#include "rcontroller.h"

#include <QSettings>
#include <QFile>
#include <QStandardPaths>
#include <QDataStream>

RController::RController() :
    m_game(nullptr)
  , m_gameClient(nullptr)
{
    m_normalDone = -100;
    m_okeyDone = -200;
    m_doubleOkeyDone = -400;
    m_directDone = -200;
}

void RController::saveGame()
{
    if(game() == nullptr)
        return;

    QFile tFile(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/game.dat");

    if(!tFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Game file does not opened";

        return;
    }

    QDataStream tDataStream(&tFile);

    tDataStream << game()->name();
    tDataStream << game()->isPaired();
    tDataStream << game()->gamers().length();

    for(int t = 0; t<game()->gamers().length(); t++)
    {
        RGamer* tGamer = (RGamer*) game()->gamers().at(t);
        tDataStream << tGamer->name();
        tDataStream << tGamer->results().length();

        for(int y = 0; y<tGamer->results().length(); y++)
        {
            RResultPart* tPart = (RResultPart*) tGamer->results().at(y);

            tDataStream << tPart->value();
            tDataStream << tPart->initialValue();
            tDataStream << tPart->deleted();
            tDataStream << tPart->changed();
        }
    }

    tFile.close();

    qDebug() << "Game written to file";
}

void RController::readGame()
{
    QFile tFile(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/game.dat");

    if(!tFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Game file does not opened";

        return;
    }

    QDataStream tDataStream(&tFile);

    QString tGameName = "";
    bool tIsPaired = false;
    int tGamersCount = 0;

    tDataStream >> tGameName;
    tDataStream >> tIsPaired;
    tDataStream >> tGamersCount;

    setGame(new RGameObject());

    game()->init(tGameName, tIsPaired);

    QList<QObject*> tList;

    for(int t = 0; t<tGamersCount; t++)
    {
        RGamer* tGamer = new RGamer();

        QString tGamerName = "";
        int tGamerResultsCount = 0;
        tDataStream >> tGamerName;
        tDataStream >> tGamerResultsCount;

        tGamer->setName(tGamerName);

        QList<QObject*> tResultList;

        for(int y = 0; y<tGamerResultsCount; y++)
        {
            int tValue = 0;
            int tInitialValue = 0;
            bool tDeleted = false;
            bool tChanged = false;

            tDataStream >> tValue;
            tDataStream >> tInitialValue;
            tDataStream >> tDeleted;
            tDataStream >> tChanged;

            RResultPart* tPart = new RResultPart(tInitialValue);
            tPart->setValue(tValue);
            tPart->setDeleted(tDeleted);
            tPart->setChanged(tChanged);

            tResultList.append(tPart);
        }

        tGamer->setResults(tResultList);

        tList.append(tGamer);
    }

    tFile.close();

    game()->setGamers(tList);
    game()->refreshResults();

    qDebug() << tGameName << tIsPaired << tGamersCount;
}

void RController::createGame(QString pGameName, bool pIsPaired, QString pGamer1, QString pGamer2, QString pGamer3, QString pGamer4)
{
    setGame(new RGameObject());

    game()->init(pGameName, pIsPaired);

    QList<QObject*> tList;
    {
        RGamer* tGamer = new RGamer();
        tGamer->setName(pGamer1);
        tList.append(tGamer);
    }

    {
        RGamer* tGamer = new RGamer();
        tGamer->setName(pGamer2);
        tList.append(tGamer);
    }

    if(pGamer3 != "")
    {
        RGamer* tGamer = new RGamer();
        tGamer->setName(pGamer3);
        tList.append(tGamer);
    }

    if(pGamer4 != "")
    {
        RGamer* tGamer = new RGamer();
        tGamer->setName(pGamer4);
        tList.append(tGamer);
    }

    game()->setGamers(tList);

    saveGame();

    game()->refreshResults();
}

void RController::saveGameSettings(int pDone, int pOkeyDone, int pDoubleOkeyDone, int pDirectDone)
{
    QSettings tSettings;

    tSettings.setValue("normalDone", pDone);
    tSettings.setValue("okeyDone", pOkeyDone);
    tSettings.setValue("doubleOkeyDone", pDoubleOkeyDone);
    tSettings.setValue("directDone", pDirectDone);

    setNormalDone(pDone);
    setOkeyDone(pOkeyDone);
    setDoubleOkeyDone(pDoubleOkeyDone);
    setDirectDone(pDirectDone);
}

void RController::refreshResults()
{
    saveGame();
    game()->refreshResults();
}

#include "rcontroller.h"

RController::RController() :
    m_game(nullptr)
  , m_gameClient(nullptr)
{

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
}

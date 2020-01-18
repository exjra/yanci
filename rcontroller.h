#ifndef RCONTROLLER_H
#define RCONTROLLER_H

#include <QObject>
#include <QSettings>

#include "rgameobject.h"
#include "rgameclient.h"

class RController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(RGameObject* game READ game WRITE setGame NOTIFY gameChanged)
    Q_PROPERTY(RGameClient* gameClient READ gameClient WRITE setGameClient NOTIFY gameClientChanged)
    Q_PROPERTY(int normalDone READ normalDone WRITE setNormalDone NOTIFY normalDoneChanged)
    Q_PROPERTY(int okeyDone READ okeyDone WRITE setOkeyDone NOTIFY okeyDoneChanged)
    Q_PROPERTY(int doubleOkeyDone READ doubleOkeyDone WRITE setDoubleOkeyDone NOTIFY doubleOkeyDoneChanged)
    Q_PROPERTY(int directDone READ directDone WRITE setDirectDone NOTIFY directDoneChanged)

public:
    RController();

    RGameObject* game() const
    {
        return m_game;
    }

    RGameClient* gameClient() const
    {
        return m_gameClient;
    }

    int normalDone() const
    {
        return m_normalDone;
    }

    int okeyDone() const
    {
        return m_okeyDone;
    }

    int doubleOkeyDone() const
    {
        return m_doubleOkeyDone;
    }

    int directDone() const
    {
        return m_directDone;
    }

public slots:
    void saveGame();
    void readGame();
    void createGame(QString pGameName, bool pIsPaired, QString pGamer1, QString pGamer2, QString pGamer3, QString pGamer4);

    void setGame(RGameObject* game)
    {
        if (m_game == game)
            return;

        m_game = game;
        emit gameChanged(m_game);
    }

    void setGameClient(RGameClient* gameClient)
    {
        if (m_gameClient == gameClient)
            return;

        m_gameClient = gameClient;
        emit gameClientChanged(m_gameClient);
    }

    void saveGameSettings(int pDone, int pOkeyDone, int pDoubleOkeyDone, int pDirectDone);

    void setNormalDone(int normalDone)
    {
        if (m_normalDone == normalDone)
            return;

        m_normalDone = normalDone;
        emit normalDoneChanged(m_normalDone);
    }

    void setOkeyDone(int okeyDone)
    {
        if (m_okeyDone == okeyDone)
            return;

        m_okeyDone = okeyDone;
        emit okeyDoneChanged(m_okeyDone);
    }

    void setDoubleOkeyDone(int doubleOkeyDone)
    {
        if (m_doubleOkeyDone == doubleOkeyDone)
            return;

        m_doubleOkeyDone = doubleOkeyDone;
        emit doubleOkeyDoneChanged(m_doubleOkeyDone);
    }

    void setDirectDone(int directDone)
    {
        if (m_directDone == directDone)
            return;

        m_directDone = directDone;
        emit directDoneChanged(m_directDone);
    }

    void refreshResults();

private:
    RGameObject* m_game;
    RGameClient* m_gameClient;

    int m_normalDone;

    int m_okeyDone;

    int m_doubleOkeyDone;

    int m_directDone;

signals:
    void gameChanged(RGameObject* game);
    void gameClientChanged(RGameClient* gameClient);
    void normalDoneChanged(int normalDone);
    void okeyDoneChanged(int okeyDone);
    void doubleOkeyDoneChanged(int doubleOkeyDone);
    void directDoneChanged(int directDone);
};

#endif // RCONTROLLER_H

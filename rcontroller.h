#ifndef RCONTROLLER_H
#define RCONTROLLER_H

#include <QObject>

#include "rgameobject.h"
#include "rgameclient.h"

class RController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(RGameObject* game READ game WRITE setGame NOTIFY gameChanged)
    Q_PROPERTY(RGameClient* gameClient READ gameClient WRITE setGameClient NOTIFY gameClientChanged)

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

public slots:
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

private:
    RGameObject* m_game;
    RGameClient* m_gameClient;

signals:
void gameChanged(RGameObject* game);
void gameClientChanged(RGameClient* gameClient);
};

#endif // RCONTROLLER_H

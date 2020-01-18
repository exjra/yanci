#ifndef RGAMEOBJECT_H
#define RGAMEOBJECT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QUdpSocket>
#include <QTimer>

#include "rgamer.h"

class RGameObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool isPaired READ isPaired WRITE setIsPaired NOTIFY isPairedChanged)
    Q_PROPERTY(QList<QObject*> gamers READ gamers WRITE setGamers NOTIFY gamersChanged)

public:
    RGameObject();
    ~RGameObject();

    void init(QString pName, bool pIsPaired);
    void addGamer(QString pName);

    QString name() const
    {
        return m_name;
    }

    bool isPaired() const
    {
        return m_isPaired;
    }

    QList<QObject*> gamers() const
    {
        return m_gamers;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }

    void setIsPaired(bool isPaired)
    {
        if (m_isPaired == isPaired)
            return;

        m_isPaired = isPaired;
        emit isPairedChanged(m_isPaired);
    }

    void setGamers(QList<QObject*> gamers)
    {
        if (m_gamers == gamers)
            return;

        m_gamers = gamers;
        emit gamersChanged(m_gamers);
    }

    void refreshResults();

private slots:
    void onNewConnection();

private:
    void prepareNetwork();
    void prepareGame();

    QTcpServer* mServer = nullptr;
    quint16 mGamePort = 1454;

    QUdpSocket* mBroadcaster;
    quint16 mBroadcastingPort = 1453;
    QTimer* mBroadcastingTimer;

    QList<QTcpSocket*> mClients;

    QString m_name;

    bool m_isPaired;

    QList<QObject*> m_gamers;

private slots:
    void whoAmI();

signals:
    void gameReady();
    void nameChanged(QString name);
    void isPairedChanged(bool isPaired);
    void gamersChanged(QList<QObject*> gamers);
};

Q_DECLARE_METATYPE(RGameObject*);

#endif // RGAMEOBJECT_H

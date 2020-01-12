#include "rgameobject.h"

#include <QDataStream>
#include <QDebug>
#include <QNetworkInterface>

RGameObject::RGameObject() :
    mBroadcaster(nullptr)
  , mBroadcastingTimer(nullptr)
  , mServer(nullptr)
{
    qRegisterMetaType<RGameObject*>("RGameObject*");

    setName("");
    setIsPaired(false);
}

RGameObject::~RGameObject()
{
    if(mBroadcaster)
    {
        mBroadcaster->close();

        disconnect(mBroadcaster, nullptr, nullptr, nullptr);

        mBroadcaster->deleteLater();
        mBroadcaster = NULL;
    }

    if(mBroadcastingTimer)
    {
        disconnect(mBroadcastingTimer, nullptr, nullptr, nullptr);

        mBroadcastingTimer->deleteLater();
        mBroadcastingTimer = NULL;
    }

    if(mServer)
    {
        mServer->close();

        disconnect(mServer, nullptr, nullptr, nullptr);

        mServer->deleteLater();
        mServer = NULL;
    }
}

void RGameObject::init(QString pName, bool pIsPaired)
{
    setName(pName);
    setIsPaired(pIsPaired);

    prepareNetwork();
    prepareGame();
}

void RGameObject::addGamer(QString pName)
{
    RGamer* tGamer = new RGamer();
    tGamer->setName(pName);
    gamers().append(tGamer);

    emit gamersChanged(m_gamers);
}

void RGameObject::onNewConnection()
{
    QTcpSocket* tSoc = mServer->nextPendingConnection();

    if(tSoc == nullptr)
        return;

    qDebug() << "New client connected:" << tSoc->peerAddress();
}

void RGameObject::prepareNetwork()
{
    if(mServer != nullptr)
    {
        mServer->close();

        disconnect(mServer, nullptr, nullptr, nullptr);

        mServer->deleteLater();
        mServer = nullptr;
    }


    mServer = new QTcpServer();

    connect(mServer, &QTcpServer::newConnection, this, &RGameObject::onNewConnection);

    mServer->listen(QHostAddress::Any, mGamePort);

    //broadcaster
    mBroadcaster = new QUdpSocket();

    mBroadcastingTimer = new QTimer;
    mBroadcastingTimer->setInterval(1000);
    connect(mBroadcastingTimer, &QTimer::timeout, this, &RGameObject::whoAmI);

    mBroadcastingTimer->start();
}

void RGameObject::prepareGame()
{

    emit gameReady();
}

void RGameObject::whoAmI()
{
    if(mBroadcaster == nullptr)
        return;

    QByteArray tWhoAmI;
    QDataStream tStream(&tWhoAmI, QIODevice::WriteOnly);

    unsigned char tTemp;

    //prefix
    tTemp = 14;
    tStream << tTemp;

    //server port
    tStream << mGamePort;

    //postfix
    tTemp = 53;
    tStream << tTemp;

    QList<QNetworkInterface> tIntList = QNetworkInterface::allInterfaces();

    // Interfaces iteration
    for (int i = 0; i < tIntList.size(); i++)
    {
        // Now get all IP addresses for the current interface
        QList<QNetworkAddressEntry> addrs = tIntList[i].addressEntries();

        // And for any IP address, if it is IPv4 and the interface is active, send the packet
        for (int j = 0; j < addrs.size(); j++)
            if ((addrs[j].ip().protocol() == QAbstractSocket::IPv4Protocol) && (addrs[j].broadcast().toString() != ""))
                //                bDebug << "Broadcasting, Data Len.:" <<
                //                          addrs[j].broadcast().toString() <<
                mBroadcaster->writeDatagram(tWhoAmI, tWhoAmI.length(), addrs[j].broadcast(), mBroadcastingPort);
    }
}

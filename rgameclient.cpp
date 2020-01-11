#include "rgameclient.h"

#include <QDataStream>
#include <QNetworkDatagram>

RGameClient::RGameClient() :
    mBroadcastListener(nullptr)
  , mSocket(nullptr)
{
    qRegisterMetaType<RGameClient*>("RGameClient*");
}

RGameClient::~RGameClient()
{
    if(mSocket != nullptr)
    {
        mSocket->close();

        disconnect(mSocket, nullptr, nullptr, nullptr);

        mSocket->deleteLater();
        mSocket = nullptr;
    }
}

void RGameClient::init()
{
    if(mSocket != nullptr)
    {
        mSocket->close();

        disconnect(mSocket, nullptr, nullptr, nullptr);

        mSocket->deleteLater();
        mSocket = nullptr;
    }

    if(mBroadcastListener != nullptr)
    {
        mBroadcastListener->close();

        disconnect(mBroadcastListener, nullptr, nullptr, nullptr);

        mBroadcastListener->deleteLater();
        mBroadcastListener = nullptr;
    }

    mServerConfReceived = false;
    mBroadcastData.clear();

    mBroadcastListener = new QUdpSocket();
    connect(mBroadcastListener, &QUdpSocket::readyRead, this, &RGameClient::onBroadcastDataReceived);

    mBroadcastListener->bind(QHostAddress::Any, 1453);
}

QHostAddress RGameClient::serverAddr() const
{
    return mServerAddr;
}

void RGameClient::setServerAddr(const QHostAddress &serverAddr)
{
    mServerAddr = serverAddr;
}

void RGameClient::onDataReady()
{

}

void RGameClient::onConnected()
{
    qDebug() << "the client connected to server";
}

void RGameClient::onDisconnected()
{
    qDebug() << "the client disconnected from server";
}

void RGameClient::onError(QAbstractSocket::SocketError pError)
{

}

void RGameClient::onBroadcastDataReceived()
{
    while (mBroadcastListener->hasPendingDatagrams())
    {
        QNetworkDatagram tDatagram = mBroadcastListener->receiveDatagram();

        mServerAddr = tDatagram.senderAddress();

        mBroadcastData.append(tDatagram.data());
    }

    if(mBroadcastData.length() >= 4)
    {
        if(mServerConfReceived)
            return;

        if(mBroadcastData.at(0) == 14 && mBroadcastData.at(3) == 53)
        {
            QDataStream tStream(&mBroadcastData, QIODevice::ReadOnly);

            unsigned char tBuff;

            tStream >> tBuff;
            tStream >> mServerPort;
            tStream >> tBuff;

            mBroadcastData.clear();

            mServerConfReceived = true;

            qDebug() << "Server conf received:" << mServerAddr << mServerPort;

            onServerConfReceived();
        }
    }
}

void RGameClient::onServerConfReceived()
{
    mSocket = new QTcpSocket();

    connect(mSocket, &QTcpSocket::readyRead, this, &RGameClient::onDataReady);
    connect(mSocket, &QTcpSocket::connected, this, &RGameClient::onConnected);
    connect(mSocket, &QTcpSocket::disconnected, this, &RGameClient::onDisconnected);
    connect(mSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &RGameClient::onError);

    qDebug() << "Connecting to:" << mServerAddr << mServerPort;

    mSocket->connectToHost(mServerAddr, mServerPort);
}

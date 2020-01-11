#ifndef RGAMECLIENT_H
#define RGAMECLIENT_H

#include <QHostAddress>
#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>

class RGameClient : public QObject
{
    Q_OBJECT
public:
    RGameClient();
    ~RGameClient();

    void init();

    QHostAddress serverAddr() const;
    void setServerAddr(const QHostAddress &serverAddr);

private:
    QTcpSocket* mSocket = nullptr;
    QHostAddress mServerAddr;

    QUdpSocket* mBroadcastListener;

    bool mServerConfReceived = false;
    QByteArray mBroadcastData;
    QHostAddress mServerAddress;
    quint16 mServerPort;

private slots:
    void onDataReady();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError pError);

    void onBroadcastDataReceived();

    void onServerConfReceived();
};

Q_DECLARE_METATYPE(RGameClient*);

#endif // RGAMECLIENT_H

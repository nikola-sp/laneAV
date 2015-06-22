#include "serverAV.h"

ServerAV::ServerAV(quint16 portIn, QObject *parent) : QObject(parent)
{
    socketIn = 0;
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), SLOT(newConnection()));
    server->listen(QHostAddress::Any, portIn);
}

void ServerAV::newConnection()
{
    socketIn = server->nextPendingConnection();
    connect(socketIn, SIGNAL(disconnected()), socketIn, SLOT(deleteLater()));
    connect(socketIn, SIGNAL(destroyed()), SLOT(zeropointer()));
}

void ServerAV::zeropointer()
{
    socketIn = 0;
}

void ServerAV::writeData(QByteArray dataIn)
{
    if (socketIn)
        socketIn->write(dataIn);
}

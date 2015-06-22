#include "clientAV.h"

ClientAV::ClientAV(QHostAddress host, quint16 portOut, QObject *parent) : QObject(parent)
{
    socketOut = new QTcpSocket(this);
    socketOut->connectToHost(host, portOut);
    connect(socketOut, SIGNAL(readyRead()), SLOT(readyRead()));
}

void ClientAV::readyRead()
{
    QByteArray dataOut;

    while (socketOut->bytesAvailable() > 0)
        dataOut.append(socketOut->readAll());

    output.writeData(dataOut);
}

void ClientAV::volume(int n){
    output.volume(n);
}


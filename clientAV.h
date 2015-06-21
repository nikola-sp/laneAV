#ifndef CLIENT_H
#define CLIENT_H

#include <QtCore>
#include <QtNetwork>
#include "audiooutput.h"

class ClientAV : public QObject
{
    Q_OBJECT
public:
    explicit ClientAV(QHostAddress host, quint16 portOut, QObject *parent = 0);

signals:

public slots:

private slots:
    void readyRead();

private:
    QTcpSocket *socketOut;
    AudioOutput output;
};

#endif // CLIENT_H


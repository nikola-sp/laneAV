#ifndef SERVERAV_H
#define SERVERAV_H

#include <QtCore>
#include <QtNetwork>

class ServerAV : public QObject
{
    Q_OBJECT
public:
    explicit ServerAV(quint16 portIn, QObject *parent = 0);

signals:

public slots:
    void writeData(QByteArray dataIn);

private slots:
    void newConnection();
    void zeropointer();

private:
    QTcpServer *server;
    QTcpSocket *socketIn;
};

#endif // SERVER_H

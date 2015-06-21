#ifndef LANEAV_H
#define LANEAV_H

#include <QMainWindow>
#include <QaudioInput>
#include <QAudioOutput>
#include <QtNetwork>
#include <QMessageBox>
#include "audioinput.h"
#include "serverAV.h"
#include "clientAV.h"

namespace Ui {
class laneAV;
}

class laneAV : public QMainWindow
{
    Q_OBJECT

public:
    explicit laneAV(QWidget *parent = 0);
    void setDevIn();
    ~laneAV();

private slots:

    void on_micOn_clicked();

private:
    Ui::laneAV *ui;
    bool mic_on=true;
    AudioInput *input;
    ServerAV *server;
    ClientAV *client;
    QHostAddress partnerIp = QHostAddress("192.168.0.101");

};

#endif // LANEAV_H

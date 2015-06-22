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
#include "videoinput.h"

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

    void on_SoundOn_clicked();

    void on_volSlider_valueChanged(int value);

    void on_cbCamDev_currentTextChanged(const QString &arg1);

private:
    Ui::laneAV *ui;
    bool mic_on=true;
    bool out_on=true;
    bool vid_on=true;
    AudioInput *input;
    ServerAV *server;
    ClientAV *client;
    videoinput *videoIn;
    QHostAddress partnerIp = QHostAddress("192.168.0.102");
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;

};

#endif // LANEAV_H

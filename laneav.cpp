#include "laneav.h"
#include "ui_laneav.h"


laneAV::laneAV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::laneAV)
{
    ui->setupUi(this);
    setDevIn();

    ui->micOn->setFlat(true);
    ui->SoundOn->setFlat(true);
    ui->ImageOn->setFlat(true);

    QAudioDeviceInfo devinfo = ui->cbInDev->itemData(ui->cbInDev->currentIndex()).value<QAudioDeviceInfo>();
    input = new AudioInput(devinfo, this);

    quint16 portIn =55555;
    server = new ServerAV(portIn, this);
    connect(input, SIGNAL(dataReady(QByteArray)), server, SLOT(writeData(QByteArray)));

    ui->cbInDev->setEnabled(false);

    quint16 portOut = portIn;
    client = new ClientAV(partnerIp, portOut, this);

    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras()){
        qDebug()<<cameraInfo.description();
        qDebug()<<ui->cbCamDev->currentText();
        if(cameraInfo.description()==ui->cbCamDev->currentText()){
               // videoIn=new videoinput(cameraInfo, this);
            camera = new QCamera(cameraInfo, parent);

            viewfinder = new QCameraViewfinder();
            viewfinder->setParent(ui->myvid);
            viewfinder->show();

            camera->setViewfinder(viewfinder);

            imageCapture = new QCameraImageCapture(camera);

            camera->setCaptureMode(QCamera::CaptureStillImage);
            camera->start();
                break;
        }
    }

}

void laneAV::setDevIn()
{
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    if (devices.isEmpty()) QMessageBox::warning(this, "Error", "No audio input device found!");
    for(int i = 0; i < devices.size(); ++i)
        ui->cbInDev->addItem(devices.at(i).deviceName(), qVariantFromValue(devices.at(i)));

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if (cameras.isEmpty()) QMessageBox::warning(this, "Error", "No video input device found!");
    for(int i = 0; i < cameras.size(); ++i)
        ui->cbCamDev->addItem(cameras.at(i).description());

}


laneAV::~laneAV()
{
    delete ui;
}



void laneAV::on_micOn_clicked()
{
    if(mic_on){
        mic_on=false;
        ui->micOn->setFlat(false);
        input->mute(true);
    }
    else{
        mic_on=true;
        ui->micOn->setFlat(true);
        input->mute(false);
    }
}

void laneAV::on_SoundOn_clicked()
{
    if(out_on){
        out_on=false;
        ui->SoundOn->setFlat(false);
        client->volume(0);
    }
    else{
        out_on=true;
        ui->SoundOn->setFlat(true);
        client->volume(50);
    }

}

void laneAV::on_volSlider_valueChanged(int value)
{
    client->volume(value);
}

void laneAV::on_cbCamDev_currentTextChanged(const QString &arg1)
{
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras()){
        qDebug()<<cameraInfo.description();
        qDebug()<<ui->cbCamDev->currentText();
        if(cameraInfo.description()==ui->cbCamDev->currentText()){
                //videoIn=new videoinput(cameraInfo, this);
            camera = new QCamera(cameraInfo);

            viewfinder = new QCameraViewfinder();
            viewfinder->show();

            camera->setViewfinder(viewfinder);
            viewfinder->setParent(ui->myvid);

            imageCapture = new QCameraImageCapture(camera);

            camera->setCaptureMode(QCamera::CaptureStillImage);
            camera->start();
                break;
        }
    }
  //  ui->viewfinder->children().append(viewfinder);

}

#include "laneav.h"
#include "ui_laneav.h"


laneAV::laneAV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::laneAV)
{
    ui->setupUi(this);
    setDevIn();

    QAudioDeviceInfo devinfo = ui->cbInDev->itemData(ui->cbInDev->currentIndex()).value<QAudioDeviceInfo>();
    input = new AudioInput(devinfo, this);

    quint16 portIn =55555;
    server = new ServerAV(portIn, this);
    connect(input, SIGNAL(dataReady(QByteArray)), server, SLOT(writeData(QByteArray)));

    ui->cbInDev->setEnabled(false);

    quint16 portOut = portIn;
    client = new ClientAV(partnerIp, portOut, this);
}

void laneAV::setDevIn()
{
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    if (devices.isEmpty()) QMessageBox::warning(this, "Error", "No input device found!");
    for(int i = 0; i < devices.size(); ++i)
        ui->cbInDev->addItem(devices.at(i).deviceName(), qVariantFromValue(devices.at(i)));
}



laneAV::~laneAV()
{
    delete ui;
}



void laneAV::on_micOn_clicked()
{
    if(mic_on){
        mic_on=false;


    }
}

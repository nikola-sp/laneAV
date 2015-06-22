#include "audioinput.h"
#include <QDebug>

AudioInput::AudioInput(QAudioDeviceInfo devinfo, QObject *parent) : QObject(parent)
{
    QAudioFormat format;
    format.setChannelCount(1);
    format.setSampleRate(8000);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    audioIn = new QAudioInput(devinfo, format, this);
    audioIn->setBufferSize(8192);

    deviceIn = audioIn->start();
    connect(deviceIn, SIGNAL(readyRead()), SLOT(readyRead()));
}

void AudioInput::readyRead()
{
    QByteArray dataIn;
    qint64 len = audioIn->bytesReady();
    if (len > 0)
    {
        dataIn.resize(len);
        deviceIn->read(dataIn.data(), len);
    }
    emit dataReady(dataIn);
}

void AudioInput::mute(bool v){
    if (v)
        deviceIn->blockSignals(true);
    else{
        deviceIn->blockSignals(false);
    }

}


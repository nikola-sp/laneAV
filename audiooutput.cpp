#include "audiooutput.h"

AudioOutput::AudioOutput(QObject *parent) : QObject(parent)
{
    QAudioFormat format;
    format.setChannelCount(1);
    format.setSampleRate(8000);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    audioOut = new QAudioOutput(format, this);
    audioOut->setBufferSize(8192);

    deviceOut = audioOut->start();
}

void AudioOutput::writeData(QByteArray dataOut)
{
    deviceOut->write(dataOut.data(), dataOut.size());
}

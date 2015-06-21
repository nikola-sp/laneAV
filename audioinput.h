#ifndef AUDIOINPUT_H
#define AUDIOINPUT_H

#include <QtCore>
#include <QtMultimedia>
#include "serverAV.h"

class AudioInput : public QObject
{
    Q_OBJECT
public:
    explicit AudioInput(QAudioDeviceInfo devinfo, QObject *parent = 0);

signals:
    void dataReady(QByteArray dataIn);

public slots:

private slots:
    void readyRead();

private:
    QAudioInput *audioIn;
    QIODevice *deviceIn;
};

#endif // AUDIOINPUT_H

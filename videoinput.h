#ifndef VIDEOINPUT_H
#define VIDEOINPUT_H

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>


class videoinput
{
public:
    explicit videoinput(QCameraInfo caminfo, QObject *parent = 0);
    ~videoinput();
    //QCameraViewfinder *viewfinder;
private:

    QCamera *camera;
    QCameraImageCapture *imageCapture;
};

#endif // VIDEOINPUT_H

#-------------------------------------------------
#
# Project created by QtCreator 2015-06-21T15:18:40
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laneAV
TEMPLATE = app


SOURCES += main.cpp\
        laneav.cpp \
    serverAV.cpp \
    audioinput.cpp \
    audiooutput.cpp \
    ClientAV.cpp \
    videoinput.cpp

HEADERS  += laneav.h \
    serverAV.h \
    audioinput.h \
    audiooutput.h \
    clientAV.h \
    videoinput.h

FORMS    += laneav.ui

#include "laneav.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    laneAV w;
    w.show();

    return a.exec();
}

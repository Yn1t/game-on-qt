#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.setGeometry(0, 0, 1920, 1080);
    w.showFullScreen();
    return a.exec();
}

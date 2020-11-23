#include <QApplication>
#include <iostream>
#include <QObject>

#include "dialog.hh"
#include "mainwindow.hh"
#include "gameengine.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    gameengine p;

    return a.exec();

}

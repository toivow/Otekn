#include <QApplication>
#include <iostream>
#include <QObject>

#include "dialog.hh"
#include "mainwindow.hh"
#include "creategame.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    Dialog d;

    MainWindow w;

    QObject::connect(&d, SIGNAL(accepted()), &w, SLOT(show()));
    QObject::connect(&d, SIGNAL(map_choice(QImage)), &w, SLOT(init_window(QImage)));
    d.show();

    return a.exec();

}

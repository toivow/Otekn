#include <QApplication>
#include <iostream>

#include "mainwindow.hh"
#include "creategame.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    MainWindow window_;


    window_.show();

    return a.exec();

    //creategame game;
    //game.show_board();
}

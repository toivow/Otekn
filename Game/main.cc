#include <QApplication>
#include <iostream>

#include "creategame.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    creategame game;
    game.show_board();
}

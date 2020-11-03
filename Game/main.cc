#include <QApplication>
#include <iostream>

#include "creategame.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    creategame lauta;
    lauta.show_board();

    return a.exec();
}

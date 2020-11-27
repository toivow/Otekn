#include <QApplication>
#include <iostream>
#include <QObject>

#include "Window/dialog.hh"
#include "Engine/gameengine.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    gameengine p;
    if ( !p.execDialog() )
    {
        return 0;
    }
    return a.exec();
}

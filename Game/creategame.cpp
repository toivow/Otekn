#include "creategame.hh"

creategame::creategame()
{
}

creategame::~creategame()
{
}

void creategame::show_board()
{
    pikkukuva_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    isokuva_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    Dialog d;

    startorexit_ = d.exec();


    if (startorexit_)
    {
        qDebug("Started program.");
        ikkuna_.setPicture(pikkukuva_);

        ikkuna_.show();
    } else if (!startorexit_)
    {
        qDebug("Exited dialog successfully.");
        return;

    } else
    {
        qDebug("This shit ain supposed to happen");
    }
}

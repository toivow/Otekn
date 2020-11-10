#include "creategame.hh"


creategame::creategame()
{
}

creategame::~creategame()
{
}

void creategame::show_board()
{
    Dialog d;

    startorexit_ = d.exec();

    if (startorexit_)
    {
        qDebug("Started program.");
        window_.setPicture(background_);

        window_.show();
    } else if (!startorexit_)
    {
        qDebug("Exited dialog successfully.");
        return;

    } else
    {
        qDebug("This shit ain supposed to happen dawg");
    }
}

void creategame::load_map(QImage map_name_)
{
    small_img_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    big_img_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


}


#include "creategame.hh"

creategame::creategame()

{
}

void creategame::show_board()
{
    pikkukuva_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    isokuva_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    ikkuna_.setPicture(pikkukuva_);

    ikkuna_.show();
}

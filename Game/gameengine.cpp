#include "gameengine.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"

gameengine::gameengine(QObject* parent) :
    QObject(parent)
{
    basicbackground_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    bigbackground_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


    /*
    Dialog d;
    startorexit_ = d.exec();

    if (startorexit_)
    {
        //window_.setPicture(background_);
        //window_.show();
        qDebug("Started program.");

    } else if (!startorexit_)
    {
        qDebug("Exited dialog successfully.");
        return;

    } else
    {
        qDebug("This shit ain supposed to happen dawg");
    }
    */


    StudentSide::creategame temp;
    city_ = temp.createGame();
    city_->setBackground(basicbackground_, bigbackground_);


    l_.fileConfig();
    l_.setTime(14, 00);
    l_.takeCity(city_);
    l_.finalizeGameStart();

}

gameengine::~gameengine()
{
}

void gameengine::show_board()
{
}

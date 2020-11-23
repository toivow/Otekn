#include "gameengine.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"

gameengine::gameengine(QObject* parent) :
    QObject(parent)
{

    Dialog d;
    connect(&d, SIGNAL(map_choice(QImage)), this, SLOT(load_map(QImage)));
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

    qDebug("En tiiä miksei tää löydä tätä funktioo");

    temp = StudentSide::creategame();

    city_ = temp.createGame();
    l_.takeCity(city_);
    l_.fileConfig();

    l_.setTime(14, 00);
    l_.finalizeGameStart();

    window_.show();

}

gameengine::~gameengine()
{
}

void gameengine::show_board()
{

}

void gameengine::load_map(QImage map_name_)
{
    background_ = map_name_;
    window_.setPicture(background_);
}


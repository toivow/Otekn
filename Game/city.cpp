#include "city.hh"
#include <QImage>


namespace StudentSide
{

city::city() :
    window_(new CourseSide::SimpleMainWindow)
{ 
}

city::~city()
{
}

void city::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    window_.setPicture(basicbackground);
}

void city::setClock(QTime clock)
{
    aika_.setHMS(clock.hour(), clock.minute(), clock.second());
}

void city::addStop(std::shared_ptr<IStop> stop)
{
    stops_.push_back(stop);
}

void city::startGame()
{
    aika_.start();
    window_.show();
}

void city::addActor(std::shared_ptr<IActor> newactor)
{
    actors_.push_back(newactor);
}

void city::removeActor(std::shared_ptr<IActor> actor)
{
    actors_.remove(actor);
    actorRemoved(actor);
}

void city::actorRemoved(std::shared_ptr<IActor> actor)
{
    actor->isRemoved();
}

bool city::findActor(std::shared_ptr<IActor> actor) const
{
    if (std::find(actors_.begin(), actors_.end(), actor) != actors_.end())
    {
        qDebug("Löytyi actori");
        return true;
    }
    else if (std::find(actors_.begin(), actors_.end(), actor) == actors_.end())
    {
        qDebug("Ei löytynyt actoria");
    }
    else
    {
        qDebug("Exception, ei pitäisi tapahtua");
    }
    return false;
}

void city::actorMoved(std::shared_ptr<IActor> actor)
{
    // Mitä vittua tänne pitää muka tehdä
    // vitun pellet
}

std::vector<std::shared_ptr<IActor> > city::getNearbyActors(Location loc) const
{
    std::vector<std::shared_ptr<IActor>> to_return;
    for (auto actor : actors_)
    {
        if (actor->giveLocation().isClose(loc) == true)
        {
            to_return.push_back(actor);
        }
    }
    return to_return;
}

bool city::isGameOver() const
{
    if (false)
    {
        qDebug("Minuutti kulunut, peli loppuu");
        return true;
    }

    return false;
}

}


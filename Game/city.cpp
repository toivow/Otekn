#include "city.hh"
#include <QImage>
#include <iostream>

namespace StudentSide
{

city::city()
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
    int X = stop->getLocation().giveX();
    int Y = 500 - stop->getLocation().giveY();

    window_.addStop(X, Y, 122, stop);
    stops_.push_back(stop);
    //qDebug("Spawnattiin stop");
}

void city::startGame()
{
    qDebug("Aloitetaan peli");
    aika_.start();
    window_.show();
}

void city::addActor(std::shared_ptr<IActor> newactor)
{
    int Y = 500 - newactor->giveLocation().giveY();
    int X = newactor->giveLocation().giveX();

    std::shared_ptr<CourseSide::Nysse> newbus = std::dynamic_pointer_cast <CourseSide::Nysse>(newactor);
    std::shared_ptr<CourseSide::Passenger> newpass = std::dynamic_pointer_cast<CourseSide::Passenger> (newactor);

    if (newpass == nullptr)
    {
        window_.addActor(X, Y, 1, newactor);
        buses_.push_back(newbus);
    }
    else if (newbus == nullptr)
    {
        window_.addActor(X, Y, 255, newactor);
        passengers_.push_back(newpass);
    }
    else
    {
        qDebug("Lisättävä actor ei ole bussi eikä passenger");
    }
}

void city::removeActor(std::shared_ptr<IActor> actor)
{

    std::shared_ptr<CourseSide::Nysse> removebus = std::dynamic_pointer_cast <CourseSide::Nysse>(actor);
    std::shared_ptr<CourseSide::Passenger> removepass = std::dynamic_pointer_cast<CourseSide::Passenger> (actor);


    buses_.remove(removebus);
    passengers_.remove(removepass);

    actorRemoved(actor);
}

void city::actorRemoved(std::shared_ptr<IActor> actor)
{
    actor->isRemoved();
}

bool city::findActor(std::shared_ptr<IActor> actor) const
{
    if (std::find(buses_.begin(), buses_.end(), actor) != buses_.end())
    {
        qDebug("Löytyi actori busseista");
        return true;
    }
    else if (std::find(passengers_.begin(), passengers_.end(), actor) != passengers_.end())
    {
        qDebug("Löytyi actori passengereistä");
        return true;
    }

    else if ( (std::find(passengers_.begin(), passengers_.end(), actor) == passengers_.end())
             || (std::find(buses_.begin(), buses_.end(), actor) == buses_.end()) )
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
    window_.move_objects(actor);
}

std::vector<std::shared_ptr<IActor> > city::getNearbyActors(Location loc) const
{
    std::vector<std::shared_ptr<IActor>> to_return;
    for (auto passenger: passengers_)
    {
        if (passenger->giveLocation().isClose(loc) == true)
        {
            to_return.push_back(passenger);
        }
    }

    for (auto bus : buses_)
    {
        if (bus->giveLocation().isClose(loc) == true)
        {
            to_return.push_back(bus);
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


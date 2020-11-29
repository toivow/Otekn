#include "../Engine/city.hh"
#include <QImage>
#include <iostream>

namespace StudentSide
{

city::city() :
    stats_(new statistics()),
    time_(new QTime()),
    end_time_(new QTime()),
    window_(new MainWindow(stats_)),
    enable_end_time_(false)
{
}

city::~city()
{
    delete stats_;
}

void city::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    window_->setPicture(basicbackground);
    //used to silence warning about unused parameter
    (void)bigbackground;
}

void city::setClock(QTime clock)
{
    //sets time for the game
    time_->setHMS(clock.hour(), clock.minute(), clock.second());
    window_->set_time(clock);
}

void city::addStop(std::shared_ptr<IStop> stop)
{
    int X = stop->getLocation().giveX() - 5;
    int Y = 500 - stop->getLocation().giveY() - 5;

    window_->addStop(X, Y, 122, stop);
    stops_.push_back(stop);
    //qDebug("Spawnattiin stop");
}

void city::startGame()
{
    qDebug("Aloitetaan peli");

    window_->spawnDestroyer(250, 250);
    window_->updateBusAmount();
    window_->updatePassAmount();
    window_->updatePoints();
    window_->show();
}

void city::addActor(std::shared_ptr<IActor> newactor)
{
    int Y = 500 - newactor->giveLocation().giveY()-5;
    int X = newactor->giveLocation().giveX()-5;
    std::shared_ptr<CourseSide::Nysse> newbus = std::dynamic_pointer_cast <CourseSide::Nysse>(newactor);
    std::shared_ptr<CourseSide::Passenger> newpass = std::dynamic_pointer_cast<CourseSide::Passenger> (newactor);

    //If tree for checking whether pointer points to a bus or passenger
    if (newpass == nullptr)
    {
        window_->addBus(X, Y, newbus);
        buses_.push_back(newbus);
        stats_->addBus(1);
    }
    else if (newbus == nullptr)
    {
        window_->addPass(X, Y, 255, newpass);
        passengers_.push_back(newpass);
        if ( (5 < Y && Y < 495) &&  (5 < X && X < 495))
            stats_->addPass(1);
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

    //If tree for checking whether pointer points to a bus or passenger
    if (removepass == nullptr)
    {
        buses_.remove(removebus);
        stats_->addBus(-1);
    }

    else if (removebus == nullptr)
    {
        passengers_.remove(removepass);
        stats_->addPass(-1);

        //Used to randomly spawn bananas on map on passenger removes.
        int rand_numb = rand() % 50;
        if (rand_numb == 1)
        {
            window_->spawnBanana();
            qDebug("Spawned a banana!");
        }

    }


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
        //qDebug("Löytyi actori busseista");
        return true;
    }
    else if (std::find(passengers_.begin(), passengers_.end(), actor) != passengers_.end())
    {
        //qDebug("Löytyi actori passengereistä");
        return true;
    }

    else if ( (std::find(passengers_.begin(), passengers_.end(), actor) == passengers_.end())
             || (std::find(buses_.begin(), buses_.end(), actor) == buses_.end()) )
    {
        //qDebug("Ei löytynyt actoria");
    }
    else
    {
        qDebug("Exception, ei pitäisi tapahtua");
    }
    return false;
}

void city::actorMoved(std::shared_ptr<IActor> actor)
{
    window_->moveObjects(actor);
}

std::vector<std::shared_ptr<IActor> > city::getNearbyActors(Location loc) const
{
    //Adds passenger to a vector if they are close to given location.
    std::vector<std::shared_ptr<IActor>> to_return;
    for (auto passenger: passengers_)
    {
        if (passenger->giveLocation().isClose(loc) == true)
        {
            to_return.push_back(passenger);
        }
    }

    //Adds busses to a vector if they are close to given location.
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
    if ( !( time_->operator<(*end_time_)) && enable_end_time_)
    {
        qDebug("Game ends");

        window_->setEnabled(false);
        window_->show_end_dialog();
        window_->close();

        return true;
    }

    return false;
}

void city::set_game_duration(int time, QTime* clock)
{
    int min = clock->minute();
    int hr = clock->hour();

    if (time == 0) {
        enable_end_time_ = false;
        window_->disable_end_time();
    }
    else
    {
        int addSecs = time*60;
        end_time_->setHMS(hr, min, 0);
        *end_time_ = end_time_->addSecs(addSecs);
        window_->show_end_time(end_time_);
        enable_end_time_ = true;
    }

}

}


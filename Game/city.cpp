#include "city.hh"
#include <QImage>
#include <QTime>


namespace StudentSide
{

city::city()
{
}

city::~city()
{
}

void city::setBackground(QImage& basicbackground, QImage& bigbackground)
{
}

void city::setClock(QTime clock){}

void city::addStop(std::shared_ptr<IStop> stop){}

void city::startGame(){}

void city::addActor(std::shared_ptr<IActor> newactor){}

void city::removeActor(std::shared_ptr<IActor> actor){}

void city::actorRemoved(std::shared_ptr<IActor> actor){}

bool city::findActor(std::shared_ptr<IActor> actor) const{
    return 1;
}

void city::actorMoved(std::shared_ptr<IActor> actor){}

std::vector<std::shared_ptr<IActor>> city::getNearbyActors(Location loc) const{}

bool city::isGameOver() const
{
    return 0;
}
}


#include "statistics.hh"
#include <iostream>
#include <list>

namespace StudentSide {


statistics::statistics() :
    passamount_(0),
    busamount_(0),
    points_(0)
{
}

statistics::~statistics(){}

void statistics::updatePoints(int amount)
{
    points_ = amount + points_;
}

int statistics::returnPoints()
{
    return points_;
}


int statistics::busAmount()
{
    return busamount_;
}

int statistics::passAmount()
{
    return passamount_;
}

void statistics::addPass(int amount)
{
    passamount_ += amount;
}

void statistics::addBus(int amount)
{
   busamount_ += amount;
}

}

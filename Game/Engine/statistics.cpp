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

void statistics::update_points(int amount)
{
    points_ = amount + points_;
}

int statistics::return_points()
{
    return points_;
}


int statistics::bus_amount()
{
    return busamount_;
}

int statistics::pass_amount()
{
    return passamount_;
}

void statistics::add_pass(int amount)
{
    passamount_ += amount;
}

void statistics::add_bus(int amount)
{
   busamount_ += amount;
}

}

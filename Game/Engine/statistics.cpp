#include "statistics.hh"
#include <iostream>
#include <list>

namespace StudentSide {


statistics::statistics(){}

statistics::~statistics(){}

int statistics::update_points(int amount)
{
    points_ = points_ + amount;
    return points_;
}

int statistics::current_busses(std::list<std::shared_ptr<CourseSide::Nysse>> nysset)
{
    int list_lenght = nysset.size();
    return list_lenght;
}

int statistics::current_passengers(std::list<std::shared_ptr<CourseSide::Passenger>> passengers)
{
    int list_lenght = passengers.size();
    return list_lenght;
}

}

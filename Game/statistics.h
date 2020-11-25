#ifndef STATISTICS_H
#define STATISTICS_H

#include "../CourseLib/interfaces/istatistics.hh"
#include "../CourseLib/actors/passenger.hh"
#include "../CourseLib/actors/nysse.hh"
#include <iostream>
#include <memory>

namespace StudentSide {



class statistics
{

public:
    statistics();
   ~statistics();
    int update_points(int amount);
    int current_busses(std::list <std::shared_ptr<CourseSide::Nysse>> nysset);
    int current_passengers(std::list <std::shared_ptr<CourseSide::Passenger>> passengers);

private:

    int points_;

};
}

#endif // STATISTICS_H

#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "../../Course/CourseLib/actors/passenger.hh"
#include "../../Course/CourseLib/actors/nysse.hh"
#include <iostream>
#include <memory>

namespace StudentSide {

class statistics
{

public:
    statistics();
   ~statistics();

    void update_points(int amount);

    int return_points();

    int bus_amount();

    int pass_amount();

    void add_pass(int amount);
    void add_bus(int amount);

private:
    int passamount_;
    int busamount_;

    int points_;

};
}

#endif // STATISTICS_HH

#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "../../Course/CourseLib/actors/passenger.hh"
#include "../../Course/CourseLib/actors/nysse.hh"
#include <iostream>
#include <memory>

/**
  * @file
  * @brief Class used for storing and updating different statistics happening in city.
  */

namespace StudentSide {

class statistics
{

public:
    statistics();
   ~statistics();
    /**
     * @brief updatePoints updates users scored points.
     * @pre -
     * @param amount is the amount user has scored to be added to the previous score.
     * @return -
     * @post Exception guaranteee: Nothrow
     */
    void updatePoints(int amount);

    /**
     * @brief returnPoints returns users score.
     * @pre -
     * @return user's score.
     * @post Exception guaranteee: Nothrow
     */
    int returnPoints();

    /**
     * @brief busAmount returns amount of busses in traffic.
     * @pre -
     * @return Amount of busses in traffic.
     * @post Exception guaranteee: Nothrow
     */
    int busAmount();

    /**
     * @brief passAmount returns amount of passengers in traffic.
     * @pre -
     * @return Amount of passengers in traffic.
     * @post Exception guaranteee: Nothrow
     */
    int passAmount();

    /**
     * @brief addPass adds new passengers to the total amount.
     * @param amount is the amount of passengers added.
     * @return -
     * @post Exception guaranteee: Nothrow
     */
    void addPass(int amount);

    /**
     * @brief addBus adds new busses to the total amount.
     * @param amount is the amount of busses added.
     * @return -
     * @post Exception guaranteee: Nothrow
     */
    void addBus(int amount);

private:
    int passamount_;
    int busamount_;

    int points_;

};
}

#endif // STATISTICS_HH

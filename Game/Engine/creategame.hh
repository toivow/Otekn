#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include "city.hh"

/**
 * @file
 * @brief class defines a function that creates the city.
 */


namespace StudentSide
{

class creategame
{


public:
    creategame();
    ~creategame();
    /**
     * @brief createGame creates the games city and return pointer to it.
     * @pre -
     * @return pointer to the created city.
     * @post Exception guaranteee: basic.
     */
    std::shared_ptr<StudentSide::city> createGame();

private:
    std::shared_ptr<StudentSide::city> city_;

};
}

#endif // CREATEGAME_HH

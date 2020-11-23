#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include "city.hh"


namespace StudentSide
{

class creategame
{
public:
    creategame();
    ~creategame();

    std::shared_ptr<Interface::ICity> createGame();

private:
    std::shared_ptr<StudentSide::city> city_;

};
}

#endif // CREATEGAME_HH

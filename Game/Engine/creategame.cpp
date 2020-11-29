#include "creategame.hh"
#include "city.hh"

#include <memory>

namespace StudentSide {

creategame::creategame()
{
}

creategame::~creategame()
{
}


std::shared_ptr<StudentSide::city> creategame::createGame()
{
    return std::make_shared<StudentSide::city>();
}

}

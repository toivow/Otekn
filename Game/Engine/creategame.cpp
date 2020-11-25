#include "../Engine/creategame.hh"
#include "../Engine/city.hh"

#include <memory>

namespace StudentSide {

creategame::creategame()
{
}

creategame::~creategame()
{
}


std::shared_ptr<Interface::ICity> creategame::createGame()
{
    return std::make_shared<StudentSide::city>();
}

}

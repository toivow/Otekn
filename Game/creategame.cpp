#include "../CourseLib/creategame.hh"
#include "city.hh"

#include <memory>

std::shared_ptr<Interface::ICity> createGame()
{
    return std::make_shared<StudentSide::city>();
}

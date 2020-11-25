#include "destroyer_logic.hh"

namespace StudentSide
{

destroyer_logic::destroyer_logic(int x, int y)
{
    location_.setXY(x, y);
}

destroyer_logic::~destroyer_logic()
{
}

Interface::Location destroyer_logic::giveLocation() const
{
    return location_;
}

void destroyer_logic::move(Interface::Location loc)
{
    location_ = loc;
}

}

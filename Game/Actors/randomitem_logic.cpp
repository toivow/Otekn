#include "randomitem_logic.hh"

namespace StudentSide {


randomitem_logic::randomitem_logic(int x, int y) :
    removed_(false),
    reward_(rand() % 15 + 5)

{
    location_.setXY(x, y);
}

randomitem_logic::~randomitem_logic()
{
}

Interface::Location randomitem_logic::giveLocation() const
{
    return location_;
}

void randomitem_logic::move(Interface::Location loc)
{
    location_ = loc;
}

bool randomitem_logic::isRemoved() const
{
    return removed_;
}

void randomitem_logic::remove()
{
    removed_ = true;
}

int randomitem_logic::return_reward()
{
    return reward_;
}

}

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
    int X = loc.giveX();
    int Y = loc.giveY();
    if (X >= 502 )
    {
        location_.setXY(-2,Y);
    }
    else if (X<=-2)
    {
         location_.setXY(502,Y);

    }
    else if ( Y>= 502)
    {
        location_.setXY(X,-2);
    }
    else if (Y <= -2 )
    {
        location_.setXY(X, 502);
    }
    else
    {
    location_ = loc;
    }
}

bool destroyer_logic::isRemoved() const
{
    return removed_;
}

void destroyer_logic::remove()
{
    removed_ = true;
}
}

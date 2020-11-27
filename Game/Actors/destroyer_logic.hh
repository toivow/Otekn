#ifndef DESTROYER_LOGIC_HH
#define DESTROYER_LOGIC_HH

#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/core/location.hh"
#include <QPointF>

namespace StudentSide {


class destroyer_logic : public Interface::IActor
{
public:
    destroyer_logic(int x, int y);
    ~destroyer_logic();


    Interface::Location giveLocation() const;

    void move(Interface::Location loc);

    bool isRemoved() const;

    void remove();

private:

    bool removed_;

    Interface::Location location_;

};
}

#endif // DESTROYER_LOGIC_HH

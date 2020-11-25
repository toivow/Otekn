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


    Interface::Location giveLocation() ;

    void move(Interface::Location loc);


    virtual bool isRemoved() = 0;

    virtual void remove() = 0;

private:

    int x_;
    int y_;

};
}

#endif // DESTROYER_LOGIC_HH

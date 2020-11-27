#ifndef RANDOMITEM_LOGIC_HH
#define RANDOMITEM_LOGIC_HH

#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/core/location.hh"
#include <QPointF>

namespace StudentSide {

class randomitem_logic : public Interface::IActor
{
public:
    randomitem_logic(int x, int y);
    ~randomitem_logic();

    Interface::Location giveLocation() const;

    void move(Interface::Location loc);

    bool isRemoved() const;

    void remove();

    int return_reward();

private:

    bool removed_;

    int reward_;

    Interface::Location location_;

};

}
#endif // RANDOMITEM_LOGIC_HH

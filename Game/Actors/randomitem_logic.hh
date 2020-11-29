#ifndef RANDOMITEM_LOGIC_HH
#define RANDOMITEM_LOGIC_HH

#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/core/location.hh"
#include <QPointF>

/** @file
 * @brief defines a class that handles the operations on our bonusitem actor.
 * Functions' definitons can be found in file ../CourseLib/interfaces/iactor.hh.
 */

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

    /**
     * @brief return_reward returns the randomized reward for this bonusbanana
     * @return reward_;
     */
    int return_reward();

private:

    bool removed_;

    int reward_;

    Interface::Location location_;

};

}
#endif // RANDOMITEM_LOGIC_HH

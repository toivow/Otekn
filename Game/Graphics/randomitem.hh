#ifndef RANDOM_ITEM_HH
#define RANDOM_ITEM_HH

#include "../CourseLib/graphics/simpleactoritem.hh"

/** @file
 * @brief A class used to create a randomly spawned object, function comments can be found in
 * "../CourseLib/graphics/simpleactoritem.hh"
 */

namespace StudentSide {

class randomitem : public CourseSide::SimpleActorItem
{
public:
    randomitem(int x, int y);
    ~randomitem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:

    int y_;
    int x_;
    int random_point_reward_;
    /**
     * @brief Gives a random score reward between 0 and 30.
     * @pre -
     * @return random score reward.
     * @post Exception guaranteee: Basic
     */
    int randomizeReward();

    QImage image_;
};
}

#endif // RANDOM_ITEM_HH

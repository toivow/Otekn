#ifndef RECTACTORITEM_HH
#define RECTACTORITEM_HH

#include "../CourseLib/graphics/simpleactoritem.hh"

/** @file
 * @brief A class used to paint the busses as images. Function comments can be found in
 * "../CourseLib/graphics/simpleactoritem.hh"
 */

namespace StudentSide {

const int WIDTH = 50;
const int HEIGHT = 25;

class RectActorItem : public CourseSide::SimpleActorItem
{
public:
    RectActorItem(int x, int y);
    ~RectActorItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoord(int x, int y);

private:

    int x_;
    int y_;
    QPixmap nysse_;

};
}

#endif // RECTACTORITEM_HH

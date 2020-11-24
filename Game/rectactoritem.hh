#ifndef RECTACTORITEM_HH
#define RECTACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include "../CourseLib/graphics/simpleactoritem.hh"

namespace StudentSide {


const int WIDTH = 35;
const int HEIGHT = 15;


class RectActorItem : public CourseSide::SimpleActorItem
{
public:
    RectActorItem(int x, int y);
    ~RectActorItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    int x_;
    int y_;
    QImage nysse_;

};
}

#endif // RECTACTORITEM_HH

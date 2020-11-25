#include "../Graphics/destroyer.hh"

namespace StudentSide {


destroyer::destroyer(int x, int y) :
    CourseSide::SimpleActorItem(x, y), y_(y), x_(x)
{
    setPos(mapToParent(x_, y_));
}

destroyer::~destroyer()
{

}

void destroyer::boundingPoints()
{
    top_y = y_ + HEIGHT/2;
    top_x = x_;
    left_y = y_ - HEIGHT/2;
    left_x = x_ - WIDTH/2;
    right_y = y_ - HEIGHT/2;
    right_x = x_ + WIDTH/2;
}


void destroyer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color(255, 69, 0);

    boundingPoints();

    QPointF points[3] = {
            QPointF(top_y, top_x),
            QPointF(left_y, left_x),
            QPointF(right_y, right_x)
    };

    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawPolygon(points, 3);


}


void destroyer::move(int x, int y)
{
    x_ += x;
    y_ += y;

    boundingPoints();


    setPos(x_, y_);

}
}

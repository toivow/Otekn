#include "../Graphics/destroyer.hh"

namespace StudentSide {


destroyer::destroyer(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    y_(y),
    x_(x),
    top_y(y + HEIGHT/2),
    top_x(x_),
    left_y(y - HEIGHT/2),
    left_x(x - WIDTH/2),
    right_y(y - HEIGHT/2),
    right_x(x + WIDTH/2)
{
}

destroyer::~destroyer()
{

}

QRectF destroyer::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}


void destroyer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    QColor color(255, 69, 0);

    QPointF points[3] = {
        QPointF(top_y, top_x),
        QPointF(left_y, left_x),
        QPointF(right_y, right_x)
    };


    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawPolygon(points, 3);


}
}

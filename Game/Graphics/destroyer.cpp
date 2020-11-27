#include "destroyer.hh"

namespace StudentSide {


destroyer::destroyer(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    y_(y),
    x_(x)
{
    setPos(mapToParent(x_, y_));
}

destroyer::~destroyer()
{

}

QRectF destroyer::boundingRect() const
{
    return QRectF(0, 0, 30, 30);
}


void destroyer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color(255, 69, 0);

    image_.load(":/kuvat/Kuvat/naama.png");
    QRectF bounds = boundingRect();
    QBrush brush(image_);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);

}


}

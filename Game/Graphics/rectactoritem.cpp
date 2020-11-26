#include "rectactoritem.hh"

namespace StudentSide {

RectActorItem::RectActorItem(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    x_(x),
    y_(y)
{
    setPos(mapToParent(x_, y_));
}

RectActorItem::~RectActorItem()
{

}


QRectF RectActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}


void RectActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    prepareGeometryChange();
    QRectF bounds = boundingRect();
    QColor color(0, 0, 0);

    nysse_.load(":/kuvat/Kuvat/Nysse_pixelart.png");
    QBrush brush(nysse_);
    painter->setBrush(brush);
    painter->drawRect(bounds);
}

void RectActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

}

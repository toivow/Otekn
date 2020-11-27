#include "rectactoritem.hh"

namespace StudentSide {

RectActorItem::RectActorItem(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    x_(x),
    y_(y),
    nysse_(QPixmap(":/kuvat/Kuvat/nysse.png"))
{
    setPos(mapToParent(x_, y_));
}

RectActorItem::~RectActorItem()
{
    prepareGeometryChange();
}


QRectF RectActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}


void RectActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;

    QRect bounds = QRect(-18, -5, WIDTH, HEIGHT);

    painter->setBackgroundMode(Qt::TransparentMode);
    painter->drawPixmap(bounds, nysse_);
}

void RectActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

}

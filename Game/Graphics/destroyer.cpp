#include "destroyer.hh"

namespace StudentSide {

const int DESTROYER_DIAMETER = 28;

destroyer::destroyer(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    y_(y),
    x_(x),
    pixmap_(QPixmap(":/kuvat/Kuvat/naama.png"))
{
    setPos(mapToParent(x_, y_));
}

destroyer::~destroyer()
{
    prepareGeometryChange();
}

QRectF destroyer::boundingRect() const
{
    return QRectF(0, 0, DESTROYER_DIAMETER, DESTROYER_DIAMETER);
}


void destroyer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int offset = 0 - DESTROYER_DIAMETER/4;

    (void)option;
    (void)widget;
    painter->setBackgroundMode(Qt::TransparentMode);
    painter->drawPixmap(QRect(offset, offset, DESTROYER_DIAMETER, DESTROYER_DIAMETER), pixmap_);
}


}

#include "destroyer.hh"

namespace StudentSide {


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

}

QRectF destroyer::boundingRect() const
{
    return QRectF(0, 0, 30, 30);
}


void destroyer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setBackgroundMode(Qt::TransparentMode);
    painter->drawPixmap(QRect(-7, -7, 28, 28), pixmap_);

}


}

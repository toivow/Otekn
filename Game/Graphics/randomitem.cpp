#include "randomitem.hh"

namespace StudentSide {


randomitem::randomitem(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    y_(y),
    x_(x),
    image_(QPixmap(":/kuvat/Kuvat/banana.png"))

{
    setPos(mapToParent(x_, y_));
}

randomitem::~randomitem()
{
    prepareGeometryChange();
}

QRectF randomitem::boundingRect() const
{
    return QRectF(0, 0, 30, 30);
}


void randomitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;

    QRect bounds = QRect(-7, -7, 28, 28);

    painter->setBackgroundMode(Qt::TransparentMode);
    painter->drawPixmap(bounds, image_);

}

}

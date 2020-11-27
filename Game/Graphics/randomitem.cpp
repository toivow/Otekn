#include "randomitem.hh"

namespace StudentSide {


randomitem::randomitem(int x, int y) :
    CourseSide::SimpleActorItem(x, y),
    y_(y),
    x_(x),
    random_point_reward_(randomizeReward()),
    image_(QImage(":/kuvat/Kuvat/30x30banana.png"))

{
    setPos(mapToParent(x_, y_));
}

randomitem::~randomitem()
{

}

QRectF randomitem::boundingRect() const
{
    return QRectF(0, 0, 30, 30);
}


void randomitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    prepareGeometryChange();
    QRectF bounds = boundingRect();
    QBrush brush(image_);
    painter->setBrush(brush);
    painter->drawRect(bounds);

}

int randomitem::randomizeReward()
{
    //seed used for random reward
    srand(time(NULL));
    int reward = rand()%(30-10+1)+10;
    return reward;
}
}

#ifndef DESTROYER_HH
#define DESTROYER_HH

#include "../CourseLib/graphics/simpleactoritem.hh"


const int WIDTH = 30;
const int HEIGHT = 30;

namespace StudentSide {

class destroyer : public CourseSide::SimpleActorItem
{
public:
    destroyer(int x, int y);
    ~destroyer();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:

    int y_;
    int x_;

    QImage image_;
};
}
#endif // DESTROYER_HH

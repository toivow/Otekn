#ifndef DESTROYER_HH
#define DESTROYER_HH

#include "../CourseLib/graphics/simpleactoritem.hh"


const int WIDTH = 20;
const int HEIGHT = 30;

namespace StudentSide {

class destroyer : public CourseSide::SimpleActorItem
{
public:
    destroyer(int x = 250, int y = 250);
    ~destroyer();

    void boundingPoints();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void move(int x, int y);

private:

    int y_;
    int x_;

    float top_y;
    float top_x;
    float left_y;
    float right_y;
    float left_x;
    float right_x;

};
}
#endif // DESTROYER_HH

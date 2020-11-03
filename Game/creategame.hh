#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include <QImage>
#include "../CourseLib/graphics/simplemainwindow.hh"


class creategame
{
public:
    creategame();
    void show_board();

private:

   QImage pikkukuva_;
   QImage isokuva_;
   CourseSide::SimpleMainWindow ikkuna_;
};

#endif // CREATEGAME_HH

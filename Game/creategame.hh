#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include <QImage>
#include "dialog.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"


class creategame
{
public:
    creategame();
    ~creategame();
    void show_board();

private:

   QImage pikkukuva_;
   QImage isokuva_;
   CourseSide::SimpleMainWindow ikkuna_;

   bool startorexit_;
};

#endif // CREATEGAME_HH

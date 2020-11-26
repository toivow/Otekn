#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include <QDialog>
#include <QImage>
#include <QObject>
#include <QTimer>
#include "../Window/dialog.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"
#include "../CourseLib/core/logic.hh"
#include "city.hh"
#include "creategame.hh"


class gameengine;

class gameengine : public QObject
{
    Q_OBJECT

public:

    explicit gameengine(QObject* parent=nullptr);
    virtual ~gameengine();

public slots:

    void conf_logic(int gametime, QTime* clock);

private:

   QImage map_name_;

   bool startorexit_;

   QImage basicbackground_;
   QImage bigbackground_;

   std::shared_ptr<StudentSide::city> city_;

   QTimer *timer;

   StudentSide::creategame temp;

   CourseSide::Logic* l_;

};

#endif // GAMEENGINE_HH

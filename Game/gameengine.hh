#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include <QDialog>
#include <QImage>
#include <QObject>
#include <QTimer>
#include "dialog.hh"
#include "mainwindow.hh"
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
    void show_board();

public slots:


private:

   QImage map_name_;

   bool startorexit_;

   QImage basicbackground_;
   QImage bigbackground_;

   std::shared_ptr<Interface::ICity> city_;

   QTimer *timer;

   StudentSide::creategame temp;

   CourseSide::Logic l_;

};

#endif // GAMEENGINE_HH

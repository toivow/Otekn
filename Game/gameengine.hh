#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include <QDialog>
#include <QImage>
#include <QObject>
#include "dialog.hh"
#include "mainwindow.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"
#include "../CourseLib/core/logic.hh"
#include "city.hh"
#include "../CourseLib/creategame.hh"


class gameengine;

class gameengine : public QObject
{
    Q_OBJECT

public:

    explicit gameengine(QObject* parent=nullptr);
    virtual ~gameengine();
    void show_board();

public slots:

    void load_map(QImage);

private:

   QImage map_name_;

   bool startorexit_;

   QImage background_;

   CourseSide::SimpleMainWindow window_;

   std::shared_ptr<Interface::ICity> city_;

   CourseSide::Logic l_;

};

#endif // CREATEGAME_HH

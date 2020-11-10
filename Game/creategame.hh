#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include <QDialog>
#include <QImage>
#include <QObject>
#include "dialog.hh"
#include "mainwindow.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"




class creategame
{

public:
    creategame();
    ~creategame();
    void show_board();

public slots:

    void load_map(QImage);

private:

   QImage small_img_;
   QImage big_img_;
   QImage hervanta_img_;

   QImage map_name_;

   MainWindow window_;

   bool startorexit_;

   QImage background_;

};

#endif // CREATEGAME_HH

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../CourseLib/graphics/simplemainwindow.hh"
#include <QMainWindow>
#include "dialog.hh"
#include <unordered_map>
#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/graphics/simpleactoritem.hh"
#include "../CourseLib/actors/nysse.hh"
#include "../CourseLib/core/logic.hh"


namespace Ui {
class MainWindow;
}

namespace StudentSide {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void init_dialog();

    void move_objects(std::shared_ptr<Interface::IActor> actor);

    void setPicture(QImage background);

    void addActor(int X, int Y, int type, std::shared_ptr<Interface::IActor> actor);

    void addStop(int X, int Y, int type, std::shared_ptr<Interface::IStop> stop);

private:

    Dialog d_;

    bool startorexit_;

    Ui::MainWindow *ui;

    std::unordered_map <std::shared_ptr<Interface::IActor>
    , QGraphicsItem*> actors_;

    std::unordered_map <std::shared_ptr<Interface::IStop>
    , QGraphicsItem*> stops_;


    QGraphicsScene *scene_;

};
}

#endif // MAINWINDOW_HH

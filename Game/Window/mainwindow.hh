#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../CourseLib/graphics/simplemainwindow.hh"
#include <QMainWindow>
#include "dialog.hh"
#include "../Graphics/rectactoritem.hh"
#include "../Graphics/destroyer.hh"
#include "../Actors/destroyer_logic.hh"
#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/actors/passenger.hh"
#include "../CourseLib/core/location.hh"

#include "../Engine/statistics.hh"

#include "../CourseLib/graphics/simpleactoritem.hh"
#include "../CourseLib/actors/nysse.hh"
#include "../CourseLib/core/logic.hh"
#include <memory>
#include <unordered_map>
#include <QKeyEvent>
#include <streambuf>
#include <iostream>



namespace Ui {
class MainWindow;
}

namespace StudentSide {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(statistics* stats_, QTime* clock ,QWidget *parent = nullptr);
    ~MainWindow();

    void move_objects(std::shared_ptr<Interface::IActor> actor);

    void setPicture(QImage background);

    void addActor(int X, int Y, int type, std::shared_ptr<CourseSide::Passenger> passenger);

    void addBus(int X, int Y, std::shared_ptr<CourseSide::Nysse> bus);

    void addStop(int X, int Y, int type, std::shared_ptr<Interface::IStop> stop);

    void update_bus_amount();

    void update_pass_amount();

    void update_points();

    void spawn_destroyer(int X = 0, int Y = 250);

    void keyPressEvent(QKeyEvent* event) override;

    void move_destroyer(destroyer* player, char direction);

    void check_deaths(Interface::Location player_loc_);

    void set_time(QTime clock);

private slots:

    void show_time();


private:

    Ui::MainWindow *ui;
    statistics* stats_;
    QTime* time_;

    Dialog d_;

    QTimer *timer;

    bool startorexit_;



    std::unordered_map < std::shared_ptr<CourseSide::Passenger>
    , QGraphicsItem* > actors_;

    std::unordered_map < std::shared_ptr<Interface::IStop>
    , QGraphicsItem* > stops_;

    std::unordered_map < std::shared_ptr<CourseSide::Nysse>, QGraphicsItem*> buses_;

    std::pair <destroyer_logic* ,destroyer*> player_;

    int tick_ = 10;

    QGraphicsScene *scene_;

};
}

#endif // MAINWINDOW_HH

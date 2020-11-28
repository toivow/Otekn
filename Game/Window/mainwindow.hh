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
#include "../Graphics/randomitem.hh"
#include "../Engine/statistics.hh"
#include "../CourseLib/graphics/simpleactoritem.hh"
#include "../CourseLib/actors/nysse.hh"
#include "../CourseLib/core/logic.hh"
#include "../Actors/randomitem_logic.hh"
#include <memory>
#include <unordered_map>
#include <QKeyEvent>
#include <streambuf>
#include <iostream>


/** @file
 * @brief A Qobject class used for all the operations happening on the screen during the game.
 */


namespace Ui {
class MainWindow;
}

namespace StudentSide {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(statistics* stats_, QWidget *parent = nullptr);
    ~MainWindow() override;
    /**
     * @brief moveObjects is used to change objects coordinates individually
     * @param actor is a shared pointer to the actor which coords we wish to change
     * @post Actor's coordinates are changed
     */
    void moveObjects(std::shared_ptr<Interface::IActor> actor);

    /**
     * @brief setPicture sets the background image
     * @param Qimage background is the wished background map.
     * @post Picture is set as background
     */
    void setPicture(QImage background);

    /**
     * @brief addActor adds a passenger on map
     * @param passenger is the pointer to passenger that is added to the map
     * @param X and Y are the coordinates of said passenger
     * @param type is the color of the passenger, in scale 0-255.
     * @post Passenger added on scene.
     */
    void addPass(int X, int Y, int type, std::shared_ptr<CourseSide::Passenger> passenger);

    /**
     * @brief addBus adds a bus on map
     * @param bus is a pointer to the bus that is added to the map
     * @param X and Y are the coordinates of said bus
     * @post Bus added to scene.
     */
    void addBus(int X, int Y, std::shared_ptr<CourseSide::Nysse> bus);
    /**
     * @brief addStop adds a stop on map
     * @param stop is a pointer to stop that is added to the map
     * @param X and Y are the coordinates of said stop
     * @param type is the color of the stop, in scale 0-255.
     * @post Stop added on scene.
     */
    void addStop(int X, int Y, int type, std::shared_ptr<Interface::IStop> stop);
    /**
     * @brief updateBusAmount updates bus amount to the QLDCobject.
     * @post QLDCobject updated
     */
    void updateBusAmount();
    /**
     * @brief updatePassAmount updates passenger amount to the QLDCobject.
     * @post QLDCobject updated
     */
    void updatePassAmount();
    /**
     * @brief updatePoints updates points amount to the statistics object.
     * @post points updated in statistics object.
     */
    void updatePoints();
    /**
     * @brief spawnDestroyer spawns our playble actor to map.
     * @param X and Y are coords where the destroyer is spawned
     * @post Destroyer spawned
     */
    void spawnDestroyer(int X = 0, int Y = 250);
    /**
     * @brief spawnBanana randomly spawns bananas on map
     * @post Banana added to map
     */
    void spawnBanana();
    /**
     * @brief KeyPressEvent moves spawned destroyer and checks for kills
     * @post destroyer moved
     */
    void keyPressEvent(QKeyEvent* event) override;
    /**
     * @brief checkDeaths checks if destroyer movement killed any passengers.
     * @param player_loc is the location of destroyer
     * @post Killed passengers checked
     */
    void checkDeaths(Interface::Location player_loc_);

    /**
     * @brief set_time sets the private parameter time_ to the time specified
     * in clock and starts the timer
     * @param clock is the time when the game is played
     * @post time_ is set and timer is started
     */
    void set_time(QTime clock);

    /**
     * @brief show_end_time creates a qstring from the qtime values, and sets
     * this as the value of the time label.
     * @param end_time is the time when the game is supposed to end (from city)
     * @post The value of end_time is displayed on endTimeLbl
     */
    void show_end_time(QTime* end_time);

    /**
     * @brief disable_end_time is called when the user doesn't specify a game
     * duration, hence overwriting the endTimeLbl
     * @param -
     * @post endTimeLbl reads "Time limit is disabled"
     */
    void disable_end_time();

private slots:

    /**
     * @brief show_time creates a qstring from the qtime values, and sets this
     * as the value of the time label.
     */
    void show_time();

    void on_exitButton_clicked();

private:

    /**
     * @brief calculate_passengers is called when a passenger is moved. This
     * function calculates if the passenger is moving in/out of the scene
     * and adds/removes passengers from city_ accordingly.
     * @param passenger the passenger being moved
     * @param newX the location the passenger is moving to in the x-axis
     * @param newY the location the passenger is moving to in the y-axis
     */
    void calculate_passengers(QGraphicsItem* passenger, int newX, int newY);

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
    std::unordered_map <randomitem_logic* ,randomitem*> bananas_;

    int tick_ = 10;

    QGraphicsScene *scene_;

};
}

#endif // MAINWINDOW_HH

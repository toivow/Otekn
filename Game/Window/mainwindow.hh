#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../CourseLib/graphics/simplemainwindow.hh"
#include <QMainWindow>
#include "dialog.hh"
#include "../Graphics/rectactoritem.hh"
#include "../Graphics/destroyer.hh"

#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/graphics/simpleactoritem.hh"
#include "../CourseLib/actors/nysse.hh"
#include "../CourseLib/core/logic.hh"
#include <unordered_map>
#include <QKeyEvent>


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

    void addBus(int X, int Y, std::shared_ptr<CourseSide::Nysse> bus);

    void addStop(int X, int Y, int type, std::shared_ptr<Interface::IStop> stop);

    void spawn_destroyer(int X = 0, int Y = 250);

    void keyPressEvent(QKeyEvent* event) override;

    void move_destroyer(destroyer* player, char direction);


private:

    Dialog d_;

    QTimer *timer;

    bool startorexit_;

    Ui::MainWindow *ui;

    std::unordered_map <std::shared_ptr<Interface::IActor>
    , QGraphicsItem*> actors_;

    std::unordered_map <std::shared_ptr<Interface::IStop>
    , QGraphicsItem*> stops_;

    destroyer* player_;

    int tick_ = 500;

    QGraphicsScene *scene_;

};
}

#endif // MAINWINDOW_HH

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../CourseLib/graphics/simplemainwindow.hh"
#include <QMainWindow>
#include "dialog.hh"

#include "../CourseLib/interfaces/iactor.hh"
#include "../CourseLib/graphics/simpleactoritem.hh"
#include "../CourseLib/actors/nysse.hh"
#include "../CourseLib/core/logic.hh"


namespace Ui {
class MainWindow;
}

class MainWindow : public CourseSide::SimpleMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_dialog();

public slots:

    void init_window(QImage background_);

private slots:

    void bus_spawn();

    virtual void add_actor(int locX, int locY, int type=0);

private:

    Dialog d_;

    QImage background_;

    bool startorexit_;

    Ui::MainWindow *ui;

    QGraphicsScene *map;

    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    CourseSide::SimpleActorItem* last_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms
};

#endif // MAINWINDOW_HH

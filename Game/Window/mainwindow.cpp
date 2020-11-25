#include "../Window/mainwindow.hh"
#include "ui_mainwindow.h"


const int PADDING = 30;
const int SIZE = 500;


namespace StudentSide {


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // We need a graphics scene in which to draw objects


    ui->gameView->setFixedSize(SIZE, SIZE);
    ui->exitButton->move(SIZE+PADDING, 3*PADDING);
    ui->startButton->move(SIZE+PADDING, PADDING);
    ui->pointsAmnt->move(SIZE+PADDING, 5*PADDING);
    ui->busAmount->move(SIZE+PADDING, 7*PADDING);
    ui->passAmnt->move(SIZE+PADDING, 9*PADDING);

    scene_ = new QGraphicsScene(this);
    ui->gameView->setScene(scene_);
    scene_->setSceneRect(0, 0, SIZE-4, SIZE-4);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_dialog()
{
    startorexit_ = d_.exec();

    if (startorexit_)
    {
        qDebug("Accepted dialog successfully");

    } else if (!startorexit_)
    {
        qDebug("Exited dialog successfully.");
        this->close();

    } else
    {
        qDebug("This shit ain supposed to happen dawg");
    }
}

void MainWindow::move_objects(std::shared_ptr<Interface::IActor> actor)
{
    /*
    for (auto object : actors_)
    {
        std::shared_ptr<Interface::IActor> iactor_object = object.first;
        QGraphicsItem* graphics_object = object.second;

        int tempX = iactor_object->giveLocation().giveX();
        int tempY = iactor_object->giveLocation().giveY();

        graphics_object->setPos(tempX, tempY);
    }
    */
    QGraphicsItem* graphics_object = actors_[actor];
    int tempX = actor->giveLocation().giveX();
    int tempY = actor->giveLocation().giveY();

    graphics_object->setPos(tempX, tempY);

}

void MainWindow::setPicture(QImage background)
{
    scene_->setBackgroundBrush(background);
}

void MainWindow::addActor(int X, int Y, int type,
                          std::shared_ptr<Interface::IActor> actor)
{
    CourseSide::SimpleActorItem* nActor =
            new CourseSide::SimpleActorItem(X, Y, type);

    actors_[actor] = nActor;
    scene_->addItem(nActor);
}

void MainWindow::addBus(int X, int Y, std::shared_ptr<CourseSide::Nysse> bus)
{
    RectActorItem* nBus = new RectActorItem(X, Y);
    actors_[bus] = nBus;
    scene_->addItem(nBus);
}

void MainWindow::addStop(int X, int Y, int type,
                          std::shared_ptr<Interface::IStop> stop)
{
    CourseSide::SimpleActorItem* nStop =
            new CourseSide::SimpleActorItem(X, Y, type);

    stops_[stop] = nStop;
    scene_->addItem(nStop);
}

void MainWindow::update_bus_amount(int amount)
{
    ui->busAmount->display(amount);
}

void MainWindow::update_pass_amount(int amount)
{
    ui->passAmnt->display(amount);
}

void MainWindow::update_points(int point_amnt)
{
    ui->pointsAmnt->display(point_amnt);
}


void MainWindow::spawn_destroyer(int X, int Y)
{
    qDebug("Spawned destroyer");
    player_ = new destroyer(X, Y);
    scene_->addItem(player_);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //
    if (event->key() == Qt::Key_A) {
        move_destroyer(player_, 'A');
        player_->setPos(+2, +0);

    }

    if (event->key() == Qt::Key_S) {
        move_destroyer(player_, 'S');
    }

    if (event->key() == Qt::Key_W) {
        move_destroyer(player_, 'W');
    }

    if (event->key() == Qt::Key_D) {
        move_destroyer(player_, 'D');
    }
}

void MainWindow::move_destroyer(destroyer* player, char direction)
{


}
}



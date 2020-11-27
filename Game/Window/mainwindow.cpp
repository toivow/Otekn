#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <random>

#include <QDebug>

const int SIZE = 500;


namespace StudentSide {


MainWindow::MainWindow(statistics* stats, QTime* clock, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stats_(stats),
    time_(new QTime())

{
    ui->setupUi(this);
    //Used to silence warning on unused param
    (void)clock;
    // We need a graphics scene in which to draw objects

    ui->gameView->setFixedSize(SIZE, SIZE);


    scene_ = new QGraphicsScene(this);
    ui->gameView->setScene(scene_);
    scene_->setSceneRect(0, 0, SIZE-4, SIZE-4);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene_, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::show_time);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete time_;
    delete stats_;
}

void MainWindow::moveObjects(std::shared_ptr<Interface::IActor> actor)
{
    QGraphicsItem* graphics_object = nullptr;
    std::shared_ptr<CourseSide::Nysse> movebus = std::dynamic_pointer_cast <CourseSide::Nysse>(actor);
    std::shared_ptr<CourseSide::Passenger> movepass= std::dynamic_pointer_cast<CourseSide::Passenger> (actor);

    if (movepass == nullptr)
    {
        graphics_object = buses_[movebus];

    }
    else if (movebus == nullptr)
    {
        graphics_object = actors_[movepass];
    }
    if (graphics_object == nullptr)
    {
        // qDebug("Yritti liikuttaa nullptr");
    }
    else
    {

    int tempX = actor->giveLocation().giveX() - 5;
    int tempY = 500 - actor->giveLocation().giveY() - 5;

    graphics_object->setPos(tempX, tempY);
    scene_->update();
    }



}

void MainWindow::setPicture(QImage background)
{
    scene_->setBackgroundBrush(background);
}

void MainWindow::addPass(int X, int Y, int type,
                          std::shared_ptr<CourseSide::Passenger> passenger)
{
    CourseSide::SimpleActorItem* nPass =
            new CourseSide::SimpleActorItem(X, Y, type);

    actors_[passenger] = nPass;
    scene_->addItem(nPass);
}

void MainWindow::addBus(int X, int Y, std::shared_ptr<CourseSide::Nysse> bus)
{
    RectActorItem* nBus = new RectActorItem(X, Y);
    buses_[bus] = nBus;
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


void MainWindow::updateBusAmount()
{
    ui->busAmount->display(stats_->busAmount());
}


void MainWindow::updatePassAmount()
{
    ui->passAmnt->display(stats_->passAmount());

}


void MainWindow::updatePoints()
{

    ui->pointsAmnt->display(stats_->returnPoints());
}


void MainWindow::spawnDestroyer(int X, int Y)
{
    qDebug("Spawned destroyer");
    destroyer* grafiikka = new destroyer(X, Y);
    destroyer_logic* logiikka = new destroyer_logic(X, Y);
    player_ = std::make_pair(logiikka, grafiikka);
    scene_->addItem(player_.second);
    player_.second->setPos(X, Y);
}

void MainWindow::spawnBanana()
{
    //Randomly generate x and y

    int rand_X = rand() % 400 + 100;
    int rand_Y = rand() % 400 + 100;

    randomitem* randitm_graf = new randomitem(rand_X, rand_Y);
    randomitem_logic* randitm_log = new randomitem_logic(rand_X, rand_Y);

    bananas_[randitm_log] = randitm_graf;
    scene_->addItem(randitm_graf);
    randitm_graf->setPos(rand_X, rand_Y);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int tempY = player_.first->giveLocation().giveY();
    int tempX =  player_.first->giveLocation().giveX();
    //Events that happen to destroyer on key presses
    if (event->key() == Qt::Key_A) {
        tempX += -10;
    }

    if (event->key() == Qt::Key_S) {
        tempY += 10;
    }

    if (event->key() == Qt::Key_W) {
        tempY += -10;
    }

    if (event->key() == Qt::Key_D) {
        tempX += 10;
    }

    Interface::Location* newloc = new Interface::Location;
    newloc->setXY(tempX, tempY);

    player_.first->move(*newloc);

    player_.second->setPos(tempX, tempY);

    checkDeaths(*newloc);

    delete newloc;


}


void MainWindow::checkDeaths(Interface::Location player_loc_)
{

    int killed_players = 0;

    for (auto it = actors_.begin(); it != actors_.end(); )
    {
        auto passloc = (*(*it).first).giveLocation();

        int passX = passloc.giveX() - 5;
        int passY = 500 - passloc.giveY() - 5;

        passloc.setXY(passX, passY);

        // Checks whether the passenger is close to our player, if the passenger
        // is active (so a killed actor that hasn't yet been removed) and if
        // the actor is in a bus, when they can't be killed.
        if (player_loc_.isClose( passloc) && (! ((*(*it).first).isRemoved()))
                && (!(*(*it).first).isInVehicle()))
        {

            (*(*it).first).remove();

            scene_->removeItem((*it).second);
            delete (*it).second;
            (*it).second = nullptr;

            it = actors_.erase(it);

            killed_players++;

        } else
        {
            it++;
        }

    }

    if (killed_players > 0)
    {
        qDebug() << "Killed " << killed_players << " players!";

        stats_->updatePoints(killed_players);

        updatePassAmount();
    }

    for (auto banana : bananas_)
    {

        if (player_loc_.isClose(banana.first->giveLocation()))
        {
            int reward = banana.first->return_reward();
            scene_->removeItem(banana.second);
            delete banana.second;
            banana.second = nullptr;

            stats_->updatePoints(reward);

        }
    }
    updatePoints();

    scene_->update();

}


void MainWindow::set_time(QTime clock)
{
    time_->setHMS(clock.hour(), clock.minute(), clock.second());
    timer->start(tick_);
}


void MainWindow::show_end_time(QTime* end_time)
{
    int minutes = end_time->minute();
    int hours = end_time->hour();

    std::string timestr = std::to_string(hours) + ':' + std::to_string(minutes);

    ui->endTimeLbl->setText(QString::fromStdString(timestr));
}


void MainWindow::show_time()
{
    int minutes = time_->minute();
    int hours = time_->hour();
    std::string timestr = std::to_string(hours) + ':' + std::to_string(minutes);

    ui->timeLbl->setText(QString::fromStdString(timestr));

}


}



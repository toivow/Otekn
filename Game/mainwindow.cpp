#include "mainwindow.hh"
#include "ui_mainwindow.h"


const int PADDING = 20;

MainWindow::MainWindow(QWidget *parent) :
    CourseSide::SimpleMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&d_, SIGNAL(map_choice(QImage)), SLOT(init_window(QImage)));
    connect(&d_, SIGNAL(rejected()), this, SLOT(close()));

    connect(ui->busSpawnButton, SIGNAL(clicked()), this, SLOT(bus_spawn()));

    ui->gameView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);
    ui->busSpawnButton->move(width_ + PADDING, 3*PADDING);
    ui->exitButton->move(width_ + PADDING, 5*PADDING);
    ui->pointsAmnt->move(width_ + PADDING, 7*PADDING);
    ui->timeLeft->move(width_ + PADDING, 9*PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);
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

void MainWindow::init_window(QImage background_)
{
    map->setBackgroundBrush(background_);
}

void MainWindow::bus_spawn()
{
    qDebug("Pitäisi spawnata");
    CourseSide::SimpleActorItem* test = new CourseSide::SimpleActorItem(10, 10) ;

}

#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    CourseSide::SimpleMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&d_, SIGNAL(map_choice(QImage)), SLOT(init_window(QImage)));
    connect(&d_, SIGNAL(rejected()), this, SLOT(close()));

    init_dialog();
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

    qDebug("Ei pitäsi tulostaa tätä");
}

void MainWindow::init_window(QImage background_)
{
    this->setPicture(background_);
}

#include "dialog.hh"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    start_time_(new QTime(QTime::currentTime().hour(),
                          QTime::currentTime().minute(),
                          QTime::currentTime().second())),
    gamedur_(0)
{
    ui->setupUi(this);
    QGraphicsScene *scene_ = new QGraphicsScene(this);
    view_ = new QGraphicsView(this);
    view_->setScene(scene_);

    connect(ui->exit_button, &QPushButton::clicked, this, &Dialog::reject);
    connect(ui->start_button, &QPushButton::clicked, this, &Dialog::accept);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_gameduration_valueChanged(int value)
{
    gamedur_ = value;
}

void Dialog::on_startingtime_userTimeChanged(const QTime &time)
{
    *start_time_ = time;
}

void Dialog::accept()
{
    emit game_length(gamedur_, start_time_);
    QDialog::accept();
}



#include "dialog.hh"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    start_time(new QTime()),
    peliaika(0)
{
    ui->setupUi(this);
    QGraphicsScene *scene_ = new QGraphicsScene(this);
    view_ = new QGraphicsView(this);
    view_->setScene(scene_);


    connect(ui->exit_button, SIGNAL(clicked()), SLOT(reject()));
    //connect(ui->start_button, SIGNAL(clicked()), SLOT(start_program()));
    connect(ui->start_button, SIGNAL(clicked()), SLOT(accept()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_peliaika_valueChanged(int arg1)
{
    peliaika = arg1;
}

void Dialog::on_startingtime_userTimeChanged(const QTime &time)
{
    *start_time = time;
}

void Dialog::accept()
{
    emit game_length(peliaika, start_time);
    QDialog::accept();
}

void Dialog::start_program()
{
    emit game_length(peliaika, start_time);
}

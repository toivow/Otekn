#include "../Window/dialog.hh"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QGraphicsScene *scene_ = new QGraphicsScene(this);
    view_ = new QGraphicsView(this);
    view_->setScene(scene_);


    connect(ui->exit_button, SIGNAL(clicked()), SLOT(reject()));
    connect(ui->start_button, SIGNAL(clicked()), SLOT(start_prog()));
    connect(ui->start_button, SIGNAL(clicked()), SLOT(accept()));
    connect(ui->start_button, SIGNAL(clicked()), SLOT(send_game_time()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sending_game_time()
{
    int time = ui->peliaika->value();
    emit game_time(time);
}


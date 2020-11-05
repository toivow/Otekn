#include "dialog.hh"
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

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_big_map_clicked()
{
    if (ui->big_map->checkState() == 2)
    {
        ui->small_map->setEnabled(false);
        ui->hervanta_map->setEnabled(false);
    }
    else if (ui->big_map->checkState() == 0)
    {
        ui->small_map->setEnabled(true);
        ui->hervanta_map->setEnabled(true);
    }
}


void Dialog::on_small_map_clicked()
{
    if (ui->small_map->checkState() == 2)
    {
        ui->big_map->setEnabled(false);
        ui->hervanta_map->setEnabled(false);
    }
    else if (ui->small_map->checkState() == 0)
    {
        ui->big_map->setEnabled(true);
        ui->hervanta_map->setEnabled(true);
    }
}

void Dialog::on_hervanta_map_clicked()
{
    if (ui->hervanta_map->checkState() == 2)
    {
        ui->big_map->setEnabled(false);
        ui->small_map->setEnabled(false);
    }
    else if (ui->hervanta_map->checkState() == 0)
    {
        ui->big_map->setEnabled(true);
        ui->small_map->setEnabled(true);
    }
}

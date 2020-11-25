#include "../Window/dialog.hh"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    map_name_("undefined")
{
    ui->setupUi(this);
    QGraphicsScene *scene_ = new QGraphicsScene(this);
    view_ = new QGraphicsView(this);
    view_->setScene(scene_);


    connect(ui->exit_button, SIGNAL(clicked()), SLOT(reject()));
    connect(ui->start_button, SIGNAL(clicked()), SLOT(start_prog()));
    connect(ui->start_button, SIGNAL(clicked()), SLOT(accept()));
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
        map_name_ = "big";
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
        map_name_ = "small";
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
        map_name_ = "hervanta";
    }
    else if (ui->hervanta_map->checkState() == 0)
    {
        ui->big_map->setEnabled(true);
        ui->small_map->setEnabled(true);
    }
}

void Dialog::start_prog()
{
    if (map_name_ == "hervanta") {
        map_pic_.load("bruh doesnt exist");
        qDebug("Ei oo olemassa vielä");

    } else if (map_name_ == "big")
    {
        map_pic_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    } else if (map_name_ == "small")
    {
        map_pic_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    }
    emit map_choice(map_pic_);
}

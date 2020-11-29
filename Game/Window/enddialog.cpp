#include "enddialog.hh"
#include "ui_enddialog.h"

namespace StudentSide {

EndDialog::EndDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndDialog)
{
    ui->setupUi(this);
}

EndDialog::~EndDialog()
{
    delete ui;
}

void EndDialog::set_points(int points)
{
    ui->pointsLbl->setNum(points);
}
}

void StudentSide::EndDialog::on_OkButton_clicked()
{
    this->reject();
}

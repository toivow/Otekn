#ifndef ENDDIALOG_HH
#define ENDDIALOG_HH

#include <QDialog>

namespace Ui {
class EndDialog;
}

namespace StudentSide {



class EndDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndDialog(QWidget *parent = nullptr);
    ~EndDialog();

    void set_points(int points);

private slots:
    void on_OkButton_clicked();

private:
    Ui::EndDialog *ui;
};
}

#endif // ENDDIALOG_HH

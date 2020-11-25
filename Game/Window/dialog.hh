#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>
#include <QGraphicsView>
#include <QPushButton>
#include <QMainWindow>
#include <QSpinBox>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:

    void game_time(int time);

private slots:

    void sending_game_time();


private:
    Ui::Dialog *ui;

    QGraphicsView* view_;

    QPushButton* start_button;
    QPushButton* exit_button;

    QSpinBox* peliaika;

};

#endif // DIALOG_HH

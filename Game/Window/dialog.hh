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

    void game_length(int time, QTime* start_time);


private slots:

    void accept() override;

    void start_program();

    void on_peliaika_valueChanged(int arg1);

    void on_startingtime_userTimeChanged(const QTime &time);

private:
    Ui::Dialog *ui;

    QGraphicsView* view_;

    QTime* start_time;

    QPushButton* start_button;
    QPushButton* exit_button;

    int peliaika;

};

#endif // DIALOG_HH

#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>
#include <QGraphicsView>
#include <QPushButton>
#include <QMainWindow>
#include <QSpinBox>


/** @file
 * @brief A dialog class used for the starting dialog when starting the game.
 */


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
    /**
     * @brief signal used to send wished game duration and game starting time.
     * @param time is the wished game duration
     * @param start_time is the wished starting time of the day
     */
    void game_length(int time, QTime* start_time);


private slots:
    /**
     * @brief Overrided accept function because we had problems with game freezing
     * with the original accept function.
     * @return -
     * @post Exception guaranteee: Nothrow
     */
    void accept() override;

    /**
     * @brief on_gameduration_valueChanged changes wished game duration
     * @param value is the wished game duration
     * @return -
     * @post Exception guaranteee: Nothrow
     */
    void on_gameduration_valueChanged(int value);

    /**
     * @brief on_startingtime_userTimeChanged changes wished game start time
     * @param value is the wished game start time
     * @return -
     * @post Exception guaranteee: Nothrow
     */
    void on_startingtime_userTimeChanged(const QTime &time);

private:
    Ui::Dialog *ui;

    QGraphicsView* view_;

    QTime* start_time_;

    QPushButton* start_button;
    QPushButton* exit_button;

    int gamedur_;

};

#endif // DIALOG_HH

#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>
#include <QGraphicsView>
#include <QPushButton>
#include <QMainWindow>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_big_map_clicked();

    void on_small_map_clicked();

    void on_hervanta_map_clicked();


private:
    Ui::Dialog *ui;

    QGraphicsView* view_;

    QPushButton* start_button;
    QPushButton* exit_button;

};

#endif // DIALOG_HH

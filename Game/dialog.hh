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

signals:

    void map_choice(QImage map_pic_);

private slots:
    void on_big_map_clicked();

    void on_small_map_clicked();

    void on_hervanta_map_clicked();

    void start_prog();


private:
    Ui::Dialog *ui;

    QGraphicsView* view_;

    QImage map_pic_;

    QPushButton* start_button;
    QPushButton* exit_button;

    std::string map_name_;

};

#endif // DIALOG_HH

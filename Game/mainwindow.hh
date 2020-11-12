#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "../CourseLib/graphics/simplemainwindow.hh"
#include <QMainWindow>
#include "dialog.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public CourseSide::SimpleMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_dialog();

public slots:

    void init_window(QImage background_);

private:

    Dialog d_;

    QImage background_;

    bool startorexit_;

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_HH

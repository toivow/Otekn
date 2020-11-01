#include "../CourseLib/graphics/simplemainwindow.hh"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    QImage kuva;
    kuva.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    CourseSide::SimpleMainWindow ikkuna;
    ikkuna.setPicture(kuva);

    ikkuna.show();

    return a.exec();
}

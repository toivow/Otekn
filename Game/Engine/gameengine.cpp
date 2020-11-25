#include "../Engine/gameengine.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"

gameengine::gameengine(QObject* parent) :
    QObject(parent)
{
    basicbackground_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    bigbackground_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    StudentSide::creategame temp;
    city_ = temp.createGame();
    city_->setBackground(basicbackground_, bigbackground_);


    l_.fileConfig();
    l_.setTime(20, 00);
    l_.takeCity(city_);
    l_.finalizeGameStart();

}

gameengine::~gameengine()
{
}

void gameengine::show_board()
{
}

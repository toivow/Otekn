#include "gameengine.hh"

gameengine::gameengine(QObject* parent) :
    QObject(parent),
    l_(new CourseSide::Logic())
{
    basicbackground_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    bigbackground_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    StudentSide::creategame temp;
    city_ = temp.createGame();
    city_->setBackground(basicbackground_, bigbackground_);

    l_->fileConfig();

    Dialog* d = new Dialog();

    connect(d, &Dialog::game_length, this, &gameengine::conf_logic);

    d->exec();

}

gameengine::~gameengine()
{
}

void gameengine::conf_logic(int gametime, QTime *clock)

{
    unsigned short minute = clock->minute();
    unsigned short hour =  clock->hour();


    l_->takeCity(city_);
    l_->setTime(hour, minute);
    l_->configChanged(*clock, false);

    l_->finalizeGameStart();

    city_->set_game_duration(gametime);

}

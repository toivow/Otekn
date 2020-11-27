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


    connect(d, SIGNAL(game_length(int,QTime*)), this, SLOT(confLogic(int,QTime*)));

    d->exec();

    qDebug("This statement after d->exec()");
}

gameengine::~gameengine()
{
}

void gameengine::confLogic(int gametime, QTime *clock)
{
    int minute = clock->minute();
    int hour =  clock->hour();


    l_->takeCity(city_);

    l_->setTime(hour, minute);



    l_->configChanged(*clock, false);

    city_->set_game_duration(gametime, clock);

    l_->finalizeGameStart();




}

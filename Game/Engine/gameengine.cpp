#include "gameengine.hh"

gameengine::gameengine(QObject* parent) :
    QObject(parent),
    game_logic_(new CourseSide::Logic())
{
    basicbackground_.load(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    bigbackground_.load(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
}

gameengine::~gameengine()
{
    delete game_logic_;
}

void gameengine::confLogic(int gametime, QTime *clock)
{    
    int minute = clock->minute();
    int hour =  clock->hour();


    game_logic_->takeCity(city_);

    game_logic_->setTime(hour, minute);

    city_->set_game_duration(gametime, clock);

    game_logic_->finalizeGameStart();

}

bool gameengine::execDialog()
{
    StudentSide::creategame temp;
    city_ = temp.createGame();
    city_->setBackground(basicbackground_, bigbackground_);

    game_logic_->fileConfig();

    Dialog* d = new Dialog();


    connect(d, SIGNAL(game_length(int,QTime*)), this, SLOT(confLogic(int,QTime*)));

    if(d->exec()){
        return true;
    }
    else {
        return false;
    }
}

#ifndef CITY_HH
#define CITY_HH

#include "../CourseLib/interfaces/icity.hh"

namespace StudentSide
{
using namespace Interface;



class city : public Interface::ICity
{
public:
    city();


    virtual ~city() = default;

    virtual void setBackground(QImage& basicbackground, QImage& bigbackground) = 0;

    virtual void setClock(QTime clock) = 0;

    virtual void addStop(std::shared_ptr<IStop> stop) = 0;

    virtual void startGame() = 0;

    virtual void addActor(std::shared_ptr<IActor> newactor) = 0;

    virtual void removeActor(std::shared_ptr<IActor> actor) = 0;

    virtual void actorRemoved(std::shared_ptr<IActor> actor) = 0;

    virtual bool findActor(std::shared_ptr<IActor> actor) const = 0;

    virtual void actorMoved(std::shared_ptr<IActor> actor) = 0;

    virtual std::vector<std::shared_ptr<IActor>> getNearbyActors(Location loc) const = 0;

    virtual bool isGameOver() const = 0;

private:

    QImage background_;


};
}
#endif // CITY_HH

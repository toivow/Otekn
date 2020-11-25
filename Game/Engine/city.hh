#ifndef CITY_HH
#define CITY_HH

#include "../CourseLib/interfaces/icity.hh"
#include "../Window/mainwindow.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"
#include <QTime>
#include <unordered_map>

namespace StudentSide
{
using namespace Interface;


class city : public Interface::ICity
{
public:
    city();

    ~city();

    void setBackground(QImage& basicbackground, QImage& bigbackground);

    void setClock(QTime clock);

    void addStop(std::shared_ptr<IStop> stop);

    void startGame();

    void addActor(std::shared_ptr<IActor> newactor);

    void removeActor(std::shared_ptr<IActor> actor);

    void actorRemoved(std::shared_ptr<IActor> actor);

    bool findActor(std::shared_ptr<IActor> actor) const;

    void actorMoved(std::shared_ptr<IActor> actor);

    std::vector<std::shared_ptr<IActor>> getNearbyActors(Location loc) const;

    bool isGameOver() const;

private:

    QImage background_;

    std::list <std::shared_ptr<CourseSide::Passenger>> passengers_;
    std::list <std::shared_ptr<CourseSide::Nysse>> buses_;

    std::list< std::shared_ptr<IStop>> stops_;

    bool debugstate_;
    bool gamestarted_;

    StudentSide::MainWindow window_;

    QTime aika_;

    StudentSide::statistics stats_;


};
}
#endif // CITY_HH

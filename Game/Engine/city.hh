#ifndef CITY_HH
#define CITY_HH

#include "../CourseLib/interfaces/icity.hh"
#include "../Window/mainwindow.hh"
#include <QTime>
#include <unordered_map>
#include "statistics.hh"
#include "../Window/enddialog.hh"

/** @file
 * @brief defines a class that handles the operations within the city.
 * Uncommented functions defintions can be found in file ../CourseLib/interfaces/icity.hh
 */


namespace StudentSide
{
using namespace Interface;


class city : public Interface::ICity
{
public:
    city();

    ~city();

    /**
     * @brief set_game_duration sets game_duration into given parameter.
     * @param int time is wished game_duration in minutes.
     * @pre City is in init state.
     * @post game_duration_ set into wished value.
     * @exception Nothrow
     */
    void set_game_duration(int time, QTime* clock);

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

    statistics* stats_;

    QTime* time_;
    QTime* end_time_;

    MainWindow* window_;


    QImage background_;

    std::list <std::shared_ptr<CourseSide::Passenger>> passengers_;
    std::list <std::shared_ptr<CourseSide::Nysse>> buses_;

    std::list< std::shared_ptr<IStop>> stops_;

    bool debugstate_;
    bool gamestarted_;

    int game_duration_;

    bool enable_end_time_;

    EndDialog* end_dialog_;


};
}
#endif // CITY_HH

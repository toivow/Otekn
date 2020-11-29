#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include <QDialog>
#include <QImage>
#include <QObject>
#include <QTimer>
#include "../Window/dialog.hh"
#include "../CourseLib/graphics/simplemainwindow.hh"
#include "../CourseLib/core/logic.hh"
#include "city.hh"
#include "creategame.hh"

/**
  * @file
  * @brief Defines a class that handles running the whole game.
  */
namespace StudentSide {

class gameengine : public QObject
{
    Q_OBJECT

public:

    explicit gameengine(QObject* parent=nullptr);
    virtual ~gameengine();

public slots:
    /**
     * @brief confLogic used to configure wished starting time and game duration.
     * @param gametime is the game duration given in dialog.
     * @param clock is a pointer to the wished game starting time from dialog.
     * @pre logic object game_logic_ in init state after calling fileconfig method.
     * @return -
     * @post Exception guaranteee: basic.
     */
    void confLogic(int gametime, QTime* clock);

    /**
     * @brief execDialog is used to call the dialog for a new gameengine object.
     * @pre A new gameengine object is created.
     * @return true if dialog accepted, false if not
     * @post city_ is configured and game_logic_ parameters are set
     */
    bool execDialog();

private:

   QImage map_name_;

   bool startorexit_;

   QImage basicbackground_;
   QImage bigbackground_;

   std::shared_ptr<StudentSide::city> city_;

   StudentSide::creategame temp;

   CourseSide::Logic* game_logic_;

};
}

#endif // GAMEENGINE_HH

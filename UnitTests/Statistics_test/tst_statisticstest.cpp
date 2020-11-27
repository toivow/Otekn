#include <QtTest>
#include "../../Game/Engine/statistics.hh"

// add necessary includes here
using namespace StudentSide;

class statisticstest : public QObject
{
    Q_OBJECT

public:
    statisticstest();
    ~statisticstest();

private slots:
    void updatePoints();
    void returnPoints();
    void busAmount();
    void passAmount();
    void addPass();
    void addBus();

};

statisticstest::statisticstest()
{

}

statisticstest::~statisticstest()
{

}
void statisticstest::returnPoints()
{
    statistics stats;
    QVERIFY2(stats.returnPoints() == 0,"Returned wrong points value");

}

void statisticstest::busAmount()
{
    statistics stats;
    QVERIFY2(stats.busAmount() == 0,"Returned wrong bus value");

}

void statisticstest::passAmount()
{
    statistics stats;
    QVERIFY2(stats.passAmount() == 0,"Returned wrong passenger value");

}

void statisticstest::updatePoints()
{
    statistics stats;
    stats.updatePoints(1);
    QVERIFY2(stats.returnPoints() == 1, "Miscalculated points");
}

void statisticstest::addPass()
{
    statistics stats;
    stats.addPass(1);
    QVERIFY2(stats.passAmount() == 1, "Miscalculated passengers");
}

void statisticstest::addBus()
{
    statistics stats;
    stats.addBus(1);
    QVERIFY2(stats.busAmount() == 1, "Miscalculated busses");
}


QTEST_APPLESS_MAIN(statisticstest)

#include "tst_statisticstest.moc"

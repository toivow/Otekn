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
    void update_points();
    void return_points();
    void bus_amount();
    void pass_amount();
    void add_pass();
    void add_bus();

};

statisticstest::statisticstest()
{

}

statisticstest::~statisticstest()
{

}
void statisticstest::return_points()
{
    statistics stats;
    QVERIFY2(stats.return_points() == 0,"Returned wrong points value");

}

void statisticstest::bus_amount()
{
    statistics stats;
    QVERIFY2(stats.bus_amount() == 0,"Returned wrong bus value");

}

void statisticstest::pass_amount()
{
    statistics stats;
    QVERIFY2(stats.pass_amount() == 0,"Returned wrong passenger value");

}

void statisticstest::update_points()
{
    statistics stats;
    stats.update_points(1);
    QVERIFY2(stats.return_points() == 1, "Miscalculated points");
}

void statisticstest::add_pass()
{
    statistics stats;
    stats.add_pass(1);
    QVERIFY2(stats.pass_amount() == 1, "Miscalculated passengers");
}

void statisticstest::add_bus()
{
    statistics stats;
    stats.add_bus(1);
    QVERIFY2(stats.bus_amount() == 1, "Miscalculated busses");
}


QTEST_APPLESS_MAIN(statisticstest)

#include "tst_statisticstest.moc"

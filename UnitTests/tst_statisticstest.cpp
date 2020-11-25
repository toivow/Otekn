#include <QtTest>
#include "../Game/Engine/statistics.h"

// add necessary includes here

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();
    ~StatisticsTest();

private slots:
    void test_case1();
    void current_busses(int x);
    void update_points();

};

StatisticsTest::StatisticsTest()
{

}

StatisticsTest::~StatisticsTest()
{

}

void StatisticsTest::test_case1()
{


}
void StatisticsTest::update_points();
{
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "tst_statisticstest.moc"

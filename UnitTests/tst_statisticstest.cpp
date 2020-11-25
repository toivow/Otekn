#include <QtTest>

// add necessary includes here

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();
    ~StatisticsTest();

private slots:
    void test_case1();

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

QTEST_APPLESS_MAIN(StatisticsTest)

#include "tst_statisticstest.moc"

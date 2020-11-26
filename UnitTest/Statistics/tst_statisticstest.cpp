#include <QtTest>

// add necessary includes here

class statisticstest : public QObject
{
    Q_OBJECT

public:
    statisticstest();
    ~statisticstest();

private slots:
    void test_case1();

};

statisticstest::statisticstest()
{

}

statisticstest::~statisticstest()
{

}

void statisticstest::test_case1()
{

}

QTEST_APPLESS_MAIN(statisticstest)

#include "tst_statisticstest.moc"

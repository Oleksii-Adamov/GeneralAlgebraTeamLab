#include <QtTest>

// add necessary includes here
#include "task1/numbermodulo.h"

class TestNumberModulo : public QObject
{
    Q_OBJECT

public:
    TestNumberModulo();
    ~TestNumberModulo();

private slots:
    void test_case_get_num();
    void test_case_set_num();

};

TestNumberModulo::TestNumberModulo()
{

}

TestNumberModulo::~TestNumberModulo()
{

}

// tests test_case_get_num and test_case_set_num are depend on each other

void TestNumberModulo::test_case_get_num()
{
    NumberModulo test_num;
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(5);
    QCOMPARE(test_num.get_num(), 5);
}

void TestNumberModulo::test_case_set_num()
{
    NumberModulo test_num;
    test_num.set_num(5);
    QCOMPARE(test_num.get_num(), 5);
    test_num.set_num(3);
    QCOMPARE(test_num.get_num(), 3);
    // to do negative (maybe should in different test_case
}


QTEST_APPLESS_MAIN(TestNumberModulo)

#include "tst_testnumbermodulo.moc"

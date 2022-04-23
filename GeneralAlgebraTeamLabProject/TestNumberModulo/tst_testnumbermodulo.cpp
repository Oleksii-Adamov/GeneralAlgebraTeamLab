#include <QtTest>

// add necessary includes here
#include "task1/numbermodulo.h"
#include <stdexcept>

class TestNumberModulo : public QObject
{
    Q_OBJECT

public:
    TestNumberModulo();
    ~TestNumberModulo();

private slots:
    void test_case_get_num();
    void test_case_set_num();
    void test_case_mod();
};

TestNumberModulo::TestNumberModulo()
{

}

TestNumberModulo::~TestNumberModulo()
{

}

// get and set tests depend on each other. I don't want to use friend for this.

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
    test_num.set_num(-2);
    QCOMPARE(test_num.get_num(), -2);
}

void TestNumberModulo::test_case_mod()
{
    NumberModulo test_num;
    // zero mod
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.mod(0));
    // postive mod
    // positive num
    test_num.set_num(5);
    test_num.mod(2);
    QCOMPARE(test_num.get_num(), 1);
    test_num.set_num(7);
    test_num.mod(5);
    QCOMPARE(test_num.get_num(), 2);
    test_num.set_num(3);
    test_num.mod(3);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(12);
    test_num.mod(4);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(13);
    test_num.mod(1);
    QCOMPARE(test_num.get_num(), 0);
    // negative num
    test_num.set_num(-5);
    test_num.mod(2);
    QCOMPARE(test_num.get_num(), 1);
    test_num.set_num(-7);
    test_num.mod(5);
    QCOMPARE(test_num.get_num(), 3);
    test_num.set_num(-3);
    test_num.mod(3);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(-12);
    test_num.mod(4);
    QCOMPARE(test_num.get_num(), 0);
    // zero num
    test_num.set_num(0);
    test_num.mod(3);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(0);
    test_num.mod(5);
    QCOMPARE(test_num.get_num(), 0);
}

QTEST_APPLESS_MAIN(TestNumberModulo)

#include "tst_testnumbermodulo.moc"

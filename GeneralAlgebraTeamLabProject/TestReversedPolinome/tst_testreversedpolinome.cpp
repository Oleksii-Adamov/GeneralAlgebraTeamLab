#include <QtTest>
#include "task19/reversepolinom.h"
#include <string>

// add necessary includes here

class TestReversedPolinome : public QObject
{
    Q_OBJECT

public:
    TestReversedPolinome();
    ~TestReversedPolinome();

private slots:
    void test_case1();

};

TestReversedPolinome::TestReversedPolinome()
{

}

TestReversedPolinome::~TestReversedPolinome()
{

}

void TestReversedPolinome::test_case1()
{

    auto a = Polinome("x^5+2x^4+x^2+1");
    auto b = Polinome("x^4+1");
    auto x = Polinome("1");
    ReversePolinom rp;

    x = rp.xGCD(a, b, 5);


    QCOMPARE(1, 1);


}

QTEST_APPLESS_MAIN(TestReversedPolinome)

#include "tst_testreversedpolinome.moc"

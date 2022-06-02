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
//PolynomialRemainder[(a)(res), p, x, Modulus -> 3]
    auto p = Polinome("x^8+x^4+x^3+x+1");
    auto a = Polinome("x^6+x^4+x+1");
    Polinome result = Polinome("x^7+x^6+x^3+x");
    ReversePolinom rp(a, p, 2);
    QCOMPARE (rp.get_reverse(), result);

    auto p1 = Polinome("x^4+x^3+x^2+1");
    auto a1 = Polinome("2x^2+2");
    Polinome result1 = Polinome("2x^3+x^2+2x+1");
    ReversePolinom rp1(a1, p1, 3);
    QCOMPARE (rp1.get_reverse(), result1);

    auto p2 = Polinome("x^7+x^6+x^3+x+1");
    auto a2 = Polinome("x^4+x^2");
    Polinome result2 = Polinome("2x^3+2x^2+2x+1");
    ReversePolinom rp2(a2, p2, 2);
    QCOMPARE (rp2.get_reverse(), result2);
}

QTEST_APPLESS_MAIN(TestReversedPolinome)

#include "tst_testreversedpolinome.moc"

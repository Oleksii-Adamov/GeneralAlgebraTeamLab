#include <QTest>

#include "task15/ri.h"

class TestRi : public QObject {
    Q_OBJECT

public:
    TestRi();
    ~TestRi();

private slots:
    void testD();
    void testM();
    void testRi();
    void testProductOfCyclotomic();
};

TestRi::TestRi() {}
TestRi::~TestRi() {}

void TestRi::testD()
{
    QCOMPARE(d(3,52),6);
}

void TestRi::testM()
{
    QCOMPARE(m(3,8,1),2);
}

void TestRi::testRi()
{
 QCOMPARE(ri(3,8,1).toString(),"x^3 + x");
 QCOMPARE(ri(5,12,1).toString(),"x^5 + x");
}

void TestRi::testProductOfCyclotomic()
{
     auto res = computePolynomialProductOfCyclotomicPlynomial(3,52);
     auto mult = Polinome("1");
     for(auto i : res)
     {
        mult = mult.multiply(i,3);
        //std::cout<<i.toString()<<std::endl;
     }
     //std::cout<<std::endl;
     QCOMPARE(degreeOfPolinome(*mult.divide(*CyclotomicPolynomial(52,3).quotient,3).quotient), 0);
     QCOMPARE(mult.divide(*CyclotomicPolynomial(52,3).quotient,3).remainder->toString(), "0");


     auto res2 = computePolynomialProductOfCyclotomicPlynomial(3,8);
     auto mult2 = Polinome("1");
     for(auto i : res2)
     {
        mult2 = mult2.multiply(i,3);
       // std::cout<<i.toString()<<std::endl;
     }
     QCOMPARE(degreeOfPolinome(*mult2.divide(*CyclotomicPolynomial(8,3).quotient,3).quotient), 0);
     QCOMPARE(mult2.divide(*CyclotomicPolynomial(8,3).quotient,3).remainder->toString(), "0");
     //std::cout<<std::endl;

     auto res3 = computePolynomialProductOfCyclotomicPlynomial(5,8);
     auto mult3 = Polinome("1");
     for(auto i : res3)
     {
        //std::cout<<i.toString()<<std::endl;
        mult3 = mult3.multiply(i,5);
     }
     QCOMPARE(degreeOfPolinome(*mult3.divide(*CyclotomicPolynomial(8,5).quotient,5).quotient), 0);
     QCOMPARE(mult3.divide(*CyclotomicPolynomial(8,5).quotient,5).remainder->toString(), "0");
}


QTEST_APPLESS_MAIN(TestRi)

#include "tst_ri.moc"

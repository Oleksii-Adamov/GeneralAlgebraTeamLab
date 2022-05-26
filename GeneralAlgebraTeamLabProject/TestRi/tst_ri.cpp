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
//            std::cout<<i.toString()<<std::endl;
        }
//        std::cout<<Polinome("x^24 + 2x^22 + x^20 + 2x^18 + x^16 + 2x^14 + x^12 + 2x^10 + x^8 + 2x^6 + x^4 + 2x^2 + 1").gcd(Polinome("x^18 + x^6 + x^2+1"),3)->toString()<<std::endl;
//      std::cout<<Polinome("x^12+x^10+2x^8+x^6+x^4+x^2+1").gcd(Polinome("x^10+x^8+2x^6+2x^2"),3)->toString()<<std::endl;
//        std::cout<<mult.toString()<<std::endl;
//        std::cout<<CyclotomicPolynomial(52,3).quotient->toString()<<std::endl;

     QCOMPARE(mult.toString(),CyclotomicPolynomial(52,3).quotient->toString());

     auto res2 = computePolynomialProductOfCyclotomicPlynomial(3,8);
     auto mult2 = Polinome("1");
     for(auto i : res2)
     {
         mult2 = mult2.multiply(i,3);
     }
     QCOMPARE(mult2.toString(),CyclotomicPolynomial(8,3).quotient->toString());
}


QTEST_APPLESS_MAIN(TestRi)

#include "tst_ri.moc"

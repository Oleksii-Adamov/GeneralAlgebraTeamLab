#include <QtTest>

// add necessary includes here
#include "task7/discrete_logarithm.h"
#include <stdexcept>
#include <sstream>
#include <vector>

class DiscreteLogarithm : public QObject
{
    Q_OBJECT

public:
    DiscreteLogarithm();
    ~DiscreteLogarithm();

private slots:
    void testDiscreteLogarithm();
    void testDiscreteLogarithmBabyStep();
};

DiscreteLogarithm::DiscreteLogarithm()
{

}

DiscreteLogarithm::~DiscreteLogarithm()
{

}

void DiscreteLogarithm::testDiscreteLogarithm()
{
     QCOMPARE(discreteLogarithm(3, 13, 17), 4);
     QCOMPARE(discreteLogarithm(2, 18, 19), 9);
     QCOMPARE(discreteLogarithm(3, 12, 17), 13);
     QCOMPARE(discreteLogarithm(5,  4,  7), 2);
     QCOMPARE(discreteLogarithm(5,  4, 11), 8);
     QCOMPARE(discreteLogarithm(3,  4,  5), 2);
}

void DiscreteLogarithm::testDiscreteLogarithmBabyStep()
{
    std::vector<long long> results1 = {45};
    std::vector<long long> values1 = discreteLogarithm2(2, 13, 59);
    for(unsigned long long i = 0; i <= values1.size() - 1; i++) {
      QCOMPARE(values1[i], results1[i]);
    }

    std::vector<long long> results2 = {10, 30, 50, 70 ,90, 110, 130, 150, 170, 190};
    std::vector<long long> values2 = discreteLogarithm2(8, 24, 200);
    for(unsigned long long i = 0; i <= values2.size() - 1; i++) {
      QCOMPARE(values2[i], results2[i]);
    }

    std::vector<long long> results3 = {1, 3, 5, 7, 9, 11, 13};
    std::vector<long long> values3 = discreteLogarithm2(5, 5, 15);
    for(unsigned long long i = 0; i <= values3.size() - 1; i++) {
      QCOMPARE(values3[i], results3[i]);
    }

    std::vector<long long> results4 = {10, 30, 50, 70, 90, 110, 130};
    std::vector<long long> values4 = discreteLogarithm2(12, 24, 150);
    for(unsigned long long i = 0; i <= values4.size() - 1; i++) {
      QCOMPARE(values4[i], results4[i]);
    }

    std::vector<long long> results5 = {2};
    std::vector<long long> values5 = discreteLogarithm2(5,  4,  7);
    for(unsigned long long i = 0; i <= values5.size() - 1; i++) {
      QCOMPARE(values5[i], results5[i]);
    }

    std::vector<long long> results6 = {0};
    std::vector<long long> values6 = discreteLogarithm2(2,  1,  6);
    for(unsigned long long i = 0; i <= values6.size() - 1; i++) {
      QCOMPARE(values6[i], values6[i]);
    }

    std::vector<long long> results7 = {0, 12};
    std::vector<long long> values7 = discreteLogarithm2(2,  1,  6);
    for(unsigned long long i = 0; i <= values7.size() - 1; i++) {
      QCOMPARE(values7[i], values7[i]);
    }
}


QTEST_APPLESS_MAIN(DiscreteLogarithm)

#include "tst_discretelogarithm.moc"

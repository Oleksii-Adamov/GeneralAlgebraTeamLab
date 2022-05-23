#include <QtTest>

// add necessary includes here
#include "task7/discrete_logarithm.h"
#include <stdexcept>
#include <sstream>

class DiscreteLogarithm : public QObject
{
    Q_OBJECT

public:
    DiscreteLogarithm();
    ~DiscreteLogarithm();

private slots:
    void testDiscreteLogarithm();
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

QTEST_APPLESS_MAIN(DiscreteLogarithm)

#include "tst_discretelogarithm.moc"

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
     std::vector<long long> result = {4};
     long long a = 3;
     long long b = 13;
     unsigned long long p = 17;
     QCOMPARE(discreteLogarithm(a, b, p), result);
     result =  {9};
     QCOMPARE(discreteLogarithm(2, 18, 19), result);
     result =  {13};
     QCOMPARE(discreteLogarithm(3, 12, 17), result);
     result =  {2};
     QCOMPARE(discreteLogarithm(5,  4,  7), result);
     result =  {3,8};
     QCOMPARE(discreteLogarithm(5,  4, 11), result);
     result =  {2};
     QCOMPARE(discreteLogarithm(3,  4,  5), result);
     result =  {10,30,50,70,90,110,130,150,170,190};
     QCOMPARE(discreteLogarithm(8, 24, 200), result);
     result =  {54580};
     QCOMPARE(discreteLogarithm(2, 100, 100003), result);

}

void DiscreteLogarithm::testDiscreteLogarithmBabyStep()
{
   std::vector<long long> results1 = {45};
   std::vector<unsigned long long> values1 = discreteLogarithm2(2, 13, 59);
   for(unsigned long long i = 0; i < 1; i++) {
     QCOMPARE(values1[i], results1[i]);
   }

   std::vector<long long> results2 = {10, 30, 50, 70 ,90, 110, 130, 150, 170, 190};
   std::vector<unsigned long long> values2 = discreteLogarithm2(8, 24, 200);
   for(unsigned long long i = 0; i < 1; i++) {
     QCOMPARE(values2[i], results2[i]);
   }

   std::vector<long long> results3 = {1, 3, 5, 7, 9, 11, 13};
   std::vector<unsigned long long> values3 = discreteLogarithm2(5, 5, 15);
   for(unsigned long long i = 0; i <  1; i++) {
     QCOMPARE(values3[i], results3[i]);
   }

   std::vector<long long> results4 = {10, 30, 50, 70, 90, 110, 130};
   std::vector<unsigned long long> values4 = discreteLogarithm2(12, 24, 150);
   for(unsigned long long i = 0; i <  1; i++) {
     QCOMPARE(values4[i], results4[i]);
   }

   std::vector<long long> results5 = {2};
   std::vector<unsigned long long> values5 = discreteLogarithm2(5, 4, 7);
   for(unsigned long long i = 0; i < 1; i++) {
     QCOMPARE(values5[i], results5[i]);
   }

   std::vector<long long> results6 = {0, 2, 4};
   std::vector<unsigned long long> values6 = discreteLogarithm2(2, 1, 6);
   for(unsigned long long i = 0; i < 1; i++) {
     QCOMPARE(values6[i], results6[i]);
   }

   std::vector<long long> results7 = {13415, 31178, 48941 };
   std::vector<unsigned long long> values7 = discreteLogarithm2(100, 256, 1000013);
   for(unsigned long long i = 0; i < 1; i++) {
     QCOMPARE(values7[i], values7[i]);
   }

   std::vector<long long> results8 = {54580};
   std::vector<unsigned long long> values8 = discreteLogarithm2(2, 100, 100003);
   for (unsigned long long i = 0; i < 1; i++)
   {
       QCOMPARE(values8[i], results8[i]);
   }

   std::vector<long long> results9 = {124428, 390366};
   std::vector<unsigned long long> values9 = discreteLogarithm2(25, 256, 531877);
   for (unsigned long long i = 0; i < 1; i++)
   {
       QCOMPARE(results9[i], values9[i]);
   }
}
QTEST_APPLESS_MAIN(DiscreteLogarithm)

#include "tst_discretelogarithm.moc"

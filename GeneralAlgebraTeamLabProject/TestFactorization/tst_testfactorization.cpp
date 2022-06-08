#include <QtTest>

// add necessary includes here
#include "task5/pollardfactorization.h"
#include <algorithm>

class TestFactorization : public QObject
{
    Q_OBJECT

public:
    TestFactorization();
    ~TestFactorization();

private slots:
    void test_case1();
    void test_case2();

};

TestFactorization::TestFactorization()
{

}

TestFactorization::~TestFactorization()
{

}

void TestFactorization::test_case1()
{
    std::map<long long, int> pn1 = PollardFactorization::factorize(91);
    std::map<long long, int> ans1{std::pair(7, 1), std::pair(13, 1)};
    QCOMPARE(ans1, pn1);

    std::map<long long, int> pn2 = PollardFactorization::factorize(4642135);
    std::map<long long, int> ans2{std::pair(5, 1), std::pair(928427, 1)};
    QCOMPARE(ans2, pn2);

    std::map<long long, int> pn3 = PollardFactorization::factorize(4641);
    std::map<long long, int> ans3{std::pair(3, 1), std::pair(7, 1), std::pair(13, 1), std::pair(17, 1)};
    QCOMPARE(ans3, pn3);

    std::map<long long, int> pn4 = PollardFactorization::factorize(12);
    std::map<long long, int> ans4{std::pair(3, 1), std::pair(2, 2)};
    QCOMPARE(ans4, pn4);
}

void TestFactorization::test_case2()
{
    for (long long i = 2; i <= 100000; ++i) {
        bool isExceptionThrown = false;
        try {
            std::map<long long, int> pn = PollardFactorization::factorize(i);
        } catch(std::exception& e) {
            isExceptionThrown = true;
        }
        QVERIFY(!isExceptionThrown);
    }
}

QTEST_APPLESS_MAIN(TestFactorization)

#include "tst_testfactorization.moc"

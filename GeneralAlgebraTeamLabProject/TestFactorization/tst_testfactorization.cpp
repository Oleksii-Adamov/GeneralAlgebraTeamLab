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

};

TestFactorization::TestFactorization()
{

}

TestFactorization::~TestFactorization()
{

}

void TestFactorization::test_case1()
{
    std::vector<int> pn1 = PollardFactorization().factorize(91);
    std::vector<int> ans1{7, 13};
    QCOMPARE(ans1, pn1);

    std::vector<int> pn2 = PollardFactorization().factorize(4642135);
    std::vector<int> ans2{5, 928427};
    QCOMPARE(ans2, pn2);

    std::vector<int> pn3 = PollardFactorization().factorize(4641);
    std::vector<int> ans3{3, 7, 13, 17};
    QCOMPARE(ans3, pn3);
}

QTEST_APPLESS_MAIN(TestFactorization)

#include "tst_testfactorization.moc"

#include <QtTest>

// add necessary includes here
#include "task6/squareroot.h"

class TestSquareRoot : public QObject
{
    Q_OBJECT

public:
    TestSquareRoot();
    ~TestSquareRoot();

private slots:
    void test_case_sqrt();

};

TestSquareRoot::TestSquareRoot()
{

}

TestSquareRoot::~TestSquareRoot()
{

}

void TestSquareRoot::test_case_sqrt()
{
    SquareRoot test_sqrt;
    QCOMPARE(test_sqrt.sqrt(0), 0);
    QCOMPARE(test_sqrt.sqrt(4), 2);
    QCOMPARE(test_sqrt.sqrt(16), 4);
}

QTEST_APPLESS_MAIN(TestSquareRoot)

#include "tst_testsquareroot.moc"

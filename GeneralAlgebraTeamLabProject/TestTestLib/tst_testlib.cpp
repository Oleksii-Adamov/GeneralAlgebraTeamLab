#include <QtTest>

// add necessary includes here
#include "testlib.h"

class TestTestLib : public QObject
{
    Q_OBJECT

public:
    TestTestLib();
    ~TestTestLib();

private slots:
    void test_case1();

};

TestTestLib::TestTestLib()
{

}

TestTestLib::~TestTestLib()
{

}

void TestTestLib::test_case1()
{
    TestLib a;
    QCOMPARE(a.get_i(), 0);
    a.set_i(1);
    QCOMPARE(a.get_i(), 1);
}

QTEST_APPLESS_MAIN(TestTestLib)

#include "tst_testlib.moc"

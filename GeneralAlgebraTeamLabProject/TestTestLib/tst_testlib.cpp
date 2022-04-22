#include <QtTest>

// add necessary includes here
#include "testlib.h"
#include "testFolder/testfolderclass.h"

class TestTestLib : public QObject
{
    Q_OBJECT

public:
    TestTestLib();
    ~TestTestLib();

private slots:
    void test_case1();
    void test_case2();
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

void TestTestLib::test_case2()
{
    testFolderClass a;
    QCOMPARE(a.test_method(), 2);
}

QTEST_APPLESS_MAIN(TestTestLib)

#include "tst_testlib.moc"

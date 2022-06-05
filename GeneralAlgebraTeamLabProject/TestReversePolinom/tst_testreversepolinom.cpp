#include <QtTest>

// add necessary includes here

class TestReversePolinom : public QObject
{
    Q_OBJECT

public:
    TestReversePolinom();
    ~TestReversePolinom();

private slots:
    void test_case1();

};

TestReversePolinom::TestReversePolinom()
{

}

TestReversePolinom::~TestReversePolinom()
{

}

void TestReversePolinom::test_case1()
{

}

QTEST_APPLESS_MAIN(TestReversePolinom)

#include "tst_testreversepolinom.moc"

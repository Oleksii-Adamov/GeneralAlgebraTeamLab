#include <QTest>

#include "task15/ri.h"

class TestRi : public QObject {
    Q_OBJECT

public:
    TestRi();
    ~TestRi();

private slots:
    void testDegree();
    void testD();
    void testM();
    void testRi();
    void testProductOfCyclotomic();
};

TestRi::TestRi() {}
TestRi::~TestRi() {}

void TestRi::testDegree()
{

}

void TestRi::testD()
{

}

void TestRi::testM()
{

}

void TestRi::testRi()
{

}

void TestRi::testProductOfCyclotomic()
{

}


QTEST_APPLESS_MAIN(TestRi)

#include "tst_ri.moc"

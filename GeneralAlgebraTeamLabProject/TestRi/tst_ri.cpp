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
    QVERIFY(ri(3,7,2).coefficients->size() == 2);
}

void TestRi::testD()
{
    QVERIFY(ri(3,7,2).coefficients->at(0).getValue() == 1);
    QVERIFY(ri(3,7,2).coefficients->at(1).getValue() == 1);
}

void TestRi::testM()
{
    QVERIFY(ri(3,7,2).coefficients->size() == 2);
}

void TestRi::testRi()
{
    QVERIFY(ri(3,7,2).coefficients->at(0).getValue() == 1);
    QVERIFY(ri(3,7,2).coefficients->at(1).getValue() == 1);
}

void TestRi::testProductOfCyclotomic()
{
    QVERIFY(ri(3,7,2).coefficients->at(0).getValue() == 1);
    QVERIFY(ri(3,7,2).coefficients->at(1).getValue() == 1);
}


QTEST_APPLESS_MAIN(TestRi)

#include "tst_ri.moc"

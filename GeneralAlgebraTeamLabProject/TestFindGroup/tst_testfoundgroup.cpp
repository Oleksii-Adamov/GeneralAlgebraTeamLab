#include <QtTest>
#include "task8/findgroup.h"
#include <string>
#include <iostream>

// add necessary includes here

class TestFoundGroup : public QObject
{
    Q_OBJECT

public:
    TestFoundGroup();
    ~TestFoundGroup();

private slots:
    void testfindgroup();
    void testGenerator();

};

TestFoundGroup::TestFoundGroup()
{

}

TestFoundGroup::~TestFoundGroup()
{

}

void TestFoundGroup::testfindgroup()
{
    IntModulo num(2);
    num.pow(17, 204);

//    FindGroup test(15);
//    IntModulo t = test.ElementOrder(7);

    FindGroup group1(15);
    group1.ElementOrder(16);

//    FindGroup group2(15);
//    IntModulo b = group2.ElementOrder(2);
//    IntModulo c = group2.ElementOrder(7);
//    QCOMPARE(a.get_num(), 16);
//    QCOMPARE(b.get_num(), 4);
//    QCOMPARE(c.get_num(), 4);
}
void TestFoundGroup::testGenerator(){
    FindGroup group2(17);
    bool b = group2.FindGroupGenerator(14);
    QVERIFY(b);
}

QTEST_APPLESS_MAIN(TestFoundGroup)

#include "tst_testfoundgroup.moc"

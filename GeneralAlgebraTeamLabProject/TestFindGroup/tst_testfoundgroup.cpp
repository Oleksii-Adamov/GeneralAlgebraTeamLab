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
    FindGroup group1(15);
    IntModulo a = group1.ElementOrder(2);
    IntModulo b = group1.ElementOrder(4);
    IntModulo c = group1.ElementOrder(7);

    FindGroup group2(100003);
    IntModulo a2 = group2.ElementOrder(2);
    IntModulo b2 = group2.ElementOrder(4);
    IntModulo c2 = group2.ElementOrder(50000);

        QCOMPARE(a.get_num(), 4);
        QCOMPARE(b.get_num(), 2);
        QCOMPARE(c.get_num(), 4);

        QCOMPARE(a2.get_num(), 100002);
        QCOMPARE(b2.get_num(), 50001);
        QCOMPARE(c2.get_num(), 33334);

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

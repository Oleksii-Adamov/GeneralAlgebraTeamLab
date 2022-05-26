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
    FindGroup group1(16);
    IntModulo a = group1.ElementOrder(2);

    FindGroup group2(15);
    IntModulo b = group2.ElementOrder(1);
    IntModulo c = group2.ElementOrder(3);
    QCOMPARE(a.get_num(),4);
    QCOMPARE(b.get_num(), 4);
    QCOMPARE(c.get_num(), 4);



}
void TestFoundGroup::testGenerator(){
    FindGroup group2(10);
    bool b = group2.FindGroupGenerator(3);
    QVERIFY(b);
}

QTEST_APPLESS_MAIN(TestFoundGroup)

#include "tst_testfoundgroup.moc"

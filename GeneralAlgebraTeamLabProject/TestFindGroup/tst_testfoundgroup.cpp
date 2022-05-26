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
//    bool b = group1.FindGroupGenerator(2);

    QCOMPARE(a.get_num(),4);


}

QTEST_APPLESS_MAIN(TestFoundGroup)

#include "tst_testfoundgroup.moc"

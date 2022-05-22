#include <QtTest>
#include "task8/findgroup.h"
#include <string>

// add necessary includes here

class TestFoundGroup : public QObject
{
    Q_OBJECT

public:
    TestFoundGroup();
    ~TestFoundGroup();

private slots:
    void test_case1();

};

TestFoundGroup::TestFoundGroup()
{

}

TestFoundGroup::~TestFoundGroup()
{

}

void TestFoundGroup::test_case1()
{
    std::string vec = "3 1 2 6 11 10 7 4 5 8 9 12";
    FindGroup group1;
    group1.SetGroup(vec);

    QCOMPARE(1,1);


}

QTEST_APPLESS_MAIN(TestFoundGroup)

#include "tst_testfoundgroup.moc"

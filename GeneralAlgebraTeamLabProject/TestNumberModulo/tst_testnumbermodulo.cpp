#include <QtTest>

// add necessary includes here
#include "task1/numbermodulo.h"

class TestNumberModulo : public QObject
{
    Q_OBJECT

public:
    TestNumberModulo();
    ~TestNumberModulo();

private slots:
    void test_case_get_modulo();
    void test_case_set_modulo_positive();
    void test_case_set_modulo_non_positive();
    void test_case_get_num();
    void test_case_set_num();

};

TestNumberModulo::TestNumberModulo()
{

}

TestNumberModulo::~TestNumberModulo()
{

}

// get and set tests depend on each other. I don't want to use friend for this.

void TestNumberModulo::test_case_get_num()
{
    NumberModulo test_num;
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(5);
    QCOMPARE(test_num.get_num(), 5);
}

void TestNumberModulo::test_case_set_num()
{
    NumberModulo test_num;
    test_num.set_num(5);
    QCOMPARE(test_num.get_num(), 5);
    test_num.set_num(3);
    QCOMPARE(test_num.get_num(), 3);
    // to do negative (maybe should in different test_case
}

void TestNumberModulo::test_case_get_modulo()
{
    NumberModulo test_num;
    QCOMPARE(test_num.get_modulo(), 2);
    test_num.set_modulo(7);
    QCOMPARE(test_num.get_modulo(), 7);
}
void TestNumberModulo::test_case_set_modulo_positive()
{
    NumberModulo test_num;
    test_num.set_modulo(5);
    QCOMPARE(test_num.get_modulo(), 5);
    test_num.set_modulo(3);
    QCOMPARE(test_num.get_modulo(), 3);
}
void TestNumberModulo::test_case_set_modulo_non_positive()
{
    NumberModulo test_num;
    QVERIFY_THROWS_EXCEPTION( char*, test_num.set_modulo(0));
    QVERIFY_THROWS_EXCEPTION( char*, test_num.set_modulo(-2));
}

QTEST_APPLESS_MAIN(TestNumberModulo)

#include "tst_testnumbermodulo.moc"

#include <QtTest>

// add necessary includes here
#include "task1/intmodulo.h"
#include <stdexcept>

class TestNumberModulo : public QObject
{
    Q_OBJECT

public:
    TestNumberModulo();
    ~TestNumberModulo();

private slots:
    void test_case_get_num();
    void test_case_set_num();
    void test_case_constructor_from_integer();
    void test_case_mod();
    void test_case_constructor_from_integer_modulo();
    void test_case_add();
    void test_case_substract();
    void test_case_multiply();
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
    IntModulo test_num;
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(5);
    QCOMPARE(test_num.get_num(), 5);
}

void TestNumberModulo::test_case_set_num()
{
    IntModulo test_num;
    test_num.set_num(5);
    QCOMPARE(test_num.get_num(), 5);
    test_num.set_num(3);
    QCOMPARE(test_num.get_num(), 3);
    test_num.set_num(-2);
    QCOMPARE(test_num.get_num(), -2);
}

void TestNumberModulo::test_case_constructor_from_integer()
{
    IntModulo test_num1(5);
    QCOMPARE(test_num1.get_num(), 5);
    IntModulo test_num2(3);
    QCOMPARE(test_num2.get_num(), 3);
    IntModulo test_num3(-2);
    QCOMPARE(test_num3.get_num(), -2);
}
void TestNumberModulo::test_case_mod()
{
    IntModulo test_num;
    // zero mod
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.mod(0));
    // comment for merge test
    // positive num
    test_num.set_num(5);
    test_num.mod(2);
    QCOMPARE(test_num.get_num(), 1);
    test_num.set_num(7);
    test_num.mod(5);
    QCOMPARE(test_num.get_num(), 2);
    test_num.set_num(7);
    test_num.mod(10);
    QCOMPARE(test_num.get_num(), 7);
    test_num.set_num(3);
    test_num.mod(3);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(12);
    test_num.mod(4);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(13);
    test_num.mod(1);
    QCOMPARE(test_num.get_num(), 0);
    // negative num
    test_num.set_num(-5);
    test_num.mod(2);
    QCOMPARE(test_num.get_num(), 1);
    test_num.set_num(-7);
    test_num.mod(5);
    QCOMPARE(test_num.get_num(), 3);
    test_num.set_num(-3);
    test_num.mod(3);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(-12);
    test_num.mod(4);
    QCOMPARE(test_num.get_num(), 0);
    // zero num
    test_num.set_num(0);
    test_num.mod(3);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(0);
    test_num.mod(5);
    QCOMPARE(test_num.get_num(), 0);
}

void TestNumberModulo::test_case_constructor_from_integer_modulo()
{
    // zero mod
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, IntModulo(3, 0));
    // postive mod
    // positive num
    IntModulo test_num1(5, 2);
    QCOMPARE(test_num1.get_num(), 1);
    // zero num
    IntModulo test_num2(0, 3);
    QCOMPARE(test_num2.get_num(), 0);
}

void TestNumberModulo::test_case_add()
{
     IntModulo test_num;
     test_num.set_num(3);
     test_num.add(IntModulo(2), 2);
     QCOMPARE(test_num.get_num(), 1);
     test_num.add(IntModulo(5), 6);
     QCOMPARE(test_num.get_num(), 0);
     test_num.add(IntModulo(-7), 5);
     QCOMPARE(test_num.get_num(), 3);
     test_num.add(IntModulo(0), 5);
     QCOMPARE(test_num.get_num(), 3);
     test_num.add(IntModulo(0), 2);
     QCOMPARE(test_num.get_num(), 1);
}

void TestNumberModulo::test_case_substract()
{
    IntModulo test_num;
    test_num.set_num(5);
    test_num.substract(IntModulo(3), 2);
    QCOMPARE(test_num.get_num(), 0);
    test_num.substract(IntModulo(7), 5);
    QCOMPARE(test_num.get_num(), 3);
    test_num.substract(IntModulo(0), 5);
    QCOMPARE(test_num.get_num(), 3);
    test_num.substract(IntModulo(0), 3);
    QCOMPARE(test_num.get_num(), 0);
}

void TestNumberModulo::test_case_multiply()
{
    IntModulo test_num;
    test_num.set_num(5);
    test_num.multiply(5, 7);
    QCOMPARE(test_num.get_num(), 4);
    test_num.multiply(4, 16);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(5);
    test_num.multiply(-2, 3);
    QCOMPARE(test_num.get_num(), 2);
    test_num.multiply(12, 7);
    QCOMPARE(test_num.get_num(), 3);
    test_num.multiply(0, 7);
    QCOMPARE(test_num.get_num(), 0);
    test_num.multiply(5, 7);
    QCOMPARE(test_num.get_num(), 0);
}

QTEST_APPLESS_MAIN(TestNumberModulo)

#include "tst_testnumbermodulo.moc"

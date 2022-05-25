#include <QtTest>

#include "task11/polinome.h"
#include "task13/polinome_division.h"
#include "task20/generator.h"

class TestGenerator : public QObject{
    Q_OBJECT

public:
    TestGenerator();
    ~TestGenerator();

private slots:
    void testOrder();
    void testDegree();
    void testMaxOrder();
    void testIsGenerator();
};

TestGenerator::TestGenerator() {}

TestGenerator::~TestGenerator() {}


void TestGenerator::testOrder() {
    // QCOMPARE(orderOfPolinome(3, Polinome("x^2 + 1"), Polinome("x")), 4)
    QCOMPARE(1,1);
}

void TestGenerator::testDegree() {
    QCOMPARE(1,2);
}

void TestGenerator::testMaxOrder() {
}

void TestGenerator::testIsGenerator() {
}

QTEST_APPLESS_MAIN(TestGenerator)

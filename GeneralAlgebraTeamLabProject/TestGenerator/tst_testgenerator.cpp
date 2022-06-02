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
    int answer = orderOfPolinome(3, Polinome("x^2 + 1"), Polinome("x") );
    int answer2 = orderOfPolinome(3, Polinome("x^2 + 1"), Polinome("2x + 1") );
    int answer3 = orderOfPolinome(7, Polinome("x^2 + 1"), Polinome("x^4 + x + 1") );
    int answer4 = orderOfPolinome(5, Polinome("x^2 + 1"), Polinome("x^3"));
    int answer5 = orderOfPolinome(5, Polinome("x^2 + 3x + 3"), Polinome("x"));
    int answer6 = orderOfPolinome(7, Polinome("x^2 + 1"), Polinome("x^4 + x + 1"));

    QCOMPARE(answer, 4);
    QCOMPARE(answer2, 8);
    QCOMPARE(answer3, 48);
    QCOMPARE(answer4, 4);
    QCOMPARE(answer5, 24);
    QCOMPARE(answer6, 48);
}

void TestGenerator::testDegree() {
    auto p = Polinome("x");
    auto p1 = Polinome("x^4");
    auto p2 = Polinome("x^2 + 1");
    auto p3 = Polinome("x^2 + x + 1");

    QCOMPARE(degreeOfPolinome(p1), 4);
    QCOMPARE(degreeOfPolinome(p2), 2);
    QCOMPARE(degreeOfPolinome(p), 1);
    QCOMPARE(degreeOfPolinome(p3), 2);
}

void TestGenerator::testMaxOrder() {
    auto p2 = Polinome("x^2 + 1");

    QCOMPARE(maxOrderOfPolinome(3, p2), 8);
}

void TestGenerator::testIsGenerator() {
    auto p2 = Polinome("x^2 + 1");
    auto p1 = Polinome("x");
    auto p3 = Polinome("2x + 1");

    QCOMPARE(isGenerator(3, p2, p1), false);
    QCOMPARE(isGenerator(3, p2, p3), true);
}

QTEST_APPLESS_MAIN(TestGenerator)

#include "tst_testgenerator.moc"

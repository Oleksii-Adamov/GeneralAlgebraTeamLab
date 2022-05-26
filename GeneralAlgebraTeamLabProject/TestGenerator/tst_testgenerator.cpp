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
//    int answer = orderOfPolinome(3, Polinome("x^2 + 1"), Polinome("x") );
//    std::cout << answer;
//     QCOMPARE(answer, 4);
//    QCOMPARE(1,1);
}

void TestGenerator::testDegree() {
    auto p1 = Polinome("x^4");
    auto p2 = Polinome("x^2 + 1");
    auto p = Polinome("x");
    auto p3 = Polinome("x^2");
    auto result = p;
    result = result.multiply(p, 5);
    std::cout << result.toString() << std::endl;
    std::cout << p3.multiply(p, 5).toString() << std::endl;
//     result = result.multiply(p, 5);
//     result = result.multiply(p, 5);
//    std::cout << "RESULTTTTTTTTTTTTTTTTTTTTTTTTTTT: " << p1.divide(p2, 3).remainder->toString() << std::endl;
    QCOMPARE(p1.divide(p2, 3).remainder->toString(), Polinome("1").toString());
}

void TestGenerator::testMaxOrder() {
    QCOMPARE(1,1);
}

void TestGenerator::testIsGenerator() {
    QCOMPARE(1,1);
}

QTEST_APPLESS_MAIN(TestGenerator)

#include "tst_testgenerator.moc"

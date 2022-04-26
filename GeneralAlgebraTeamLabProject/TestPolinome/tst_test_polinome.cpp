#include <QTest>

#include "task11/polinome.h"
#include <stdexcept>

class TestPolinome : public QObject {
    Q_OBJECT

public:
    TestPolinome();
    ~TestPolinome();

private slots:
    void testPolinomeParsing();
    void testPolinomeAddition();
    void testPolinomeSubtraction();
    void testPolinomeMultiplication();

};

TestPolinome::TestPolinome() {}

TestPolinome::~TestPolinome() {}

void TestPolinome::testPolinomeParsing() {
    std::vector<IntModulo> coefficientsVector;
    coefficientsVector.emplace_back(IntModulo(1));
    coefficientsVector.emplace_back(IntModulo(2));
    QCOMPARE(Polinome(coefficientsVector), Polinome("1 + 2x"));

    coefficientsVector.clear();
    coefficientsVector.emplace_back(IntModulo(1));
    coefficientsVector.emplace_back(IntModulo(0));
    coefficientsVector.emplace_back(IntModulo(3));
    coefficientsVector.emplace_back(IntModulo(2));
    QCOMPARE(Polinome(coefficientsVector), Polinome("  1 + 3x^2 +   2x ^3 "));

    coefficientsVector.clear();
    coefficientsVector.emplace_back(IntModulo(321));
    coefficientsVector.emplace_back(IntModulo(22));
    coefficientsVector.emplace_back(IntModulo(3));
    coefficientsVector.emplace_back(IntModulo(0));
    coefficientsVector.emplace_back(IntModulo(35));
    QCOMPARE(Polinome(coefficientsVector), Polinome("3x^ 2 + 35  x ^ 4   + 22 x  + 321"));
}

void TestPolinome::testPolinomeAddition() {
    QCOMPARE(Polinome("1 + 2x").add(Polinome("2 + 3x"), 6), Polinome("3 + 5x"));
    QCOMPARE(Polinome("1 + 2x").add(Polinome("2 + 3x"), 5), Polinome("3"));
    QCOMPARE(Polinome("1 + 2x").add(Polinome("2"), 5), Polinome("3 + 2x"));
    QCOMPARE(Polinome("1").add(Polinome("3x + 4x^2"), 5), Polinome("1 + 3x + 4x^2"));
    QCOMPARE(Polinome("1 + 2x").add(Polinome("2 + x"), 3), Polinome("0"));
}

void TestPolinome::testPolinomeSubtraction() {
    QCOMPARE(Polinome("2 + 2x").subtract(Polinome("1 + x"), 6), Polinome("1 + x"));
    QCOMPARE(Polinome("1 + x").subtract(Polinome("2 + 2x"), 5), Polinome("4 + 4x"));
    QCOMPARE(Polinome("1").subtract(Polinome("2 + 2x"), 5), Polinome("4 + 3x"));
    QCOMPARE(Polinome("1 + x").subtract(Polinome("4x"), 5), Polinome("1 + 2x"));
    QCOMPARE(Polinome("1 + x").subtract(Polinome("1 + x"), 5), Polinome("0"));
}

void TestPolinome::testPolinomeMultiplication() {
    QCOMPARE(Polinome("1").multiply(Polinome("1"), 6), Polinome("1"));
    QCOMPARE(Polinome("1 + x").multiply(Polinome("1 + x"), 6), Polinome("1 + 2x + x^2"));
    QCOMPARE(Polinome("1").multiply(Polinome("1 + x"), 6), Polinome("1 + x"));
    QCOMPARE(Polinome("1 + x").multiply(Polinome("1"), 6), Polinome("1 + x"));
    QCOMPARE(Polinome("x + 2").multiply(Polinome("x^2 + 3x + 4"), 6), Polinome("x^3 + 5x^2 + 4x + 2"));
    QCOMPARE(Polinome("x^2 + 3x + 4").multiply(Polinome("x + 2"), 6), Polinome("x^3 + 5x^2 + 4x + 2"));
}

QTEST_APPLESS_MAIN(TestPolinome)

#include "tst_test_polinome.moc"

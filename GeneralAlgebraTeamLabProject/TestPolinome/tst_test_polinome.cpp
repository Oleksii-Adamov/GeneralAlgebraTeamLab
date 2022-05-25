#include <QTest>

#include "task11/polinome.h"
#include "task13/polinome.hpp"
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
    void testPolinomeToString();

    // Task12 tests
    void testPolinomeDerivative();
    void testPolinomeEvaluate();

    // Task13 tests
    void testPolinomeDivision();
};

TestPolinome::TestPolinome() {}

TestPolinome::~TestPolinome() {}

void TestPolinome::testPolinomeParsing() {
    std::vector<IntModulo>* coefficientsVector = new std::vector<IntModulo>();
    coefficientsVector->emplace_back(IntModulo(1));
    coefficientsVector->emplace_back(IntModulo(2));
    std::string writtenPolinome = "1 + 2x";
    QCOMPARE(Polinome(coefficientsVector), Polinome(writtenPolinome));

    coefficientsVector = new std::vector<IntModulo>();
    coefficientsVector->emplace_back(IntModulo(1));
    coefficientsVector->emplace_back(IntModulo(0));
    coefficientsVector->emplace_back(IntModulo(3));
    coefficientsVector->emplace_back(IntModulo(2));
    writtenPolinome = "  1 + 3x^2 +   2x ^3 ";
    QCOMPARE(Polinome(coefficientsVector), Polinome(writtenPolinome));

    coefficientsVector = new std::vector<IntModulo>();
    coefficientsVector->emplace_back(IntModulo(321));
    coefficientsVector->emplace_back(IntModulo(22));
    coefficientsVector->emplace_back(IntModulo(3));
    coefficientsVector->emplace_back(IntModulo(0));
    coefficientsVector->emplace_back(IntModulo(35));
    writtenPolinome = "3x^ 2 + 35  x ^ 4   + 22 x  + 321";
    QCOMPARE(Polinome(coefficientsVector), Polinome(writtenPolinome));

    bool caught = false;
    try {
        writtenPolinome = "3x^ 2 + 35  x ^ 4 + 11x  + 22 x  + 321 + 11";
        Polinome p = Polinome(writtenPolinome);
        qDebug() << p.toString().c_str();
    } catch(const std::exception& e) {
        caught = true;
    }
    QVERIFY(caught);

    caught = false;
    try {
        writtenPolinome = "3x^ 2 + 35  x ^ 4 + 22 x  + 321 + 11";
        Polinome p = Polinome(writtenPolinome);
        qDebug() << p.toString().c_str();
    } catch(const std::exception& e) {
        caught = true;
    }
    QVERIFY(caught);

    caught = false;
    try {
        writtenPolinome = "3x^ 2 + 35  x ^ 4 + 11x  + 22 x  + 321";
        Polinome p = Polinome(writtenPolinome);
        qDebug() << p.toString().c_str();
    } catch(const std::exception& e) {
        caught = true;
    }
    QVERIFY(caught);
}

void TestPolinome::testPolinomeAddition() {
    std::string writtenAddend1 = "1 + 2x";
    std::string writtenAddend2 = "2 + 3x";
    std::string result = "3 + 5x";
    QCOMPARE(Polinome(writtenAddend1).add(Polinome(writtenAddend2), 6), Polinome(result));

    writtenAddend1 = "1 + 2x";
    writtenAddend2 = "2 + 3x";
    result = "3";
    QCOMPARE(Polinome(writtenAddend1).add(Polinome(writtenAddend2), 5), Polinome(result));

    writtenAddend1 = "1 + 2x";
    writtenAddend2 = "2";
    result = "3 + 2x";
    QCOMPARE(Polinome(writtenAddend1).add(Polinome(writtenAddend2), 5), Polinome(result));

    writtenAddend1 = "1";
    writtenAddend2 = "3x + 4x^2";
    result = "1 + 3x + 4x^2";
    QCOMPARE(Polinome(writtenAddend1).add(Polinome(writtenAddend2), 5), Polinome(result));

    writtenAddend1 = "1 + 2x";
    writtenAddend2 = "2 + x";
    result = "0";
    QCOMPARE(Polinome(writtenAddend1).add(Polinome(writtenAddend2), 3), Polinome(result));
}

void TestPolinome::testPolinomeSubtraction() {
    std::string writtenMinuend = "2 + 2x";
    std::string writtenSubtrahend = "1 + x";
    std::string result = "1 + x";


    QCOMPARE(Polinome(writtenMinuend).subtract(Polinome(writtenSubtrahend), 6), Polinome(result));

    writtenMinuend = "1 + x";
    writtenSubtrahend = "2 + 2x";
    result = "4 + 4x";
    QCOMPARE(Polinome(writtenMinuend).subtract(Polinome(writtenSubtrahend), 5), Polinome(result));

    writtenMinuend = "1";
    writtenSubtrahend = "2 + 2x";
    result = "4 + 3x";
    QCOMPARE(Polinome(writtenMinuend).subtract(Polinome(writtenSubtrahend), 5), Polinome(result));

    writtenMinuend = "1 + x";
    writtenSubtrahend = "4x";
    result = "1 + 2x";
    QCOMPARE(Polinome(writtenMinuend).subtract(Polinome(writtenSubtrahend), 5), Polinome(result));

    writtenMinuend = "1 + x";
    writtenSubtrahend = "1 + x";
    result = "0";
    QCOMPARE(Polinome(writtenMinuend).subtract(Polinome(writtenSubtrahend), 5), Polinome(result));
}

void TestPolinome::testPolinomeMultiplication() {
    std::string writtenFactor1 = "1";
    std::string writtenFactor2 = "1";
    std::string result = "1";
    QCOMPARE(Polinome(writtenFactor1).multiply(Polinome(writtenFactor2), 6), Polinome(result));

    writtenFactor1 = "1 + x";
    writtenFactor2 = "1 + x";
    result = "1 + 2x + x^2";
    QCOMPARE(Polinome(writtenFactor1).multiply(Polinome(writtenFactor2), 6), Polinome(result));

    writtenFactor1 = "1";
    writtenFactor2 = "1 + x";
    result = "1 + x";
    QCOMPARE(Polinome(writtenFactor1).multiply(Polinome(writtenFactor2), 6), Polinome(result));

    writtenFactor1 = "1 + x";
    writtenFactor2 = "1";
    result = "1 + x";
    QCOMPARE(Polinome(writtenFactor1).multiply(Polinome(writtenFactor2), 6), Polinome(result));

    writtenFactor1 = "x + 2";
    writtenFactor2 = "x^2 + 3x + 4";
    result = "x^3 + 5x^2 + 4x + 2";
    QCOMPARE(Polinome(writtenFactor1).multiply(Polinome(writtenFactor2), 6), Polinome(result));

    writtenFactor1 = "x^2 + 3x + 4";
    writtenFactor2 = "x + 2";
    result = "x^3 + 5x^2 + 4x + 2";
    QCOMPARE(Polinome(writtenFactor1).multiply(Polinome(writtenFactor2), 6), Polinome(result));
}

void TestPolinome::testPolinomeToString() {
    std::string writtenPolinome = "2x + 1";
    QCOMPARE(writtenPolinome, Polinome(writtenPolinome).toString());

    writtenPolinome = "1";
    QCOMPARE(writtenPolinome, Polinome(writtenPolinome).toString());

    writtenPolinome = "0";
    QCOMPARE(writtenPolinome, Polinome(writtenPolinome).toString());

    writtenPolinome = "2x^2 + x + 150";
    QCOMPARE(writtenPolinome, Polinome(writtenPolinome).toString());

    writtenPolinome = "15x^4 + 2x^2 + x + 150";
    QCOMPARE(writtenPolinome, Polinome(writtenPolinome).toString());

    writtenPolinome = "2x + 1 -";
    bool caught = false;
    try {
        Polinome(writtenPolinome).toString();
    } catch (const std::exception& e) {
        caught = true;
    }
    QVERIFY(caught);

    writtenPolinome = "3xx + 1";
    caught = false;
    try {
        Polinome(writtenPolinome).toString();
    } catch (const std::exception& e) {
        caught = true;
    }
    QVERIFY(caught);

    writtenPolinome = "3xxx + 1";
    caught = false;
    try {
        Polinome(writtenPolinome).toString();
    } catch (const std::exception& e) {
        caught = true;
    }
    QVERIFY(caught);
}

// Task12 tests
void TestPolinome::testPolinomeDerivative() {
   std::string writtenPolinome = "1 + 2x";
   std::string writtenPolinomeDerivative = "2";

   QCOMPARE(Polinome(writtenPolinome).derivative(6), Polinome(writtenPolinomeDerivative));

   writtenPolinome = "1";
   writtenPolinomeDerivative = "0";
   QCOMPARE(Polinome(writtenPolinome).derivative(6), Polinome(writtenPolinomeDerivative));

   writtenPolinome = "150 + x + 7x^2";
   writtenPolinomeDerivative = "1 + 2x";
   QCOMPARE(Polinome(writtenPolinome).derivative(6), Polinome(writtenPolinomeDerivative));

   writtenPolinome = "150 + x + 2x^2";
   writtenPolinomeDerivative = "1 + 4x";
   QCOMPARE(Polinome(writtenPolinome).derivative(6), Polinome(writtenPolinomeDerivative));

   writtenPolinome = "5x^3 + 3x + 150 + 9x^5";
   writtenPolinomeDerivative = "3x^4 + 3x^2 + 3";

   QCOMPARE(Polinome(writtenPolinome).derivative(6), Polinome(writtenPolinomeDerivative));
}

void TestPolinome::testPolinomeEvaluate() {
   QCOMPARE(Polinome("1 + 2x").evaluate(IntModulo(50), 30).get_num(), 11);
   QCOMPARE(Polinome("").evaluate(IntModulo(14), 15).get_num(), 0);
   QCOMPARE(Polinome("8x^2 + 3x + 9").evaluate(IntModulo(4), 24).get_num(), 5);
   QCOMPARE(Polinome("4x^3 + 8x^2 + 2x + 2").evaluate(IntModulo(5), 23).get_num(), 22);
   QCOMPARE(Polinome("8x^6 + 8x^5 + 2x^4 + 3x^3 + 1x^2 + 1x + 8").evaluate(IntModulo(15), 22).get_num(), 13);
   QCOMPARE(Polinome("5x^8 + 3x^7 + 6x^6 + 9x^5 + 2x^4 + 4x^3 + 3x + 4").evaluate(IntModulo(21), 13).get_num(), 6);
   QCOMPARE(Polinome("9x^8 + 4x^6 + 8x^5 + 9x^4 + 7x^3 + 2x^2 + 6x + 7").evaluate(IntModulo(12), 35).get_num(), 8);
   QCOMPARE(Polinome("1x^2 + 9x + 8").evaluate(IntModulo(16), 3).get_num(), 0);
   QCOMPARE(Polinome("4x^6 + 4x^5 + 1x^4 + 1x^3 + 7x^2 + 3").evaluate(IntModulo(14), 33).get_num(), 25);
   QCOMPARE(Polinome("4x^4 + 6x^3 + 4x^2 + 6x + 6").evaluate(IntModulo(13), 37).get_num(), 18);
   QCOMPARE(Polinome("1x^7 + 4x^6 + 5x^5 + 9x^3 + 6x^2 + 2x + 9").evaluate(IntModulo(28), 27).get_num(), 9);
   QCOMPARE(Polinome("5x^7 + 5x^6 + 2x^5 + 6x^4 + 5x^3 + 5x^2 + 2x + 6").evaluate(IntModulo(2), 36).get_num(), 2);
   QCOMPARE(Polinome("2x^2 + 3x").evaluate(IntModulo(11), 6).get_num(), 5);
   QCOMPARE(Polinome("7x^2 + 5x + 8").evaluate(IntModulo(18), 29).get_num(), 17);
   QCOMPARE(Polinome("5x^6 + 8x^5 + 3x^4 + 1x^2 + 4x + 9").evaluate(IntModulo(13), 32).get_num(), 30);
   QCOMPARE(Polinome("8").evaluate(IntModulo(24), 37).get_num(), 8);
   QCOMPARE(Polinome("5x^7 + 7x^6 + 3x^4 + 2x^3 + 4x^2 + 9x + 6").evaluate(IntModulo(17), 12).get_num(), 4);
   QCOMPARE(Polinome("3").evaluate(IntModulo(9), 35).get_num(), 3);
   QCOMPARE(Polinome("").evaluate(IntModulo(24), 15).get_num(), 0);
   QCOMPARE(Polinome("9x^6 + 1x^5 + 5x^4 + 8x^3 + 1x^2 + 9x + 8").evaluate(IntModulo(11), 15).get_num(), 11);
   QCOMPARE(Polinome("1x^2 + 1x + 6").evaluate(IntModulo(27), 2).get_num(), 0);
   QCOMPARE(Polinome("9x^7 + 5x^6 + 5x^5 + 6x^4 + 1x^3 + 8x^2 + 9x + 6").evaluate(IntModulo(27), 8).get_num(), 1);
   QCOMPARE(Polinome("2x^3 + 4x^2 + 3x + 6").evaluate(IntModulo(28), 4).get_num(), 2);
   QCOMPARE(Polinome("1x^7 + 2x^6 + 7x^5 + 5x^4 + 8x^3 + 9x^2 + 8x + 9").evaluate(IntModulo(29), 20).get_num(), 1);
   QCOMPARE(Polinome("3x^2 + 1x + 6").evaluate(IntModulo(25), 2).get_num(), 0);
   QCOMPARE(Polinome("1x^8 + 5x^7 + 4x^6 + 5x^5 + 1x^4 + 8x^3 + 7x^2 + 6x + 8").evaluate(IntModulo(5), 29).get_num(), 0);
   QCOMPARE(Polinome("2x^8 + 5x^7 + 6x^6 + 9x^5 + 7x^4 + 4x^3 + 7x^2 + 3x").evaluate(IntModulo(5), 21).get_num(), 7);
   QCOMPARE(Polinome("3x^7 + 9x^5 + 9x^4 + 4x^3 + 1x^2 + 7x + 5").evaluate(IntModulo(25), 7).get_num(), 0);
   QCOMPARE(Polinome("1x^2 + 7x").evaluate(IntModulo(1), 27).get_num(), 8);
   QCOMPARE(Polinome("7x^3 + 2x^2 + 5x + 4").evaluate(IntModulo(26), 17).get_num(), 10);
}

void TestPolinome::testPolinomeDivision() {
    auto r1 = Polinome("x^3 - 12x^2 + 38x - 17").divide(Polinome("x - 7"));
    QCOMPARE(r1.quotient, Polinome("x^2 - 5x + 3"));
    QCOMPARE(r1.remainder, Polinome("4"));

    auto r2 = Polinome("x^2 + x + 5").divide(Polinome("x + 2"));
    QCOMPARE(r2.quotient, Polinome("1"));
    QCOMPARE(r2.remainder, Polinome("x + 3"));
}

QTEST_APPLESS_MAIN(TestPolinome)

#include "tst_test_polinome.moc"

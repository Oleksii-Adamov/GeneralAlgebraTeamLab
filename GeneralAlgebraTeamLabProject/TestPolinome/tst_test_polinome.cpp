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
    void testPolinomeToString();

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
    } catch(std::exception e) {
        caught = true;
    }
    QVERIFY(caught);

    caught = false;
    try {
        writtenPolinome = "3x^ 2 + 35  x ^ 4 + 22 x  + 321 + 11";
        Polinome p = Polinome(writtenPolinome);
        qDebug() << p.toString().c_str();
    } catch(std::exception e) {
        caught = true;
    }
    QVERIFY(caught);

    caught = false;
    try {
        writtenPolinome = "3x^ 2 + 35  x ^ 4 + 11x  + 22 x  + 321";
        Polinome p = Polinome(writtenPolinome);
        qDebug() << p.toString().c_str();
    } catch(std::exception e) {
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
}

QTEST_APPLESS_MAIN(TestPolinome)

#include "tst_test_polinome.moc"

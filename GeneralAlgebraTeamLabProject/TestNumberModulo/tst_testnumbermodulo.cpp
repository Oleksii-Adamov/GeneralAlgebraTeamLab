#include <QtTest>

#include "task1/intmodulo.h"
#include <stdexcept>
#include <sstream>
#include "task6/sqrt.h"

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
    void test_case_subtract();
    void test_case_multiply();
    void test_case_divide();
    void test_case_findReversed();
    void test_case_pow();
    void test_case_sqrt();
    void test_case_copy_constructor();
    void test_case_copy_assignment_operator();
    void test_case_ToString();
    void test_case_in_stream();
    void test_case_FromString();
    void test_case_isPrime();
    void test_case_isPrime_helper(int optimal_iterations_num);
    void test_case_comparision_operators();
    void test_case_phi();    
    void test_case_carmichael();
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
    // zero modulo
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.mod(0));
    // postive modulo
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
    // zero modulo
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, IntModulo(3, 0));
    // postive modulo
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

void TestNumberModulo::test_case_subtract()
{
    IntModulo test_num;
    test_num.set_num(5);
    test_num.subtract(IntModulo(3), 2);
    QCOMPARE(test_num.get_num(), 0);
    test_num.subtract(IntModulo(7), 5);
    QCOMPARE(test_num.get_num(), 3);
    test_num.subtract(IntModulo(0), 5);
    QCOMPARE(test_num.get_num(), 3);
    test_num.subtract(IntModulo(0), 3);
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
void TestNumberModulo::test_case_divide()
{
    IntModulo test_num;
    test_num.set_num(3);
    test_num.divide(IntModulo(3), 26);
    QCOMPARE(test_num.get_num(), 1);
    test_num.divide(5, 16);
    QCOMPARE(test_num.get_num(), 13);
    test_num.set_num(7);
    test_num.divide(8, 3);
    QCOMPARE(test_num.get_num(), 2);
    test_num.set_num(56);
    test_num.divide(34, 67);
    QCOMPARE(test_num.get_num(), 45);
    test_num.set_num(246);
    test_num.divide(3, 56);
    QCOMPARE(test_num.get_num(), 26);
    test_num.set_num(246);
    test_num.divide(1, 56);
    QCOMPARE(test_num.get_num(), 22);

    //zero
    test_num.set_num(0);
    test_num.divide(3, 56);
    QCOMPARE(test_num.get_num(), 0);

    // no reverse
    test_num.set_num(4);
    QVERIFY_THROWS_EXCEPTION(std::logic_error, test_num.divide(4, 10));
}
void TestNumberModulo::test_case_findReversed()
{
    IntModulo test_num;
    test_num.set_num(3);
    test_num = test_num.findReversed(26);
    QCOMPARE(test_num.get_num(), 9);
    test_num.set_num(147);
    test_num = test_num.findReversed(53);
    QCOMPARE(test_num.get_num(), 22);
    test_num.set_num(454);
    test_num = test_num.findReversed(21);
    QCOMPARE(test_num.get_num(), 13);
    test_num.set_num(0);
    // no reverse
    test_num = test_num.findReversed(1);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(2);
    test_num = test_num.findReversed(0);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(1);
    test_num = test_num.findReversed(1);
    QCOMPARE(test_num.get_num(), 0);
    test_num.set_num(35);
    test_num = test_num.findReversed(1);
    QCOMPARE(test_num.get_num(), 0);

    test_num.set_num(2);
    test_num = test_num.findReversed(12);
    QCOMPARE(test_num.get_num(), 0);

    test_num.set_num(4);
    test_num = test_num.findReversed(10);
    QCOMPARE(test_num.get_num(), 0);

}

void TestNumberModulo::test_case_pow() {
    IntModulo test_num(5);
    test_num.pow(3, 13);
    QCOMPARE(test_num.get_num(), 8);

    test_num.set_num(4);
    test_num.pow(13, 497);
    QCOMPARE(test_num.get_num(), 445);

    test_num.pow(5, 1);
    QCOMPARE(test_num.get_num(), 0);

    test_num.pow(3, 12);
    QCOMPARE(test_num.get_num(), 0);

    test_num.set_num(1);
    test_num.pow(13, 497);
    QCOMPARE(test_num.get_num(), 1);

    test_num.set_num(2);
    test_num.pow(0, 497);
    QCOMPARE(test_num.get_num(), 1);

    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.pow(2, 0));
    QCOMPARE(test_num.get_num(), 1);

    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.pow(2, 0));
    // negative

    test_num.set_num(4); // inverse 3
    test_num.pow(-2, 11);
    QCOMPARE(test_num.get_num(), 9);

    test_num.set_num(3); // inverse 9
    test_num.pow(-3, 13);
    QCOMPARE(test_num.get_num(), 1);

    test_num.set_num(4);
    QVERIFY_THROWS_EXCEPTION(std::logic_error, test_num.pow(-2, 16));
}

bool invoke_sqrt_test(long long a, long long n, bool no_roots) {
    auto anss = IntModulo(a).sqrt(n);
    if (no_roots) {
        if (anss.size() != 0) {
            throw "There should be no roots";
        }
    } else {
        for (auto ans : anss) {
            if (ans*ans%n != a%n) {
                throw "Not a root";
            }
        }
    }
    return true;
}

void TestNumberModulo::test_case_sqrt() {
    // prime n
    invoke_sqrt_test(1, 2, false);
    invoke_sqrt_test(312, 683, false);
    invoke_sqrt_test(169, 1801, false);
    invoke_sqrt_test(420, 1237, false);
    invoke_sqrt_test(742, 1217, false);
    invoke_sqrt_test(738, 1279, false);
    invoke_sqrt_test(829, 1861, false);
    invoke_sqrt_test(870, 1013, false);
    invoke_sqrt_test(64, 887, false);
    invoke_sqrt_test(252, 1531, false);
    invoke_sqrt_test(118, 229, false);
    invoke_sqrt_test(233, 557, false);
    invoke_sqrt_test(965, 1493, false);
    invoke_sqrt_test(13, 647, false);
    invoke_sqrt_test(573, 1307, false);
    invoke_sqrt_test(559, 1789, false);
    invoke_sqrt_test(633, 1783, false);
    invoke_sqrt_test(776, 1279, false);
    invoke_sqrt_test(916, 1399, false);
    invoke_sqrt_test(724, 1949, false);
    invoke_sqrt_test(715, 1237, false);
    invoke_sqrt_test(108, 541, false);

    invoke_sqrt_test(10, 17, true);
    invoke_sqrt_test(907, 1123, true);
    invoke_sqrt_test(179, 1103, true);
    invoke_sqrt_test(340, 1451, true);
    invoke_sqrt_test(657, 1283, true);
    invoke_sqrt_test(518, 1223, true);

    // composite n
    invoke_sqrt_test(37, 1436, false);
    invoke_sqrt_test(863, 1535, false);
    invoke_sqrt_test(92, 1106, false);
    invoke_sqrt_test(287, 1099, false);
    invoke_sqrt_test(168, 514, false);
    invoke_sqrt_test(563, 1644, false);
    invoke_sqrt_test(938, 690, false);
    invoke_sqrt_test(577, 1121, false);
    invoke_sqrt_test(251, 1135, false);
    invoke_sqrt_test(504, 1851, false);
    invoke_sqrt_test(747, 1593, false);
    invoke_sqrt_test(856, 1514, false);
    invoke_sqrt_test(529, 1267, false);
    invoke_sqrt_test(323, 139, false);
    invoke_sqrt_test(59, 47, false);

    invoke_sqrt_test(858, 1422, true);
    invoke_sqrt_test(910, 973, true);
    invoke_sqrt_test(466, 1906, true);
    invoke_sqrt_test(48, 1309, true);
    invoke_sqrt_test(350, 644, true);
}

void TestNumberModulo::test_case_copy_constructor()
{
    IntModulo test_num(3);
    IntModulo copy_test_num = test_num;
    QCOMPARE(copy_test_num.get_num(), test_num.get_num());
    QCOMPARE(copy_test_num.get_num(), 3);
    test_num.set_num(0);
    IntModulo copy_test_num2 = test_num;
    QCOMPARE(copy_test_num2.get_num(), test_num.get_num());
    QCOMPARE(copy_test_num2.get_num(), 0);
    test_num.set_num(-2);
    IntModulo copy_test_num3 = test_num;
    QCOMPARE(copy_test_num3.get_num(), test_num.get_num());
    QCOMPARE(copy_test_num3.get_num(), -2);
}
void TestNumberModulo::test_case_copy_assignment_operator()
{
    IntModulo test_num(3);
    IntModulo copy_test_num;
    copy_test_num = test_num;
    QCOMPARE(copy_test_num.get_num(), test_num.get_num());
    QCOMPARE(copy_test_num.get_num(), 3);
    test_num.set_num(0);
    copy_test_num = test_num;
    QCOMPARE(copy_test_num.get_num(), test_num.get_num());
    QCOMPARE(copy_test_num.get_num(), 0);
    test_num.set_num(-2);
    copy_test_num = test_num;
    QCOMPARE(copy_test_num.get_num(), test_num.get_num());
    QCOMPARE(copy_test_num.get_num(), -2);
}

void TestNumberModulo::test_case_ToString()
{
    IntModulo test_num(3);
    QCOMPARE(test_num.ToString(), "3");
    test_num.set_num(45);
    QCOMPARE(test_num.ToString(), "45");
    test_num.set_num(-145);
    QCOMPARE(test_num.ToString(), "-145");
    test_num.set_num(0);
    QCOMPARE(test_num.ToString(), "0");
}

void TestNumberModulo::test_case_in_stream()
{
    std::stringstream ss;
    ss << "3 45 -145 0";
    IntModulo test_num;
    ss >> test_num;
    QCOMPARE(test_num.get_num(), 3);
    ss >> test_num;
    QCOMPARE(test_num.get_num(), 45);
    ss >> test_num;
    QCOMPARE(test_num.get_num(), -145);
    ss >> test_num;
    QCOMPARE(test_num.get_num(), 0);
}

void TestNumberModulo::test_case_FromString()
{
    IntModulo test_num;
    test_num.FromString("3");
    QCOMPARE(test_num.get_num(), 3);
    test_num.FromString("45");
    QCOMPARE(test_num.get_num(), 45);
    test_num.FromString("-145");
    QCOMPARE(test_num.get_num(), -145);
    test_num.FromString("0");
    QCOMPARE(test_num.get_num(), 0);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.FromString("ab"));
    test_num.FromString("0b");
    QCOMPARE(test_num.get_num(), 0);
}

void TestNumberModulo::test_case_isPrime()
{
    // checking incorrect iterations numbers.
    int iterations_num = 0;
    test_case_isPrime_helper(iterations_num);
    iterations_num = -1;
    test_case_isPrime_helper(iterations_num);

    // checking iterations numbers.
    // optimal numbers
    iterations_num = 5;
    test_case_isPrime_helper(iterations_num);
    iterations_num = 8;
    test_case_isPrime_helper(iterations_num);

    // non-optimal numbers
    iterations_num = 1;
    test_case_isPrime_helper(iterations_num);
    iterations_num = 2;
    test_case_isPrime_helper(iterations_num);
    iterations_num = 4;
    test_case_isPrime_helper(iterations_num);
    iterations_num = 5;
    test_case_isPrime_helper(iterations_num);
}

void TestNumberModulo::test_case_isPrime_helper(int iterations_num)
{
    IntModulo test_num;

    // checking incorrect iterations numbers.
    if(iterations_num < 1){
        test_num.set_num(0);
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.isPrime(iterations_num));
        test_num.set_num(-1);
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.isPrime(iterations_num));
        test_num.set_num(1);
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.isPrime(iterations_num));
        test_num.set_num(2);
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.isPrime(iterations_num));
        test_num.set_num(8);
        QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.isPrime(iterations_num));
        return;
    }

    // if iterations numbers are correct.
    // checking for non-natural numbers.
    test_num.set_num(0);
    QVERIFY(!test_num.isPrime(iterations_num));

    // checking corner case.
    test_num.set_num(1);
    QVERIFY(!test_num.isPrime(iterations_num));

    // checking non-prime numbers.
    test_num.set_num(4);
    QVERIFY(!test_num.isPrime(iterations_num));
    test_num.set_num(6);
    QVERIFY(!test_num.isPrime(iterations_num));
    test_num.set_num(8);
    QVERIFY(!test_num.isPrime(iterations_num));
    test_num.set_num(36);
    QVERIFY(!test_num.isPrime(iterations_num));

    // checking prime numbers.
    test_num.set_num(2);
    QVERIFY(test_num.isPrime(iterations_num));
    test_num.set_num(3);
    QVERIFY(test_num.isPrime(iterations_num));
    test_num.set_num(5);
    QVERIFY(test_num.isPrime(iterations_num));
    test_num.set_num(11);
    QVERIFY(test_num.isPrime(iterations_num));
    test_num.set_num(101);
    QVERIFY(test_num.isPrime(iterations_num));
}

void TestNumberModulo::test_case_comparision_operators()
{
    IntModulo test_num1, test_num2;
    test_num1.set_num(3);
    test_num2.set_num(3);
    QCOMPARE(test_num1 == test_num2, true);
    QCOMPARE(test_num1 != test_num2, false);
    QCOMPARE(test_num1 >= test_num2, true);
    QCOMPARE(test_num1 <= test_num2, true);
    QCOMPARE(test_num1 > test_num2, false);
    QCOMPARE(test_num1 < test_num2, false);

    test_num2.set_num(2);
    QCOMPARE(test_num1 == test_num2, false);
    QCOMPARE(test_num1 != test_num2, true);
    QCOMPARE(test_num1 >= test_num2, true);
    QCOMPARE(test_num1 <= test_num2, false);
    QCOMPARE(test_num1 > test_num2, true);
    QCOMPARE(test_num1 < test_num2, false);
}

void TestNumberModulo::test_case_phi()
{
    IntModulo test_num;

    // checking incorrect values of IntModulo
    test_num.set_num(0);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.phi());
    test_num.set_num(-1);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.phi());
    test_num.set_num(-8);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.phi());
    test_num.set_num(-36);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.phi());

    // checking Euler's Totient function Values
    test_num.set_num(1);
    QCOMPARE(test_num.phi(), 1);
    test_num.set_num(2);
    QCOMPARE(test_num.phi(), 1);
    test_num.set_num(3);
    QCOMPARE(test_num.phi(), 2);
    test_num.set_num(4);
    QCOMPARE(test_num.phi(), 2);
    test_num.set_num(5);
    QCOMPARE(test_num.phi(), 4);
    test_num.set_num(8);
    QCOMPARE(test_num.phi(), 4);
    test_num.set_num(12);
    QCOMPARE(test_num.phi(), 4);
    test_num.set_num(30);
    QCOMPARE(test_num.phi(), 8);
    test_num.set_num(31);
    QCOMPARE(test_num.phi(), 30);
    test_num.set_num(101);
    QCOMPARE(test_num.phi(), 100);
}

void TestNumberModulo::test_case_carmichael()
{
    IntModulo test_num;

    // checking incorrect values of IntModulo
    test_num.set_num(0);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.carmichael());
    test_num.set_num(-1);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.carmichael());
    test_num.set_num(-8);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.carmichael());
    test_num.set_num(-36);
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, test_num.carmichael());

    // checking Carmichael function values
    test_num.set_num(1);
    QCOMPARE(test_num.carmichael(), 1);
    test_num.set_num(2);
    QCOMPARE(test_num.carmichael(), 1);
    test_num.set_num(3);
    QCOMPARE(test_num.carmichael(), 2);
    test_num.set_num(4);
    QCOMPARE(test_num.carmichael(), 2);
    test_num.set_num(5);
    QCOMPARE(test_num.carmichael(), 4);
    test_num.set_num(8);
    QCOMPARE(test_num.carmichael(), 2);
    test_num.set_num(12);
    QCOMPARE(test_num.carmichael(), 2);
    test_num.set_num(30);
    QCOMPARE(test_num.carmichael(), 4);
    test_num.set_num(35);
    QCOMPARE(test_num.carmichael(), 12);
    test_num.set_num(36);
    QCOMPARE(test_num.carmichael(), 6);
    test_num.set_num(101);
    QCOMPARE(test_num.carmichael(), 100);
}

QTEST_APPLESS_MAIN(TestNumberModulo)

#include "tst_testnumbermodulo.moc"

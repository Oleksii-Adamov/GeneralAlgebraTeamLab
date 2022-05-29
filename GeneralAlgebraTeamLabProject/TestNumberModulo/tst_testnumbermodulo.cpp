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
}

bool invoke_sqrt_test(long long a, long long n, bool no_roots) {
    auto anss = IntModulo(a).sqrt(n);
    if (no_roots) {
        return anss.size() == 0;
    } else {
        for (auto ans : anss) {
            if (ans*ans%n != a%n) {
                return false;
            }
        }
    }
    return true;
}

void TestNumberModulo::test_case_sqrt() {
    invoke_sqrt_test(312, 683, false);

//    // prime modulo
//    IntModulo test_num(5);
//    std::optional<std::pair<IntModulo, IntModulo>> res;
//    std::vector<int> sqrts;

//    test_num.set_num(312);
//    res = test_num.sqrt(683);
//    sqrts.assign({76, 607});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(169);
//    res = test_num.sqrt(1801);
//    sqrts.assign({13, 1788});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(420);
//    res = test_num.sqrt(1237);
//    sqrts.assign({347, 890});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(681);
//    res = test_num.sqrt(1013);
//    sqrts.assign({126, 887});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(742);
//    res = test_num.sqrt(1217);
//    sqrts.assign({457, 760});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(738);
//    res = test_num.sqrt(1279);
//    sqrts.assign({456, 823});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(829);
//    res = test_num.sqrt(1861);
//    sqrts.assign({226, 1635});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(870);
//    res = test_num.sqrt(1013);
//    sqrts.assign({496, 517});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(64);
//    res = test_num.sqrt(887);
//    sqrts.assign({8, 879});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(252);
//    res = test_num.sqrt(1531);
//    sqrts.assign({436, 1095});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(118);
//    res = test_num.sqrt(229);
//    sqrts.assign({24, 205});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(233);
//    res = test_num.sqrt(557);
//    sqrts.assign({104, 453});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(965);
//    res = test_num.sqrt(1493);
//    sqrts.assign({661, 832});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(13);
//    res = test_num.sqrt(647);
//    sqrts.assign({51, 596});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(573);
//    res = test_num.sqrt(1307);
//    sqrts.assign({241, 1066});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(559);
//    res = test_num.sqrt(1789);
//    sqrts.assign({181, 1608});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(633);
//    res = test_num.sqrt(1783);
//    sqrts.assign({656, 1127});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(776);
//    res = test_num.sqrt(1279);
//    sqrts.assign({463, 816});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(916);
//    res = test_num.sqrt(1399);
//    sqrts.assign({621, 778});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(724);
//    res = test_num.sqrt(1949);
//    sqrts.assign({824, 1125});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(715);
//    res = test_num.sqrt(1237);
//    sqrts.assign({514, 723});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(108);
//    res = test_num.sqrt(541);
//    sqrts.assign({199, 342});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(12);
//    res = test_num.sqrt(601);
//    sqrts.assign({230, 371});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(305);
//    res = test_num.sqrt(547);
//    sqrts.assign({98, 449});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(703);
//    res = test_num.sqrt(1741);
//    sqrts.assign({179, 1562});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(892);
//    res = test_num.sqrt(1087);
//    sqrts.assign({255, 832});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(26);
//    res = test_num.sqrt(1181);
//    sqrts.assign({432, 749});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(579);
//    res = test_num.sqrt(1151);
//    sqrts.assign({443, 708});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(52);
//    res = test_num.sqrt(439);
//    sqrts.assign({37, 402});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(838);
//    res = test_num.sqrt(977);
//    sqrts.assign({207, 770});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(10);
//    res = test_num.sqrt(17);
//    QVERIFY(!res.has_value());

//    test_num.set_num(907);
//    res = test_num.sqrt(1123);
//    QVERIFY(!res.has_value());

//    test_num.set_num(179);
//    res = test_num.sqrt(1103);
//    QVERIFY(!res.has_value());

//    test_num.set_num(340);
//    res = test_num.sqrt(1451);
//    QVERIFY(!res.has_value());

//    test_num.set_num(657);
//    res = test_num.sqrt(1283);
//    QVERIFY(!res.has_value());

//    test_num.set_num(518);
//    res = test_num.sqrt(1223);
//    QVERIFY(!res.has_value());

//    test_num.set_num(163);
//    res = test_num.sqrt(1607);
//    QVERIFY(!res.has_value());

//    // -- p == 3 (mod 4)
//    test_num.set_num(691);
//    res = test_num.sqrt(1123);
//    sqrts.assign({319, 804});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(554);
//    res = test_num.sqrt(587);
//    sqrts.assign({166, 421});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(98);
//    res = test_num.sqrt(1439);
//    sqrts.assign({628, 811});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(882);
//    res = test_num.sqrt(887);
//    sqrts.assign({193, 694});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(899);
//    res = test_num.sqrt(1051);
//    QVERIFY(!res.has_value());

//    test_num.set_num(571);
//    res = test_num.sqrt(683);
//    sqrts.assign({104, 579});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(747);
//    res = test_num.sqrt(1087);
//    sqrts.assign({432, 655});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(12);
//    res = test_num.sqrt(307);
//    QVERIFY(!res.has_value());

//    test_num.set_num(927);
//    res = test_num.sqrt(1663);
//    QVERIFY(!res.has_value());

//    test_num.set_num(572);
//    res = test_num.sqrt(587);
//    sqrts.assign({137, 450});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(9);
//    res = test_num.sqrt(1439);
//    sqrts.assign({3, 1436});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(108);
//    res = test_num.sqrt(739);
//    QVERIFY(!res.has_value());

//    test_num.set_num(662);
//    res = test_num.sqrt(1543);
//    QVERIFY(!res.has_value());

//    test_num.set_num(183);
//    res = test_num.sqrt(383);
//    QVERIFY(!res.has_value());

//    test_num.set_num(665);
//    res = test_num.sqrt(1327);
//    QVERIFY(!res.has_value());

//    test_num.set_num(163);
//    res = test_num.sqrt(563);
//    QVERIFY(!res.has_value());

//    test_num.set_num(541);
//    res = test_num.sqrt(1283);
//    QVERIFY(!res.has_value());

//    test_num.set_num(223);
//    res = test_num.sqrt(1619);
//    QVERIFY(!res.has_value());

//    test_num.set_num(730);
//    res = test_num.sqrt(1951);
//    QVERIFY(!res.has_value());

//    test_num.set_num(696);
//    res = test_num.sqrt(1999);
//    sqrts.assign({284, 1715});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(384);
//    res = test_num.sqrt(643);
//    sqrts.assign({90, 553});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(129);
//    res = test_num.sqrt(283);
//    sqrts.assign({107, 176});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(235);
//    res = test_num.sqrt(991);
//    QVERIFY(!res.has_value());

//    test_num.set_num(168);
//    res = test_num.sqrt(827);
//    sqrts.assign({310, 517});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(439);
//    res = test_num.sqrt(823);
//    sqrts.assign({379, 444});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(386);
//    res = test_num.sqrt(1987);
//    sqrts.assign({210, 1777});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(758);
//    res = test_num.sqrt(1063);
//    QVERIFY(!res.has_value());

//    test_num.set_num(487);
//    res = test_num.sqrt(523);
//    QVERIFY(!res.has_value());

//    test_num.set_num(300);
//    res = test_num.sqrt(983);
//    sqrts.assign({57, 926});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(155);
//    res = test_num.sqrt(587);
//    QVERIFY(!res.has_value());


//    // -- p == 5 (mod 8)
//    test_num.set_num(977);
//    res = test_num.sqrt(1733);
//    QVERIFY(!res.has_value());

//    test_num.set_num(413);
//    res = test_num.sqrt(757);
//    sqrts.assign({147, 610});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(668);
//    res = test_num.sqrt(829);
//    QVERIFY(!res.has_value());

//    test_num.set_num(182);
//    res = test_num.sqrt(1277);
//    sqrts.assign({432, 845});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(970);
//    res = test_num.sqrt(1549);
//    QVERIFY(!res.has_value());

//    test_num.set_num(464);
//    res = test_num.sqrt(1181);
//    QVERIFY(!res.has_value());

//    test_num.set_num(671);
//    res = test_num.sqrt(1229);
//    QVERIFY(!res.has_value());

//    test_num.set_num(122);
//    res = test_num.sqrt(829);
//    QVERIFY(!res.has_value());

//    test_num.set_num(311);
//    res = test_num.sqrt(541);
//    QVERIFY(!res.has_value());

//    test_num.set_num(584);
//    res = test_num.sqrt(1693);
//    sqrts.assign({274, 1419});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(663);
//    res = test_num.sqrt(877);
//    sqrts.assign({227, 650});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(107);
//    res = test_num.sqrt(653);
//    sqrts.assign({138, 515});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(965);
//    res = test_num.sqrt(1637);
//    QVERIFY(!res.has_value());

//    test_num.set_num(827);
//    res = test_num.sqrt(1613);
//    sqrts.assign({153, 1460});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(492);
//    res = test_num.sqrt(1613);
//    sqrts.assign({198, 1415});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(728);
//    res = test_num.sqrt(773);
//    QVERIFY(!res.has_value());

//    test_num.set_num(232);
//    res = test_num.sqrt(677);
//    sqrts.assign({159, 518});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(785);
//    res = test_num.sqrt(1877);
//    sqrts.assign({118, 1759});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(56);
//    res = test_num.sqrt(1301);
//    sqrts.assign({81, 1220});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(521);
//    res = test_num.sqrt(1997);
//    QVERIFY(!res.has_value());

//    test_num.set_num(203);
//    res = test_num.sqrt(1693);
//    sqrts.assign({714, 979});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(73);
//    res = test_num.sqrt(509);
//    sqrts.assign({40, 469});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(683);
//    res = test_num.sqrt(1373);
//    QVERIFY(!res.has_value());

//    test_num.set_num(431);
//    res = test_num.sqrt(1109);
//    QVERIFY(!res.has_value());

//    test_num.set_num(323);
//    res = test_num.sqrt(1997);
//    QVERIFY(!res.has_value());

//    test_num.set_num(951);
//    res = test_num.sqrt(1373);
//    QVERIFY(!res.has_value());

//    test_num.set_num(694);
//    res = test_num.sqrt(1117);
//    sqrts.assign({86, 1031});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(330);
//    res = test_num.sqrt(1021);
//    QVERIFY(!res.has_value());

//    test_num.set_num(881);
//    res = test_num.sqrt(1949);
//    QVERIFY(!res.has_value());

//    test_num.set_num(956);
//    res = test_num.sqrt(997);
//    QVERIFY(!res.has_value());

//    // n composite

//    test_num.set_num(37);
//    res = test_num.sqrt(1436);
//    sqrts.assign({197, 521, 915, 1239});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(863);
//    res = test_num.sqrt(1535);
//    QVERIFY(!res.has_value());

//    test_num.set_num(92);
//    res = test_num.sqrt(1106);
//    sqrts.assign({48, 426, 680, 1058});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(41);
//    res = test_num.sqrt(1617);
//    QVERIFY(!res.has_value());

//    test_num.set_num(858);
//    res = test_num.sqrt(1422);
//    QVERIFY(!res.has_value());

//    test_num.set_num(910);
//    res = test_num.sqrt(973);
//    QVERIFY(!res.has_value());

//    test_num.set_num(231);
//    res = test_num.sqrt(1139);
//    QVERIFY(!res.has_value());

//    test_num.set_num(352);
//    res = test_num.sqrt(655);
//    QVERIFY(!res.has_value());

//    test_num.set_num(287);
//    res = test_num.sqrt(1099);
//    sqrts.assign({546, 553});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(168);
//    res = test_num.sqrt(514);
//    sqrts.assign({164, 350});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(563);
//    res = test_num.sqrt(1644);
//    QVERIFY(!res.has_value());

//    test_num.set_num(500);
//    res = test_num.sqrt(690);
//    QVERIFY(!res.has_value());

//    test_num.set_num(938);
//    res = test_num.sqrt(1562);
//    sqrts.assign({50, 192, 1370, 1512});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(867);
//    res = test_num.sqrt(1479);
//    QVERIFY(!res.has_value());

//    test_num.set_num(272);
//    res = test_num.sqrt(1508);
//    QVERIFY(!res.has_value());

//    test_num.set_num(264);
//    res = test_num.sqrt(1746);
//    QVERIFY(!res.has_value());

//    test_num.set_num(978);
//    res = test_num.sqrt(1455);
//    QVERIFY(!res.has_value());

//    test_num.set_num(577);
//    res = test_num.sqrt(1121);
//    sqrts.assign({315, 334, 787, 806});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(251);
//    res = test_num.sqrt(1135);
//    QVERIFY(!res.has_value());

//    test_num.set_num(504);
//    res = test_num.sqrt(1851);
//    sqrts.assign({882, 969});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(747);
//    res = test_num.sqrt(1593);
//    QVERIFY(!res.has_value());

//    test_num.set_num(188);
//    res = test_num.sqrt(822);
//    QVERIFY(!res.has_value());

//    test_num.set_num(326);
//    res = test_num.sqrt(1014);
//    QVERIFY(!res.has_value());

//    test_num.set_num(856);
//    res = test_num.sqrt(1514);
//    sqrts.assign({448, 1066});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(232);
//    res = test_num.sqrt(1275);
//    QVERIFY(!res.has_value());

//    test_num.set_num(171);
//    res = test_num.sqrt(1995);
//    QVERIFY(!res.has_value());

//    test_num.set_num(529);
//    res = test_num.sqrt(1267);
//    sqrts.assign({23, 520, 747, 1244});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(466);
//    res = test_num.sqrt(1906);
//    QVERIFY(!res.has_value());

//    test_num.set_num(48);
//    res = test_num.sqrt(1309);
//    QVERIFY(!res.has_value());

//    test_num.set_num(350);
//    res = test_num.sqrt(644);
//    QVERIFY(!res.has_value());

//    // a > mod
//    test_num.set_num(323);
//    res = test_num.sqrt(139);
//    sqrts.assign({36, 103});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(192);
//    res = test_num.sqrt(586);
//    QVERIFY(!res.has_value());

//    test_num.set_num(59);
//    res = test_num.sqrt(47);
//    sqrts.assign({23, 24});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(182);
//    res = test_num.sqrt(270);
//    QVERIFY(!res.has_value());

//    test_num.set_num(56);
//    res = test_num.sqrt(283);
//    QVERIFY(!res.has_value());

//    test_num.set_num(52);
//    res = test_num.sqrt(8);
//    sqrts.assign({2, 6});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

//    test_num.set_num(436);
//    res = test_num.sqrt(455);
//    QVERIFY(!res.has_value());

//    test_num.set_num(125);
//    res = test_num.sqrt(146);
//    QVERIFY(!res.has_value());

//    test_num.set_num(77);
//    res = test_num.sqrt(115);
//    QVERIFY(!res.has_value());

//    test_num.set_num(899);
//    res = test_num.sqrt(467);
//    sqrts.assign({124, 343});
//    QVERIFY(res.has_value());
//    QVERIFY(res.value().first.get_num() != res.value().second.get_num());
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().first.get_num()) != std::end(sqrts));
//    QVERIFY(std::find(std::begin(sqrts), std::end(sqrts), res.value().second.get_num()) != std::end(sqrts));

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
    test_num.set_num(-1);
    QVERIFY(!test_num.isPrime(iterations_num));
    test_num.set_num(-2);
    QVERIFY(!test_num.isPrime(iterations_num));
    test_num.set_num(-8);
    QVERIFY(!test_num.isPrime(iterations_num));
    test_num.set_num(-36);
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

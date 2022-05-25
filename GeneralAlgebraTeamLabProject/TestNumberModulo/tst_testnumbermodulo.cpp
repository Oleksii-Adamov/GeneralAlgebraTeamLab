#include <QtTest>

// add necessary includes here
#include "task1/intmodulo.h"
#include <stdexcept>
#include <sstream>

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
    void test_case_divide();
    void test_case_findReversed();
    void test_case_pow();
    void test_case_sqrt();
    void test_case_copy_constructor();
    void test_case_copy_assignment_operator();
    void test_case_ToString();
    void test_case_in_stream();
    void test_case_FromString();
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

    /* not working
    test_num.set_num(2);
    test_num = test_num.findReversed(12);
    QCOMPARE(test_num.get_num(), 0);
    */
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
}

void TestNumberModulo::test_case_sqrt() {

    // prime modulo
    IntModulo test_num(5);
    std::optional<std::pair<IntModulo, IntModulo>> res = test_num.sqrt(41);
    std::vector<int> sqrtsP {13, 28};
    std::vector<int> sqrtsN {-13, -28};
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(10);
    res = test_num.sqrt(13);
    sqrtsP.assign({6, 7});
    sqrtsN.assign({-6, -7});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(47);
    res = test_num.sqrt(61);
    sqrtsP.assign({13, 48});
    sqrtsN.assign({-13, -48});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(47);
    res = test_num.sqrt(89);
    sqrtsP.assign({15, 74});
    sqrtsN.assign({-15, -74});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(55);
    res = test_num.sqrt(103);
    sqrtsP.assign({40, 63});
    sqrtsN.assign({-40, -63});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(131);
    sqrtsP.assign({49, 82});
    sqrtsN.assign({-49, -82});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(173);
    sqrtsP.assign({40, 133});
    sqrtsN.assign({-40, -133});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(229);
    sqrtsP.assign({57, 172});
    sqrtsN.assign({-57, -172});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(59);
    res = test_num.sqrt(257);
    sqrtsP.assign({109, 148});
    sqrtsN.assign({-109, -148});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(55);
    res = test_num.sqrt(271);
    sqrtsP.assign({41, 230});
    sqrtsN.assign({-41, -230});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(71);
    res = test_num.sqrt(313);
    sqrtsP.assign({135, 178});
    sqrtsN.assign({-135, -178});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(383);
    sqrtsP.assign({127, 256});
    sqrtsN.assign({-127, -256});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(397);
    sqrtsP.assign({123, 274});
    sqrtsN.assign({-123, -274});
    std::cout << "val:" << res.value().first.get_num() << std::endl;
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(51);
    res = test_num.sqrt(439);
    sqrtsP.assign({200, 239});
    sqrtsN.assign({-200, -239});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(467);
    sqrtsP.assign({38, 429});
    sqrtsN.assign({-38, -429});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(509);
    sqrtsP.assign({68, 441});
    sqrtsN.assign({-68, -441});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(43);
    res = test_num.sqrt(523);
    sqrtsP.assign({33, 490});
    sqrtsN.assign({-33, -490});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(55);
    res = test_num.sqrt(593);
    sqrtsP.assign({184, 409});
    sqrtsN.assign({-184, -409});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(10);
    res = test_num.sqrt(17);
    QVERIFY(!res.has_value());

    // -- p == 3 (mod 4)
    test_num.set_num(17);
    res = test_num.sqrt(43);
    sqrtsP.assign({19, 24});
    sqrtsN.assign({-19, -24});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(2);
    res = test_num.sqrt(31);
    sqrtsP.assign({8, 23});
    sqrtsN.assign({-8, -23});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(67);
    res = test_num.sqrt(683);
    sqrtsP.assign({46, 637});
    sqrtsN.assign({-46, -637});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(15);
    res = test_num.sqrt(23);
    QVERIFY(!res.has_value());

    // -- p == 5 (mod 8)
    test_num.set_num(15);
    res = test_num.sqrt(797);
    sqrtsP.assign({183, 614});
    sqrtsN.assign({-183, -614});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(55);
    res = test_num.sqrt(421);
    sqrtsP.assign({62, 359});
    sqrtsN.assign({-62, -359});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(37);
    res = test_num.sqrt(101);
    sqrtsP.assign({21, 80});
    sqrtsN.assign({-21, -80});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(46);
    res = test_num.sqrt(109);
    sqrtsP.assign({41, 68});
    sqrtsN.assign({-41, -68});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(54);
    res = test_num.sqrt(421);
    QVERIFY(!res.has_value());

    test_num.set_num(44);
    res = test_num.sqrt(109);
    QVERIFY(!res.has_value());

    // n composite

    test_num.set_num(470);
    res = test_num.sqrt(1295);
    sqrtsP.assign({195});
    sqrtsN.assign({-195});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(33);
    res = test_num.sqrt(367);
    sqrtsP.assign({20});
    sqrtsN.assign({-20});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(740);
    res = test_num.sqrt(1670);
    sqrtsP.assign({590});
    sqrtsN.assign({-590});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(961);
    res = test_num.sqrt(1180);
    sqrtsP.assign({31, 149, 441, 559, 621, 739});
    sqrtsN.assign({-31, -149, -441, -559, -621, -739});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(520);
    res = test_num.sqrt(1551);
    sqrtsP.assign({82, 247});
    sqrtsN.assign({-82, -247});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(675);
    res = test_num.sqrt(1878);
    sqrtsP.assign({633});
    sqrtsN.assign({-633});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(695);
    res = test_num.sqrt(1142);
    sqrtsP.assign({309});
    sqrtsN.assign({-309});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(954);
    res = test_num.sqrt(1411);
    sqrtsP.assign({295, 618, 793});
    sqrtsN.assign({-295, -618, -793});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(545);
    res = test_num.sqrt(689);
    sqrtsP.assign({148, 307, 382, 541});
    sqrtsN.assign({-148, -307, -382, -541});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(909);
    res = test_num.sqrt(1819);
    sqrtsP.assign({573, 787});
    sqrtsN.assign({-573, -787});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(540);
    res = test_num.sqrt(1557);
    sqrtsP.assign({114, 405});
    sqrtsN.assign({-114, -405});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(815);
    res = test_num.sqrt(1882);
    sqrtsP.assign({159});
    sqrtsN.assign({-159});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(762);
    res = test_num.sqrt(1889);
    sqrtsP.assign({404});
    sqrtsN.assign({-404});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(830);
    res = test_num.sqrt(1606);
    sqrtsP.assign({136, 282});
    sqrtsN.assign({-136, -282});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(394);
    res = test_num.sqrt(1614);
    sqrtsP.assign({92});
    sqrtsN.assign({-92});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(670);
    res = test_num.sqrt(1329);
    sqrtsP.assign({161, 604});
    sqrtsN.assign({-161, -604});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(592);
    res = test_num.sqrt(1626);
    sqrtsP.assign({62});
    sqrtsN.assign({-62});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(690);
    res = test_num.sqrt(771);
    sqrtsP.assign({144, 627});
    sqrtsN.assign({-144, -627});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(873);
    res = test_num.sqrt(1114);
    sqrtsP.assign({73});
    sqrtsN.assign({-73});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(106);
    res = test_num.sqrt(1575);
    sqrtsP.assign({41});
    sqrtsN.assign({-41});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(285);
    res = test_num.sqrt(1887);
    sqrtsP.assign({195});
    sqrtsN.assign({-195});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(303);
    res = test_num.sqrt(973);
    sqrtsP.assign({144, 283});
    sqrtsN.assign({-144, -283});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(800);
    res = test_num.sqrt(929);
    sqrtsP.assign({155, 774});
    sqrtsN.assign({-155, -774});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(878);
    res = test_num.sqrt(1697);
    sqrtsP.assign({620});
    sqrtsN.assign({-620});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(816);
    res = test_num.sqrt(1130);
    sqrtsP.assign({334, 344, 786, 796});
    sqrtsN.assign({-334, -344, -786, -796});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(246);
    res = test_num.sqrt(1955);
    sqrtsP.assign({226});
    sqrtsN.assign({-226});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(132);
    res = test_num.sqrt(332);
    sqrtsP.assign({76, 90});
    sqrtsN.assign({-76, -90});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(783);
    res = test_num.sqrt(1189);
    sqrtsP.assign({203});
    sqrtsN.assign({-203});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(341);
    res = test_num.sqrt(1676);
    sqrtsP.assign({315});
    sqrtsN.assign({-315});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));

    test_num.set_num(348);
    res = test_num.sqrt(1938);
    sqrtsP.assign({90, 318});
    sqrtsN.assign({-90, -318});
    QVERIFY(res.has_value());
    QVERIFY(std::find(std::begin(sqrtsP), std::end(sqrtsP), res.value().first.get_num()) != std::end(sqrtsP));
    QVERIFY(std::find(std::begin(sqrtsN), std::end(sqrtsN), res.value().second.get_num()) != std::end(sqrtsN));



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

QTEST_APPLESS_MAIN(TestNumberModulo)

#include "tst_testnumbermodulo.moc"

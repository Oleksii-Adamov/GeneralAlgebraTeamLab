#include "polynomialfieldwindow.h"
#include "ui_polynomialfieldwindow.h"
#include "validation.h"
#include "task15/ri.h"
#include "task20/generator.h"

PolynomialFieldWindow::PolynomialFieldWindow(QWidget *parent) :
    AbstractGuiShowExceptionWindow(parent),
    ui(new Ui::PolynomialFieldWindow)
{
    ui->setupUi(this);
}

PolynomialFieldWindow::~PolynomialFieldWindow()
{
    delete ui;
}

void PolynomialFieldWindow::evaluate_func(std::function<void(PolynomialFieldWindow*)> func, PolynomialFieldWindow* context)
{
    std::function<void(AbstractGuiShowExceptionWindow*)>& base_func = reinterpret_cast<std::function<void(AbstractGuiShowExceptionWindow*)>&>(func);
    evaluate_base_func(base_func, context);
}
void PolynomialFieldWindow::show_exception(const std::string& message)
{
    set_ans(message);
}

void PolynomialFieldWindow::set_ans(int ans)
{
    ui->lineEdit_ans->setText(QString::number(ans));
}

void PolynomialFieldWindow::set_ans(const Polinome& ans)
{
    ui->lineEdit_ans->setText(QString::fromStdString(ans.toString()));
}

void PolynomialFieldWindow::set_ans(const std::string& ans)
{
    ui->lineEdit_ans->setText(QString::fromStdString(ans));
}

void PolynomialFieldWindow::validate_modulus_field() {
    if(!valid_ull(ui->lineEdit_modulus->text())) {
        throw std::invalid_argument("Модуль неправильно введено");
    }
}

void PolynomialFieldWindow::read_and_mod(Polinome& first, Polinome& second, Polinome& irreducible, unsigned long long& modulus)
{
    read_and_mod(first, irreducible, modulus);
    second = Polinome(ui->lineEdit_second->text().toStdString());
    second = second.add(Polinome("0"), modulus);
}

void PolynomialFieldWindow::read_and_mod(Polinome& first, Polinome& irreducible, unsigned long long& modulus)
{
    validate_modulus_field();
    modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    first = Polinome(ui->lineEdit_first->text().toStdString());
    first = first.add(Polinome("0"), modulus);
    irreducible = Polinome(ui->lineEdit_irreducible->text().toStdString());
    irreducible = irreducible.add(Polinome("0"), modulus);
}

void PolynomialFieldWindow::on_pushButton_order_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        Polinome input, irreducible;
        unsigned long long modulus;
        window->read_and_mod(input, irreducible, modulus);
        int ans = orderOfPolinome(modulus, irreducible, input);
        window->set_ans(ans);
    }, this);
}


void PolynomialFieldWindow::on_pushButton_CyclFact_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        window->validate_modulus_field();
        unsigned long long modulus = std::stoull(window->ui->lineEdit_modulus->text().toStdString());
        if (!valid_ull(window->ui->lineEdit_first->text())) {
            throw std::invalid_argument("Перше поле неправильно заповнене");
        }
        unsigned long long number_of_cycl_pol =  std::stoull(window->ui->lineEdit_first->text().toStdString());
        std::vector<Polinome> fact  = computePolynomialProductOfCyclotomicPlynomial(modulus, number_of_cycl_pol);
        std::string ans = "";
        for (std::size_t i = 0; i < fact.size(); i++) {
            ans += "(" + fact[i].toString() + ")";
        }
        window->ui->lineEdit_ans->setText(QString::fromStdString(ans));
    }, this);
}


void PolynomialFieldWindow::on_pushButton_is_irreducible_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        window->validate_modulus_field();
        unsigned long long modulus = std::stoull(window->ui->lineEdit_modulus->text().toStdString());
        Polinome input(window->ui->lineEdit_first->text().toStdString());
        if(checkIrreducibilty(input, modulus)) {
            window->ui->lineEdit_ans->setText("Так, є незвідним");
        }
        else {
            window->ui->lineEdit_ans->setText("Ні, не є незвідним");
        }
    }, this);
}


void PolynomialFieldWindow::on_pushButton_add_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        Polinome first, second, irreducible;
        unsigned long long modulus;
        window->read_and_mod(first, second, irreducible, modulus);
        Polinome ans = first.add(second, irreducible, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialFieldWindow::on_pushButton_subtract_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        Polinome first, second, irreducible;
        unsigned long long modulus;
        window->read_and_mod(first, second, irreducible, modulus);
        Polinome ans = first.subtract(second, irreducible, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialFieldWindow::on_pushButton_multiply_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        Polinome first, second, irreducible;
        unsigned long long modulus;
        window->read_and_mod(first, second, irreducible, modulus);
        Polinome ans = first.multiply(second, irreducible, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialFieldWindow::on_pushButton_pow_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        Polinome first, irreducible;
        unsigned long long modulus;
        window->read_and_mod(first, irreducible, modulus);
        // possible change for valid_ll if negatives will be added
        if (!valid_ull(window->ui->lineEdit_second->text())) throw std::invalid_argument("Друге поле введено неправильно");
        long long exponent = std::stoll(window->ui->lineEdit_second->text().toStdString());
        Polinome ans = first.pow(exponent, irreducible, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialFieldWindow::on_pushButton_reduce_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        window->validate_modulus_field();
        unsigned long long modulus = std::stoull(window->ui->lineEdit_modulus->text().toStdString());
        Polinome input = Polinome(window->ui->lineEdit_first->text().toStdString());
        Polinome ans = input.reduce(modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialFieldWindow::on_pushButton_is_generator_clicked()
{
    evaluate_func([](PolynomialFieldWindow* window) {
        Polinome input, irreducible;
        unsigned long long modulus;
        window->read_and_mod(input, irreducible, modulus);
        if (isGenerator(modulus, irreducible, input)) {
            window->set_ans("Так, є генератором");
        }
        else {
            window->set_ans("Ні, не є генератором");
        }
    }, this);
}


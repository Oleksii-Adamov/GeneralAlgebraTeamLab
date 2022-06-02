#include "polynomialringwindow.h"
#include "ui_polynomialringwindow.h"
#include "validation.h"

PolynomialRingWindow::PolynomialRingWindow(QWidget *parent) :
    AbstractGuiShowExceptionWindow(parent),
    ui(new Ui::PolynomialRingWindow)
{
    ui->setupUi(this);
}

PolynomialRingWindow::~PolynomialRingWindow()
{
    delete ui;
}

void PolynomialRingWindow::evaluate_func(std::function<void(PolynomialRingWindow*)> func, PolynomialRingWindow* context)
{
    std::function<void(AbstractGuiShowExceptionWindow*)>& base_func = reinterpret_cast<std::function<void(AbstractGuiShowExceptionWindow*)>&>(func);
    evaluate_base_func(base_func, context);
}
void PolynomialRingWindow::show_exception(const std::string& message)
{
    set_ans(message);
}

void PolynomialRingWindow::set_ans(const IntModulo& ans)
{
    ui->lineEdit_ans->setText(QString::number(ans.get_num()));
}

void PolynomialRingWindow::set_ans(const Polinome& ans)
{
    ui->lineEdit_ans->setText(QString::fromStdString(ans.toString()));
}

void PolynomialRingWindow::set_ans(const std::string& ans)
{
    ui->lineEdit_ans->setText(QString::fromStdString(ans));
}

void PolynomialRingWindow::validate_modulus_field() {
    if(!valid_ull(ui->lineEdit_modulus->text())) {
        throw std::invalid_argument("Модуль неправильно введено");
    }
}

void PolynomialRingWindow::read_and_mod(Polinome& first, Polinome& second, unsigned long long& modulus)
{
    read_and_mod(first, modulus);
    second = Polinome(ui->lineEdit_second->text().toStdString());
    second = second.add(Polinome("0"), modulus);
}
void PolynomialRingWindow::read_and_mod(Polinome& first, unsigned long long& modulus)
{
    validate_modulus_field();
    modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    first = Polinome(ui->lineEdit_first->text().toStdString());
    first = first.add(Polinome("0"), modulus);
}

void PolynomialRingWindow::on_pushButton_add_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        Polinome ans = first.add(second, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialRingWindow::on_pushButton_evaluate_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        if (!valid_ll(window->ui->lineEdit_second->text())) {
            throw std::invalid_argument("Друге поле неправильно заповнене");
        }
        IntModulo point(window->ui->lineEdit_second->text().toStdString());
        point.mod(modulus);
        IntModulo ans = first.evaluate(point, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialRingWindow::on_pushButton_derivative_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        Polinome ans = first.derivative(modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialRingWindow::on_pushButton_divide_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        auto ans = first.divide(second, modulus);
        window->ui->lineEdit_ans->setText("Частка: " + QString::fromStdString(ans.quotient->toString())
                                  + " Остача: " + QString::fromStdString(ans.remainder->toString()));
    }, this);
}


void PolynomialRingWindow::on_pushButton_gcd_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        auto ans = first.gcd(second, modulus);
        window->set_ans(*ans);
        delete ans;
    }, this);
}


void PolynomialRingWindow::on_pushButton_CyclotomicPolynomial_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        window->validate_modulus_field();
        unsigned long long modulus = std::stoull(window->ui->lineEdit_modulus->text().toStdString());
        if (!valid_ull(window->ui->lineEdit_first->text())) {
            throw std::invalid_argument("Перше поле неправильно заповнене");
        }
        unsigned long long n = std::stoull(window->ui->lineEdit_first->text().toStdString());
        DivisionResult<Polinome> ans = CyclotomicPolynomial(n, modulus);
        window->ui->lineEdit_ans->setText(QString::fromStdString(ans.quotient->toString()));
    }, this);
}


void PolynomialRingWindow::on_pushButton_subtract_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        Polinome ans = first.subtract(second, modulus);
        window->set_ans(ans);
    }, this);
}


void PolynomialRingWindow::on_pushButton_multiply_clicked()
{
    evaluate_func([](PolynomialRingWindow* window) {
        Polinome first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        Polinome ans = first.multiply(second, modulus);
        window->set_ans(ans);
    }, this);
}


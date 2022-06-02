#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"
#include <string>
#include <limits>
#include "task5/pollardfactorization.h"
#include "task8/findgroup.h"
#include "task7/discrete_logarithm.h"
#include "validation.h"

FiniteFieldWindow::FiniteFieldWindow(QWidget *parent) :
    AbstractGuiShowExceptionWindow(parent),
    ui(new Ui::FiniteFieldWindow)
{
    ui->setupUi(this);
}

FiniteFieldWindow::~FiniteFieldWindow()
{
    delete ui;
}

void FiniteFieldWindow::show_exception(const std::string& message) {
    set_ans(message);
}

void FiniteFieldWindow::evaluate_func(std::function<void(FiniteFieldWindow*)> func, FiniteFieldWindow* context) {
    std::function<void(AbstractGuiShowExceptionWindow*)>& base_func = reinterpret_cast<std::function<void(AbstractGuiShowExceptionWindow*)>&>(func);
    evaluate_base_func(base_func, context);
}

void FiniteFieldWindow::validate_first_field() {
    if(!valid_ll(ui->lineEdit_first->text())) {
        throw std::invalid_argument("Перше поле неправильно заповнене");
    }
}

void FiniteFieldWindow::validate_second_field() {
    if(!valid_ll(ui->lineEdit_second->text())) {
        throw std::invalid_argument("Друге поле неправильно заповнене");
    }
}

void FiniteFieldWindow::validate_modulus_field() {
    if(!valid_ull(ui->lineEdit_modulus->text())) {
        throw std::invalid_argument("Модуль неправильно введено");
    }
}

void FiniteFieldWindow::read_and_mod(IntModulo& first, IntModulo& second, unsigned long long& modulus) {
    read_and_mod(first, modulus);
    //if (ui->lineEdit_second->text() == "") throw std::invalid_argument("Друге поле не заповнене");
    validate_second_field();
    second.FromString(ui->lineEdit_second->text().toStdString());
    second.mod(modulus);
}

void FiniteFieldWindow::read_and_mod(IntModulo& first, unsigned long long& modulus) {
    //if (ui->lineEdit_modulus->text() == "") throw std::invalid_argument("Модуль не задано");
    //if (ui->lineEdit_first->text() == "") throw std::invalid_argument("Перше поле не заповнене");
    validate_modulus_field();
    validate_first_field();
    modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    first.FromString(ui->lineEdit_first->text().toStdString());
    first.mod(modulus);
}

void FiniteFieldWindow::set_ans(const std::string& ans) {
    ui->lineEdit_ans->setText(QString::fromStdString(ans));
}

void FiniteFieldWindow::set_ans(const IntModulo& ans) {
    ui->lineEdit_ans->setText(QString::number(ans.get_num()));
}

void FiniteFieldWindow::set_ans(long long ans) {
    ui->lineEdit_ans->setText(QString::number(ans));
}

void FiniteFieldWindow::on_pushButton_add_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        first.add(second, modulus);
        window->set_ans(first);
        return;
    }, this);
}


void FiniteFieldWindow::on_pushButton_substract_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        first.subtract(second, modulus);
        window->set_ans(first);
    }, this);
}


void FiniteFieldWindow::on_pushButton_multiply_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        first.multiply(second, modulus);
        window->set_ans(first);
    }, this);
}


void FiniteFieldWindow::on_pushButton_pow_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        window->validate_second_field();
        long long exponent = std::stoll(window->ui->lineEdit_second->text().toStdString());
        first.pow(exponent, modulus);
        window->set_ans(first);
    }, this);
}


void FiniteFieldWindow::on_pushButton_divide_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first, second;
        unsigned long long modulus;
        window->read_and_mod(first, second, modulus);
        first.divide(second, modulus);
        window->set_ans(first);
    }, this);
}


void FiniteFieldWindow::on_pushButton_reverse_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        IntModulo ans = first.findReversed(modulus);
        if (ans.get_num() == 0) {
            window->set_ans("Елемент немає оберненого");
        }
        else {
            window->set_ans(ans);
        }
    }, this);
}


void FiniteFieldWindow::on_pushButton_factorization_Pollard_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        std::map<long long, int> map_ans = PollardFactorization::factorize(first.get_num());
        QString ans = "";
        for (auto val : map_ans) {
            ans += "(" + QString::number(val.first) + "^" + QString::number(val.second) + ")";
        }
        window->set_ans(ans.toStdString());
    }, this);
}


void FiniteFieldWindow::on_pushButton_is_prime_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        window->validate_second_field();
        int iterations_num = std::stoi(window->ui->lineEdit_second->text().toStdString());
        if(first.isPrime(iterations_num)) {
            window->set_ans("Так, число є простим");
        }
        else {
            window->set_ans("Ні, число не є простим");
        }
    }, this);
}


void FiniteFieldWindow::on_pushButton_euler_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        long long ans = first.phi();
        window->set_ans(ans);
    }, this);
}


void FiniteFieldWindow::on_pushButton_carmichael_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        long long ans = first.carmichael();
        window->set_ans(ans);
    }, this);
}


void FiniteFieldWindow::on_pushButton_discreteLogarithm_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo base, arg;
        unsigned long long modulus;
        window->read_and_mod(arg, base, modulus);
        /*int ans = discreteLogarithm(base.get_num(), arg.get_num(), modulus);
        window->set_ans(ans);*/
        std::vector<int> answers = discreteLogarithm(base.get_num(), arg.get_num(), modulus);
        QString ans = "";
        for(std::size_t i = 0; i < answers.size(); i++) {
          ans += QString::number(answers[i]) + " ";
        }
        window->set_ans(ans.toStdString());
    }, this);
}

void FiniteFieldWindow::on_pushButton_discreteLogarithm2_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo base, arg;
        unsigned long long modulus;
        window->read_and_mod(arg, base, modulus);
        std::vector<long long> answers = discreteLogarithm2(base.get_num(), arg.get_num(), modulus);
        QString ans = "";
        for(std::size_t i = 0; i < answers.size(); i++) {
          ans += QString::number(answers[i]) + " ";
        }
        window->set_ans(ans.toStdString());
    }, this);
}

void FiniteFieldWindow::on_pushButton_elementOrder_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        FindGroup group(modulus);
        IntModulo ans = group.ElementOrder(first);
        if (ans.get_num() == 0) {
            window->set_ans("Елемент має нескінченний порядок");
        }
        else {
            window->set_ans(ans);
        }
    }, this);
}


void FiniteFieldWindow::on_pushButton_is_generator_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo first;
        unsigned long long modulus;
        window->read_and_mod(first, modulus);
        FindGroup group(modulus);
        if(group.FindGroupGenerator(first.get_num())) {
            window->set_ans("Так, є генератором");
        }
        else {
            window->set_ans("Ні, не є генератором");
        }
    }, this);
}


void FiniteFieldWindow::on_pushButton_sqrt_clicked()
{
    evaluate_func([](FiniteFieldWindow* window) {
        IntModulo input;
        unsigned long long modulus;
        window->read_and_mod(input, modulus);
        std::set<long long> answers = IntModulo(input).sqrt(modulus);
        if (answers.size() == 0) {
            window->set_ans("Коренів немає");
        }
        else {
            QString ans_str =  "";
            for (auto ans : answers) {
                ans_str += QString::number(ans) + " ";
            }
            window->set_ans(ans_str.toStdString());
        }
    }, this);
}


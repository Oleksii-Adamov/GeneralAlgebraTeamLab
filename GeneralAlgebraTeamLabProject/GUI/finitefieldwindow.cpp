#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"
#include <string>
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <limits>
#include "task1/intmodulo.h"
#include "task5/pollardfactorization.h"
#include "task8/findgroup.h"
#include "task7/discrete_logarithm.h"

FiniteFieldWindow::FiniteFieldWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FiniteFieldWindow)
{
    ui->setupUi(this);
    QRegularExpression rx("^[0-9]+$");
    QValidator* validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit_modulus->setValidator(validator);
    ui->lineEdit_first->setValidator(validator);
    ui->lineEdit_second->setValidator(validator);
}

FiniteFieldWindow::~FiniteFieldWindow()
{
    delete ui;
}

void FiniteFieldWindow::read_and_mod(IntModulo& first, IntModulo& second, unsigned long long& modulus) {
    //try {
        first.FromString(ui->lineEdit_first->text().toStdString());
        second.FromString(ui->lineEdit_second->text().toStdString());
        modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
        first.mod(modulus);
        second.mod(modulus);
    //}
   // catch(std::exception& e) {
     //   set_ans(e.what());
    //}
}

void FiniteFieldWindow::read_and_mod(IntModulo& first, unsigned long long& modulus) {
    try {
        first.FromString(ui->lineEdit_first->text().toStdString());
        modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
        first.mod(modulus);
    }
    catch(std::exception& e) {
        set_ans(e.what());
    }
}

void FiniteFieldWindow::set_ans(const std::string& ans) {
    ui->lineEdit_ans->setText(QString::fromStdString(ans));
}

/*void FiniteFieldWindow::set_ans(const QString& ans) {
    ui->lineEdit_ans->setText(ans);
}*/

void FiniteFieldWindow::set_ans(const IntModulo& ans) {
    ui->lineEdit_ans->setText(QString::number(ans.get_num()));
}

void FiniteFieldWindow::set_ans(long long ans) {
    ui->lineEdit_ans->setText(QString::number(ans));
}

void FiniteFieldWindow::on_pushButton_add_clicked()
{
    try {
        IntModulo first, second;
        unsigned long long modulus;
        read_and_mod(first, second, modulus);
        first.add(second, modulus);
        set_ans(first);
    }
    catch(std::exception& e) {
        std::string message = e.what();
        if (message == "modulus = 0") {
            message = "Модуль = 0";
        }
        set_ans(message);
    }
}


void FiniteFieldWindow::on_pushButton_substract_clicked()
{
    try {
        IntModulo first, second;
        unsigned long long modulus;
        read_and_mod(first, second, modulus);
        first.subtract(second, modulus);
        set_ans(first);
    }
    catch(std::exception& e) {
        set_ans(e.what());
    }
}


void FiniteFieldWindow::on_pushButton_multiply_clicked()
{
    IntModulo first, second;
    unsigned long long modulus;
    read_and_mod(first, second, modulus);
    first.multiply(second, modulus);
    set_ans(first);
}


void FiniteFieldWindow::on_pushButton_pow_clicked()
{
    IntModulo first;
    unsigned long long modulus, exponent = std::stoull(ui->lineEdit_second->text().toStdString());
    read_and_mod(first, modulus);
    first.pow(exponent, modulus);
    set_ans(first);
}


void FiniteFieldWindow::on_pushButton_divide_clicked()
{
    IntModulo first, second;
    unsigned long long modulus;
    read_and_mod(first, second, modulus);
    try {
        first.divide(second, modulus);
        set_ans(first);
    }
    catch(std::logic_error& e) {
       set_ans("Дільник немає оберненого");
    }
}


void FiniteFieldWindow::on_pushButton_reverse_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    IntModulo ans = first.findReversed(modulus);
    if (ans.get_num() == 0) {
        set_ans("Елемент немає оберненого");
    }
    else {
        set_ans(ans);
    }
}


void FiniteFieldWindow::on_pushButton_factorization_Pollard_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    try {
        std::map<long long, int> map_ans = PollardFactorization::factorize(first.get_num());
        QString ans = "";
        for (auto val : map_ans) {
            ans += QString::number(val.first) + " " + QString::number(val.second);
        }
        set_ans(ans.toStdString());
    }
    catch(std::invalid_argument& e) {
        set_ans("Число меньше 1");
    }
}


void FiniteFieldWindow::on_pushButton_is_prime_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    int iterations_num;
    try {
        iterations_num = std::stoi(ui->lineEdit_second->text().toStdString());
    }
    catch(std::exception& e) {
        set_ans("Кількість ітерацій не введена (друге поле)");
        return;
    }

    if(first.isPrime(iterations_num)) {
        set_ans("Так, число є простим");
    }
    else {
        set_ans("Ні, число не є простим");
    }
}


void FiniteFieldWindow::on_pushButton_euler_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    try {
        long long ans = first.phi();
        set_ans(ans);
    }
    catch(std::exception& e) {
        if (std::string(e.what()) == std::string("Num can`t be less than 1.")) {
            set_ans("Число не може бути меньшим за 1");
        }
        else {
            set_ans(e.what());
        }
    }
}


void FiniteFieldWindow::on_pushButton_carmichael_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    long long ans = first.carmichael();
    set_ans(ans);
}


void FiniteFieldWindow::on_pushButton_discreteLogarithm_clicked()
{
    IntModulo base, arg;
    unsigned long long modulus;
    read_and_mod(arg, base, modulus);
    int ans = discreteLogarithm2(base.get_num(), arg.get_num(), modulus);
    set_ans(ans);
}


void FiniteFieldWindow::on_pushButton_elementOrder_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    FindGroup group(modulus);
    IntModulo ans = group.ElementOrder(first);
    if (ans.get_num() == 0) {
        set_ans("Елемент має нескінченний порядок");
    }
    else {
        set_ans(ans);
    }
}


void FiniteFieldWindow::on_pushButton_is_generator_clicked()
{
    IntModulo first;
    unsigned long long modulus;
    read_and_mod(first, modulus);
    FindGroup group(modulus);
    if(group.FindGroupGenerator(first.get_num())) {
        set_ans("Так, є генератором");
    }
    else {
        set_ans("Ні, не є генератором");
    }
}


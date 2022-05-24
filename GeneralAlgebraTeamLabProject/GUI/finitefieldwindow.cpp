#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"
#include <string>
#include <QRegularExpressionValidator>
#include "task1/intmodulo.h"
#include "task5/pollardfactorization.h"

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
    first.FromString(ui->lineEdit_first->text().toStdString());
    second.FromString(ui->lineEdit_second->text().toStdString());
    modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    first.mod(modulus);
    second.mod(modulus);
}

void FiniteFieldWindow::read_and_mod(IntModulo& first, unsigned long long& modulus) {
    first.FromString(ui->lineEdit_first->text().toStdString());
    modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    first.mod(modulus);
}

void FiniteFieldWindow::set_ans(const QString& ans) {
    ui->lineEdit_ans->setText(ans);
}

void FiniteFieldWindow::set_ans(IntModulo& ans) {
    ui->lineEdit_ans->setText(QString::number(ans.get_num()));
}

void FiniteFieldWindow::on_pushButton_add_clicked()
{
    IntModulo first, second;
    unsigned long long modulus;
    read_and_mod(first, second, modulus);
    first.add(second, modulus);
    set_ans(first);
}


void FiniteFieldWindow::on_pushButton_substract_clicked()
{
    IntModulo first, second;
    unsigned long long modulus;
    read_and_mod(first, second, modulus);
    first.subtract(second, modulus);
    set_ans(first);
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
        set_ans(ans);
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


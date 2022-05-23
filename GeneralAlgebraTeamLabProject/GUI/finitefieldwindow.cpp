#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"
#include <string>
#include <QRegularExpressionValidator>
#include "task1/intmodulo.h"


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

void FiniteFieldWindow::on_pushButton_add_clicked()
{
    IntModulo first, second;
    unsigned long long modulus;
    read_and_mod(first, second, modulus);
    first.add(second, modulus);
    set_ans(QString::number(first.get_num()));
}


void FiniteFieldWindow::on_pushButton_substract_clicked()
{
    IntModulo first, second;
    unsigned long long modulus;
    read_and_mod(first, second, modulus);
    first.subtract(second, modulus);
    set_ans(QString::number(first.get_num()));
}


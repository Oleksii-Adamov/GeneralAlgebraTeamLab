#include "polynomialringwindow.h"
#include "ui_polynomialringwindow.h"
#include "task11/polinome.h"
#include <QRegularExpressionValidator>

PolynomialRingWindow::PolynomialRingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PolynomialRingWindow)
{
    ui->setupUi(this);
    //QRegularExpression rx(/*"^[0-9x ]+$"*/"/[0-9]*[ ]*[x]+[ ]*[+]?[ ]*/");
    //QValidator* validator = new QRegularExpressionValidator(rx, this);
    //ui->lineEdit_modulus->setValidator(validator);
    //ui->lineEdit_first->setValidator(validator);
    //ui->lineEdit_second->setValidator(validator);
}

PolynomialRingWindow::~PolynomialRingWindow()
{
    delete ui;
}

void PolynomialRingWindow::on_pushButton_add_clicked()
{


    try {
        Polinome first(ui->lineEdit_first->text().toStdString());
        Polinome second(ui->lineEdit_second->text().toStdString());
        unsigned long long modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
        Polinome ans = first.add(second, modulus);
        ui->lineEdit_ans->setText(QString::fromStdString(ans.toString()));
    }
    catch(std::exception& e) {
        ui->lineEdit_ans->setText(e.what());
    }
}


void PolynomialRingWindow::on_pushButton_evaluate_clicked()
{
    Polinome first(ui->lineEdit_first->text().toStdString());
    unsigned long long modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    IntModulo point(ui->lineEdit_second->text().toStdString());
    point.mod(modulus);
    IntModulo ans = first.evaluate(point, modulus);
    ui->lineEdit_ans->setText(QString::number(ans.get_num()));
}


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

    unsigned long long modulus;
    try {
        Polinome first(ui->lineEdit_first->text().toStdString());
        Polinome second(ui->lineEdit_second->text().toStdString());
        modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
        Polinome ans = first.add(second, modulus);
        ui->lineEdit_ans->setText(QString::fromStdString(ans.toString()));
    }
    catch(std::exception& e) {
        ui->lineEdit_ans->setText(e.what());
    }
}


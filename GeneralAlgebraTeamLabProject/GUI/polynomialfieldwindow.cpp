#include "polynomialfieldwindow.h"
#include "ui_polynomialfieldwindow.h"
#include "task20/generator.h"
PolynomialFieldWindow::PolynomialFieldWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PolynomialFieldWindow)
{
    ui->setupUi(this);
}

PolynomialFieldWindow::~PolynomialFieldWindow()
{
    delete ui;
}

void PolynomialFieldWindow::on_pushButton_order_clicked()
{
    Polinome irreducible(ui->lineEdit_irreducible->text().toStdString());
    unsigned long long modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    Polinome input(ui->lineEdit_first->text().toStdString());
    int ans = orderOfPolinome(modulus, irreducible, input);
    ui->lineEdit_ans->setText(QString::number(ans));
}


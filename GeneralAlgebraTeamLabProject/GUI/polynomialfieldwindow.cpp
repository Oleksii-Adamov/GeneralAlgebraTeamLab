#include "polynomialfieldwindow.h"
#include "ui_polynomialfieldwindow.h"
#include "task15/ri.h"
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


void PolynomialFieldWindow::on_pushButton_CyclFact_clicked()
{
    unsigned long long modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    unsigned long long number_of_cycl_pol =  std::stoull(ui->lineEdit_first->text().toStdString());
    std::vector<Polinome> fact  = computePolynomialProductOfCyclotomicPlynomial(modulus, number_of_cycl_pol);
    std::string ans = "";
    for (std::size_t i = 0; i < fact.size(); i++) {
        ans += "(" + fact[i].toString() + ")";
    }
    ui->lineEdit_ans->setText(QString::fromStdString(ans));
}


void PolynomialFieldWindow::on_pushButton_is_irreducible_clicked()
{
    unsigned long long modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    Polinome input(ui->lineEdit_first->text().toStdString());
    //std::vector<Polinome> coefs =
    if(checkIrreducibilty(*(input.getCoefficients()), modulus)) {
        ui->lineEdit_ans->setText("Так, є незвідним");
    }
    else {
        ui->lineEdit_ans->setText("Ні, не є незвідним");
    }
}


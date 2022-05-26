#include "polynomialfieldwindow.h"
#include "ui_polynomialfieldwindow.h"

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

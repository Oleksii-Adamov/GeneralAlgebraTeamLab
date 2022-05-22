#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"
#include <string>
#include "task1/intmodulo.h"


FiniteFieldWindow::FiniteFieldWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FiniteFieldWindow)
{
    ui->setupUi(this);
    ui->verticalLayout->setAlignment(Qt::AlignHCenter);
}

FiniteFieldWindow::~FiniteFieldWindow()
{
    delete ui;
}

void FiniteFieldWindow::on_pushButton_add_clicked()
{
    IntModulo first(ui->lineEdit_first->text().toStdString());
    IntModulo second(ui->lineEdit_second->text().toStdString());
    unsigned long long modulus = std::stoull(ui->lineEdit_modulus->text().toStdString());
    first.mod(modulus);
    second.mod(modulus);
    first.add(second, modulus);
    ui->lineEdit_ans->setText(QString::number(first.get_num()));
}


void FiniteFieldWindow::on_pushButton_substract_clicked()
{

}


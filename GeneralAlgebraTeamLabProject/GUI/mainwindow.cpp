#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include "testlib.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_PolynomialRings_clicked()
{
    TestLib a;
    a.set_i(2);
    qDebug() << a.get_i();
}


void MainWindow::on_pushButton_FiniteField_clicked()
{
    TestLib a;
    a.set_i(1);
    qDebug() << a.get_i();
}


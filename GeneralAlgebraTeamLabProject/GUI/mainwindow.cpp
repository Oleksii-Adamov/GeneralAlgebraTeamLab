#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finitefieldwindow.h"
#include "polynomialringwindow.h"
#include "polynomialfieldwindow.h"
#include <QDebug>

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
    PolynomialRingWindow* new_window = new PolynomialRingWindow(this);
    new_window->show();
}


void MainWindow::on_pushButton_FiniteField_clicked()
{
    FiniteFieldWindow* new_window = new FiniteFieldWindow(this);
    //new_window->setWindowModality(Qt::WindowModal);
    new_window->show();
}


void MainWindow::on_pushButton_PolynomialField_clicked()
{
    PolynomialFieldWindow* new_window = new PolynomialFieldWindow(this);
    new_window->show();
}


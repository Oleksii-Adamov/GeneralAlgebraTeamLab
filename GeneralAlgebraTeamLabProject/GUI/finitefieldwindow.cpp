#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"

FiniteFieldWindow::FiniteFieldWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiniteFieldWindow)
{
    ui->setupUi(this);
}

FiniteFieldWindow::~FiniteFieldWindow()
{
    delete ui;
}

#include "finitefieldwindow.h"
#include "ui_finitefieldwindow.h"

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

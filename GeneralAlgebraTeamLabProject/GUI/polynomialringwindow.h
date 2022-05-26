#ifndef POLYNOMIALRINGWINDOW_H
#define POLYNOMIALRINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class PolynomialRingWindow;
}

class PolynomialRingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PolynomialRingWindow(QWidget *parent = nullptr);
    ~PolynomialRingWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_evaluate_clicked();

    void on_pushButton_derivative_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_gcd_clicked();

private:
    Ui::PolynomialRingWindow *ui;
};

#endif // POLYNOMIALRINGWINDOW_H

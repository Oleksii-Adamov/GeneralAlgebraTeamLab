#ifndef POLYNOMIALRINGWINDOW_H
#define POLYNOMIALRINGWINDOW_H

#include "abstractguishowexceptionwindow.h"
#include "task1/intmodulo.h"
#include "task11/polinome.h"

namespace Ui {
class PolynomialRingWindow;
}

class PolynomialRingWindow : public AbstractGuiShowExceptionWindow
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

    void on_pushButton_CyclotomicPolynomial_clicked();

    void on_pushButton_subtract_clicked();

    void on_pushButton_multiply_clicked();

private:
    Ui::PolynomialRingWindow *ui;
    void evaluate_func(std::function<void(PolynomialRingWindow*)> func, PolynomialRingWindow* context);
    void show_exception(const std::string& message) override;
    void set_ans(const IntModulo& ans);
    void set_ans(const Polinome& ans);
    void set_ans(const std::string& ans);
    void validate_modulus_field();
    void read_and_mod(Polinome& first, Polinome& second, unsigned long long& modulus);
    void read_and_mod(Polinome& first, unsigned long long& modulus);
};

#endif // POLYNOMIALRINGWINDOW_H

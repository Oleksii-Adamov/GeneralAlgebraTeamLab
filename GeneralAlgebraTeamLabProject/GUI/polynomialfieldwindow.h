#ifndef POLYNOMIALFIELDWINDOW_H
#define POLYNOMIALFIELDWINDOW_H

#include "abstractguishowexceptionwindow.h"
#include "task11/polinome.h"

namespace Ui {
class PolynomialFieldWindow;
}

class PolynomialFieldWindow : public AbstractGuiShowExceptionWindow
{
    Q_OBJECT

public:
    explicit PolynomialFieldWindow(QWidget *parent = nullptr);
    ~PolynomialFieldWindow();

private slots:
    void on_pushButton_order_clicked();

    void on_pushButton_CyclFact_clicked();

    void on_pushButton_is_irreducible_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_subtract_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_reduce_clicked();

private:
    Ui::PolynomialFieldWindow *ui;
    void evaluate_func(std::function<void(PolynomialFieldWindow*)> func, PolynomialFieldWindow* context);
    void show_exception(const std::string& message) override;
    void set_ans(const int ans);
    void set_ans(const Polinome& ans);
    void set_ans(const std::string& ans);
    void validate_modulus_field();
    void read_and_mod(Polinome& first, Polinome& second, Polinome& irreducible, unsigned long long& modulus);
    void read_and_mod(Polinome& first, Polinome& irreducible, unsigned long long& modulus);
};

#endif // POLYNOMIALFIELDWINDOW_H

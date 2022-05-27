#ifndef FINITEFIELDWINDOW_H
#define FINITEFIELDWINDOW_H

#include <QMainWindow>
#include "abstractguishowexceptionwindow.h"
#include "task1/intmodulo.h"


namespace Ui {
class FiniteFieldWindow;
}

class FiniteFieldWindow : public AbstractGuiShowExceptionWindow
{
    Q_OBJECT

public:
    explicit FiniteFieldWindow(QWidget *parent = nullptr);
    ~FiniteFieldWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_substract_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_reverse_clicked();

    void on_pushButton_factorization_Pollard_clicked();

    void on_pushButton_is_prime_clicked();

    void on_pushButton_euler_clicked();

    void on_pushButton_carmichael_clicked();

    void on_pushButton_discreteLogarithm_clicked();

    void on_pushButton_elementOrder_clicked();

    void on_pushButton_is_generator_clicked();

    void on_pushButton_discreteLogarithm2_clicked();

private:
    void read_and_mod(IntModulo& first, IntModulo& second, unsigned long long& modulus);
    void read_and_mod(IntModulo& first, unsigned long long& modulus);
    Ui::FiniteFieldWindow *ui;
    void set_ans(const IntModulo& ans);
    void set_ans(long long ans);
    void set_ans(const std::string& ans);
    void evaluate_func(std::function<void(FiniteFieldWindow*)> func, FiniteFieldWindow* context);
    void add();
    void show_exception(const std::string& message) override;
};

#endif // FINITEFIELDWINDOW_H

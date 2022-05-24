#ifndef FINITEFIELDWINDOW_H
#define FINITEFIELDWINDOW_H

#include <QMainWindow>
#include "task1/intmodulo.h"

namespace Ui {
class FiniteFieldWindow;
}

class FiniteFieldWindow : public QMainWindow
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

private:
    void read_and_mod(IntModulo& first, IntModulo& second, unsigned long long& modulus);
    void read_and_mod(IntModulo& first, unsigned long long& modulus);
    void set_ans(const QString& ans);
    void set_ans(IntModulo& ans);
    Ui::FiniteFieldWindow *ui;
};

#endif // FINITEFIELDWINDOW_H

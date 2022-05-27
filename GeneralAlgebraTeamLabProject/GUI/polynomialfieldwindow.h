#ifndef POLYNOMIALFIELDWINDOW_H
#define POLYNOMIALFIELDWINDOW_H

#include <QMainWindow>

namespace Ui {
class PolynomialFieldWindow;
}

class PolynomialFieldWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PolynomialFieldWindow(QWidget *parent = nullptr);
    ~PolynomialFieldWindow();

private slots:
    void on_pushButton_order_clicked();

    void on_pushButton_CyclFact_clicked();

    void on_pushButton_is_irreducible_clicked();

private:
    Ui::PolynomialFieldWindow *ui;
};

#endif // POLYNOMIALFIELDWINDOW_H
#ifndef FINITEFIELDWINDOW_H
#define FINITEFIELDWINDOW_H

#include <QMainWindow>

namespace Ui {
class FiniteFieldWindow;
}

class FiniteFieldWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FiniteFieldWindow(QWidget *parent = nullptr);
    ~FiniteFieldWindow();

private:
    Ui::FiniteFieldWindow *ui;
};

#endif // FINITEFIELDWINDOW_H

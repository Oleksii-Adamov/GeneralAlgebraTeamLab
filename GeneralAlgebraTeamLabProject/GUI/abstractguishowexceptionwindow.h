#ifndef ABSTRACTGUISHOWEXCEPTIONWINDOW_H
#define ABSTRACTGUISHOWEXCEPTIONWINDOW_H
#include <QMainWindow>
class AbstractGuiShowExceptionWindow : public QMainWindow
{
    Q_OBJECT

public:
    AbstractGuiShowExceptionWindow(QWidget *parent = nullptr);
private:
    virtual  void evaluate_func(std::function<void(AbstractGuiShowExceptionWindow*)> func,
                                AbstractGuiShowExceptionWindow* context) {

    }
};
#endif // ABSTRACTGUISHOWEXCEPTIONWINDOW_H

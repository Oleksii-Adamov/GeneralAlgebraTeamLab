#ifndef ABSTRACTGUISHOWEXCEPTIONWINDOW_H
#define ABSTRACTGUISHOWEXCEPTIONWINDOW_H
#include <QMainWindow>
class AbstractGuiShowExceptionWindow : public QMainWindow
{
    Q_OBJECT

public:
    AbstractGuiShowExceptionWindow(QWidget *parent = nullptr) :
        QMainWindow(parent)
    {

    }
protected:
    virtual void show_exception(const std::string& message) = 0;
    virtual void evaluate_base_func(std::function<void(AbstractGuiShowExceptionWindow*)> func,
                                AbstractGuiShowExceptionWindow* context) {
        try {
            func(context);
        }
        catch(std::exception& e) {
            std::string message = e.what();
            if (message == "modulus = 0") {
                message = "Модуль = 0";
            }
            if (message == "divider has no reverse") {
                message = "Дільник немає оберненого";
            }
            show_exception(message);
        }
    }
};
#endif // ABSTRACTGUISHOWEXCEPTIONWINDOW_H

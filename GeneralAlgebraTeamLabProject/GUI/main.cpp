#include "mainwindow.h"
#include <QApplication>
#include "finitefieldwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int ret;
    app_exec:
    try {
        ret = a.exec();
    }
    catch (std::exception& e){
        std::string message = e.what();
        if (message == "modulus = 0") {
            message = "Модуль = 0";
        }
        auto active_window = a.activeWindow();
        FiniteFieldWindow* ffw = dynamic_cast<FiniteFieldWindow*>(active_window);
        if (ffw != nullptr) {
            ffw->set_ans(message);
        }
        goto app_exec;
    }
    return ret;
}

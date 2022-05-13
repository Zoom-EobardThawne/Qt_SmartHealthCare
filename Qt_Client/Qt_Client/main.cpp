#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login loginwindow;
    loginwindow.show();

    return a.exec();
}

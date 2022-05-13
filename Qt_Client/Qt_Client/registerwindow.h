#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include "passwordwindow.h"

#define REGISTER_SUCCESS_STATE 0
#define REGISTER_USERNAME_FAILE 1
#define REGISTER_TELPHONE_FAILE 2

namespace Ui {
class registerWindow;
}

class registerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit registerWindow(QWidget *parent = 0);
    ~registerWindow();

signals:
    void userRegister(const QStringList registerList);

private slots:
    void on_registerPushButton_clicked();

    void registerStateHandle(int state);
private:
    Ui::registerWindow *ui;
  
};

#endif // REGISTERWINDOW_H

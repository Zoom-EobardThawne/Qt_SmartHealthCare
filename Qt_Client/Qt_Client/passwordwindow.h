#ifndef PASSWORDWINDOW_H
#define PASSWORDWINDOW_H

#include <QMainWindow>

#define GET_PASSWORD_SUCCESS_STATE 0
#define GET_PASSWORD_FAILE_STATE 1
#define PASSWORD_USER true
#define PASSWORD_DOCTOR false

namespace Ui {
class PasswordWindow;
}

class PasswordWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PasswordWindow(QWidget *parent = 0);
    ~PasswordWindow();

signals:
    void passwordRetrieve(const QString username,const QString telphone,const QString ID);
    void passwordDoctorRetrieve(const QString username,const QString telphone,const QString ID);

private slots:
    void on_retrievePasswordPushButton_clicked();
    void getPasswordStateHandle(int state , const QString &password);

    void on_userRadioButton_clicked();

    void on_doctorRadioButton_clicked();

private:
    Ui::PasswordWindow *ui;
    bool passwordRole;
};

#endif // PASSWORDWINDOW_H

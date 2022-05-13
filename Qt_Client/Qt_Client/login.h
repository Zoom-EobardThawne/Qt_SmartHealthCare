#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "registerwindow.h"
#include "doctorregisterwindow.h"

#define LOGIN_SUCCESS_STATE 0
#define LOGIN_FAILE_STATE  1

#define LOGIN_USER true
#define LOGIN_DOCTOR false


namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

    static QString loginUser;
    static QString loginDoctor;
private slots:
    void on_pushButton_clicked();
    void loginstateHandle(int state);
    void on_RegistrationPushbutton_clicked();

    
    void on_RegistrationPushbutton_2_clicked();

    void on_userRadioButton_clicked();

    void on_doctorRadioButton_clicked();


    void on_comboBox_activated(int index);

signals:
    void userLogin(const QString username,const QString password);
    void doctorLogin(const QString username,const QString password);

private:
      Ui::login *ui;
      registerWindow *registerwindow;
      PasswordWindow *passwordwindow;
      DoctorRegisterWindow *doctorRegisterWindow;
      bool loginRole;
      bool registerRole;

};

#endif // LOGIN_H

#include "passwordwindow.h"
#include "ui_passwordwindow.h"
#include <QMessageBox>

PasswordWindow::PasswordWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PasswordWindow)
{
    ui->setupUi(this);
    passwordRole = PASSWORD_USER;
}

PasswordWindow::~PasswordWindow()
{
    delete ui;
}

void PasswordWindow::on_retrievePasswordPushButton_clicked()
{
    QString username =ui->UsernameLineEdit->text();
    if(username.isEmpty()){

        QMessageBox::warning(NULL,"密码找回","请输入用户名后重试",QMessageBox::Ok);
        return;
    }
    QString telphone =ui->TelphoneLineEdit->text();
    if(telphone.isEmpty()){

        QMessageBox::warning(NULL,"密码找回","请输入电话号后重试",QMessageBox::Ok);
        return;
    }
    QString ID = ui->IDLineEdit->text();
    if(ID.isEmpty()){

        QMessageBox::warning(NULL,"密码找回","请输入身份证号后重试",QMessageBox::Ok);
        return;
    }
    if(passwordRole==PASSWORD_USER){
        emit passwordRetrieve(username,telphone,ID);
    }
    else if(passwordRole==PASSWORD_DOCTOR){
        emit passwordDoctorRetrieve(username,telphone,ID);
    }
}

void PasswordWindow::getPasswordStateHandle(int state, const QString &password)
{
    QString message;
    if(state ==GET_PASSWORD_SUCCESS_STATE){

        message="密码找回成功！密码："+password;
    }else if(state == GET_PASSWORD_FAILE_STATE){

        message = "找回密码失败！请查看信息是否输入正确！";

    }
    QMessageBox::warning(NULL,"注册",message,QMessageBox::Ok);
    return ;
    
}



void PasswordWindow::on_userRadioButton_clicked()
{
    passwordRole=PASSWORD_USER;
}

void PasswordWindow::on_doctorRadioButton_clicked()
{
    passwordRole=PASSWORD_DOCTOR;
}

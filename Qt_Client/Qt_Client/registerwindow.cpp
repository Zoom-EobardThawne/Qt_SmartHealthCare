#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "userverify.h"
#include <QString>
#include <QMessageBox>
#include<QStringList>

registerWindow::registerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
    
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::on_registerPushButton_clicked()
{
    QStringList registerList ;
    registerList<< ui->usernameLineEdit->text();
    if(registerList[0]==NULL){

        QMessageBox::warning(NULL,"注册","请输入用户名",QMessageBox::Ok);
        return;
    }
    registerList<<ui->passwordLineEdit->text();
    if(registerList[1]==NULL){

        QMessageBox::warning(NULL,"注册","请输入密码",QMessageBox::Ok);
        return;
    }
    registerList <<ui->telphoneLineEdit->text();
    if(registerList[2]==NULL){

        QMessageBox::warning(NULL,"注册","请输入电话号",QMessageBox::Ok);
        return;
    }
   registerList <<ui->RealNameLineEdit->text();
    if(registerList[3]==NULL){

        QMessageBox::warning(NULL,"注册","请输入真实姓名",QMessageBox::Ok);
        return;
    }
    registerList<<ui->IDLineEdit->text();
    if(registerList[4]==NULL){

        QMessageBox::warning(NULL,"注册","请输入真实姓名",QMessageBox::Ok);
        return;
    }
    emit userRegister(registerList);
}

void registerWindow::registerStateHandle(int state)
{
    QString message;
    if(state ==REGISTER_SUCCESS_STATE){

        message="注册成功！";
    }else if(state == REGISTER_USERNAME_FAILE){

        message = "用户名已存在，请重新输入！";

    }else if(state ==REGISTER_TELPHONE_FAILE){

        message = "电话号已被注册，请重新输入！";
    }
    QMessageBox::warning(NULL,"注册",message,QMessageBox::Ok);
    return ;
}




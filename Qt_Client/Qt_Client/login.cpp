#include "login.h"
#include "ui_login.h"
#include "userverify.h"
#include <QString>
#include <QMessageBox>
#include "mainwindow.h"
#include "registerwindow.h"
#include "doctorregisterwindow.h"
#include <qdebug.h>
#include "doctormainwindow.h"

QString login::loginUser;
QString login::loginDoctor;

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    registerwindow = new registerWindow;
    passwordwindow =new PasswordWindow;
    doctorRegisterWindow =new DoctorRegisterWindow;

    Userverify *userVerify=new Userverify;
    connect(this,SIGNAL(userLogin(QString,QString)),userVerify,SLOT(verifyUserNamePassword(QString,QString)));
    connect(this,SIGNAL(doctorLogin(QString,QString)),userVerify,SLOT(verifyDoctorNamePassword(QString,QString)));
    connect(userVerify,SIGNAL(loginState(int)),this,SLOT(loginstateHandle(int)));

    connect(registerwindow,SIGNAL(userRegister(QStringList)),userVerify,SLOT(verifyRegisterInformation(QStringList)));

    connect(userVerify,SIGNAL(registerState(int)),registerwindow,SLOT(registerStateHandle(int)));
    connect(passwordwindow,SIGNAL(passwordRetrieve(QString,QString,QString)),userVerify,SLOT(verifyUserGetPassword(QString,QString,QString)));
    connect(passwordwindow,SIGNAL(passwordDoctorRetrieve(QString,QString,QString)),userVerify,SLOT(verifyDoctorGetPassword(QString,QString,QString)));

    connect(userVerify,SIGNAL(getPasswordState(int,QString)),passwordwindow,SLOT(getPasswordStateHandle(int,QString)));

    loginRole =LOGIN_USER;


}

login::~login()
{
    delete ui;
    delete registerwindow;
    delete passwordwindow;
    delete doctorRegisterWindow;
}

void login::on_pushButton_clicked()
{
    QString username =ui->NameLineEdit->text();
    if(username.isEmpty()){

        QMessageBox::warning(NULL,"登录","请输入账号后登录",QMessageBox::Ok);
        return;
    }
    QString password =ui->PasswordLineEdit->text();
    if(password.isEmpty()){

        QMessageBox::warning(NULL,"登录","请输入密码后登录",QMessageBox::Ok);
        return;
    }

    if(loginRole==LOGIN_USER){
        emit userLogin(username,password);
    }
    else if(loginRole==LOGIN_DOCTOR)
    {
        emit doctorLogin(username,password);

    }
}
void login::loginstateHandle(int state){

    if(state==LOGIN_FAILE_STATE){
        QMessageBox::warning(NULL,"登录","用户名或密码错误，请输入正确的用户名或密码！",QMessageBox::Ok);
        return;

    }
    else if(state==LOGIN_SUCCESS_STATE&&loginRole==LOGIN_USER ){
        MainWindow *mainWindow = new MainWindow;
        mainWindow->show();
        loginUser=ui->NameLineEdit->text();
        this->close();
        
        
    }
    else if(state==LOGIN_SUCCESS_STATE&&loginRole==LOGIN_DOCTOR){
        doctorMainWindow *doctormainwindow=new doctorMainWindow;
        doctormainwindow->getuserInformation();
        doctormainwindow->show();
        loginDoctor=ui->NameLineEdit->text();
        this->close();

    }
}

void login::on_RegistrationPushbutton_clicked()
{

    if(registerRole==0){
        registerwindow->show();
    }else{
        doctorRegisterWindow-> show();
    }
}


void login::on_RegistrationPushbutton_2_clicked()
{
     passwordwindow->show();
}

void login::on_userRadioButton_clicked()
{
    loginRole =LOGIN_USER;
}

void login::on_doctorRadioButton_clicked()
{
    loginRole =LOGIN_DOCTOR;
}



void login::on_comboBox_activated(int index)
{
    registerRole=index;
}

#include "doctorregisterwindow.h"
#include "ui_doctorregisterwindow.h"
#include<QDir>
#include <QFileDialog>
#include <QDebug>
#include "jaondata.h"
#include "protocal.h"
#include <QMessageBox>



DoctorRegisterWindow::DoctorRegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorRegisterWindow)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplyData()));

}

DoctorRegisterWindow::~DoctorRegisterWindow()
{
    delete ui;
}

void DoctorRegisterWindow::registerDoctor(const QByteArray &data)
{
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
        tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    QByteArray protocolData = Protocal::toProtocalData(data);
    tcpSocket.write(protocolData);
    return;
}

void DoctorRegisterWindow::on_picturePushButton_clicked()
{
    QString currentPath = QDir::currentPath();
    fileName=QFileDialog::getOpenFileName(this,tr("打开图片"),currentPath,tr("Images(*.png *.jpeg *.jpg)"));



    if(!fileName.isEmpty()){

        ui->displayWidget->displayPicture(fileName);
    }

}

void DoctorRegisterWindow::on_registerPushButton_clicked()
{
    JaonData jsonData;
    jsonData.addString("username",ui->usernameLineEdit->text());
    jsonData.addString("password",ui->passwordLineEdit->text());
    jsonData.addString("fullname",ui->realNameLineEdit->text());
    jsonData.addString("telphone",ui->telphoneLineEdit->text());
    jsonData.addString("id",ui->IDLineEdit->text());
    jsonData.addString("major",ui->majorLineEdit->text());
    jsonData.addString("education",ui->educationLineEdit->text());
    jsonData.addString("worktime",ui->workTimeLineEdit->text());
    jsonData.addString("briefIntroduction",ui->briefIntroductionTextEdit->toPlainText());
    jsonData.addInt("function_id",DOCTOR_REGISTER);

    jsonData.addPicture("picture",fileName);

    //QByteArray text=jsonData.toByteArrayData();
    registerDoctor(jsonData.toByteArrayData());

}



void DoctorRegisterWindow::handleReplyData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsondoc;

    jsondoc = QJsonDocument::fromJson(data);
    if(jsondoc.isNull()){
        return ;
    }
    QJsonObject jsonObject = jsondoc.object();
    int state =jsonObject["state"].toInt();

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

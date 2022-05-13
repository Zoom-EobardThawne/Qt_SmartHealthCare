#include "getdoctormessagewindow.h"
#include "ui_getdoctormessagewindow.h"
#include <QJsonObject>
#include "protocal.h"
#include <QJsonDocument>
#include <QMessageBox>
#include<QDebug>
#include <QJsonArray>
#include "login.h"



getDoctorMessageWindow::getDoctorMessageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::getDoctorMessageWindow)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplyData()));
}

getDoctorMessageWindow::~getDoctorMessageWindow()
{
    delete ui;

}

void getDoctorMessageWindow::sendDoctorMessage()
{
    QJsonObject object;
    object["function_id"]=DOCTOR_MESSAGE;
    object["username"]=login::loginUser;
    QJsonDocument jsonDoc(object);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);}
    tcpSocket.write(Protocal::toProtocalData(data));
}

void getDoctorMessageWindow::handleReplyData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;
    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){
        return;
    }

    QJsonObject jsonObject = jsonDoc.object();

    int state = jsonObject["state"].toInt();

    if(state!=0){
        return ;
    }
    QJsonArray dataArray=jsonObject["doctor_opinion"].toArray();
    for(int i=0;i<dataArray.size();i++){
        QJsonObject dataObject=dataArray[i].toObject();
        ui->doctornameLineEdit->setText(dataObject["doctorname"].toString());
        ui->doctorMessageTextEdit->setText(dataObject["opinionTxt"].toString());
    }
}



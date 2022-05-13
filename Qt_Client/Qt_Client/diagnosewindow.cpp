#include "diagnosewindow.h"
#include "ui_diagnosewindow.h"
#include "login.h"
#include <QDebug>
#include "jaondata.h"
#include "protocal.h"
#include <QMessageBox>
#define DOCTOR_OPINION 12

diagnoseWindow::diagnoseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::diagnoseWindow)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplyData()));

}

diagnoseWindow::~diagnoseWindow()
{
    delete ui;
}

void diagnoseWindow::displayWindow()
{
    this->show();
}

void diagnoseWindow::doctorOpinion(const QByteArray &data)
{
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
        tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    QByteArray protocolData = Protocal::toProtocalData(data);
    tcpSocket.write(protocolData);
    return;
}

void diagnoseWindow::on_pushButton_clicked()
{
    JaonData jsonData;
    jsonData.addString("username",login::loginUser);
    jsonData.addString("doctorName",login::loginDoctor);
    jsonData.addString("doctorOpinion",ui->doctorOpinionTextEdit->toPlainText());

    jsonData.addInt("function_id",DOCTOR_OPINION);

    doctorOpinion(jsonData.toByteArrayData());
}

void diagnoseWindow::handleReplyData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsondoc;
    jsondoc = QJsonDocument::fromJson(data);
    if(jsondoc.isNull()){
        return ;
    }
    QJsonObject jsonObject = jsondoc.object();
    int state =jsonObject["state"].toInt();
    if(state==0){
        QMessageBox::warning(NULL,"提交","提交成功",QMessageBox::Ok);
    }
    else{
       QMessageBox::warning(NULL,"提交","提交失败，请稍后重试！",QMessageBox::Ok);
    }
}

#include "datawindow.h"
#include "ui_datawindow.h"
#define PERSON_FEATURE_DATA 9
#include <QJsonArray>
#include <QJsonObject>
#include "protocal.h"
#include <QJsonDocument>
#include <QMessageBox>
#include <QDate>
#include "login.h"
DataWindow::DataWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataWindow)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplyData()));
}

DataWindow::~DataWindow()
{
    delete ui;
}

void DataWindow::cleanWindow()
{
    ui->bloodGluseLineEdit->clear();
    ui->bloodOxygenLineEdit->clear();
    ui->bloodPresureLineEdit->clear();
    ui->heartRateLineEdit->clear();
    ui->temperatureLineEdit->clear();
}

void DataWindow::on_commitPushButton_clicked()
{
    QJsonObject user;
    user["function_id"]=PERSON_FEATURE_DATA;
    user["username"]=login::loginUser;
    user["blood_gluse"]=ui->bloodGluseLineEdit->text();
    user["blood_oxygen"]=ui->bloodOxygenLineEdit->text();
    user["blood_presure"]=ui->bloodPresureLineEdit->text();
    user["heart_rate"]=ui->heartRateLineEdit->text();
    user["temperature"]=ui->temperatureLineEdit->text();
    user["date"]=QDate::currentDate().toString("yyyy-MM-dd");

    QJsonDocument jsonDoc(user);
    QByteArray data =jsonDoc.toJson();

    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
        tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    tcpSocket.write(Protocal::toProtocalData(data));

}

void DataWindow::handleReplyData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;
    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){
        return;
    }

    QString message;

    QJsonObject jsonObject = jsonDoc.object();

    int state = jsonObject["state"].toInt();
    if(state!=0){

        message= QString("提交数据失败，请稍后重试");
    }else if(state == 0){

        message =QString("提交数据成功");

    }
        QMessageBox::warning(NULL,"体征数据",message,QMessageBox::Ok);
    return;

}

QString DataWindow::getUsername() const
{
    return username;
}

void DataWindow::setUsername(const QString &value)
{
    username = value;
}

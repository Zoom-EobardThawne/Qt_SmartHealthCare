#include "doctormainwindow.h"
#include "ui_doctormainwindow.h"
#include <QTableWidgetItem>
#include "appointmentbutton.h"
#include "chartwindow.h"
#include "diagnosewindow.h"
#include "protocal.h"
#include <QJsonObject>
#include "protocal.h"
#include <QJsonDocument>
#include <QMessageBox>
#include<QDebug>
#include <QJsonArray>
#include <string>
#include "user.h"
#include "login.h"
#define USER_INFORMATION_GET 11

doctorMainWindow::doctorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::doctorMainWindow)
{
    ui->setupUi(this);
    diagnosewindow=new diagnoseWindow;
    chartWindow =new ChartWindow;
    initDoctorTableWidget();
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplayData()));
}

doctorMainWindow::~doctorMainWindow()
{
    delete ui;
    delete diagnosewindow;
    delete chartWindow;
}

void doctorMainWindow::adduserInformation(const QList<QString> &list)
{
    for(int i=0;i<list.size();i++){
        user theUser;
        theUser.setUsername(list[i]);
        int line =ui->DoctorTableWidget->rowCount();
        ui->DoctorTableWidget->insertRow(line);
        ui->DoctorTableWidget->setItem(line,0,new QTableWidgetItem(list[i]));

        AppointmentButton *datapushButton =new AppointmentButton;
        datapushButton->setText("点击查看体征数据");
        datapushButton->setUser(theUser);
        connect(datapushButton,SIGNAL(clicked()),chartWindow,SLOT(displayWindow()));
        connect(datapushButton,SIGNAL(clicked()),this,SLOT(getUsername()));
        ui->DoctorTableWidget->setCellWidget(line,2,datapushButton);

        AppointmentButton *diagnosepushButton =new AppointmentButton;
        diagnosepushButton->setText("点击提出就医意见");
        diagnosepushButton->setUser(theUser);
        connect(diagnosepushButton,SIGNAL(clicked()),diagnosewindow,SLOT(displayWindow()));
        connect(diagnosepushButton,SIGNAL(clicked()),this,SLOT(getUsername()));

        ui->DoctorTableWidget->setCellWidget(line,3,diagnosepushButton);
    }
}

void doctorMainWindow::getuserInformation()
{
    QJsonObject user;
    user["function_id"]=USER_INFORMATION_GET;

    QJsonDocument jsonDoc(user);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);}
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;
}

void doctorMainWindow::initDoctorTableWidget()
{
    ui->DoctorTableWidget->horizontalHeader()->setFixedHeight(30);
    ui->DoctorTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->DoctorTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void doctorMainWindow::handleReplayData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;
    QList<QString> list ;
    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){
        return;
    }
    QJsonObject jsonObject = jsonDoc.object();
    int functionId =jsonObject["function_id"].toInt();
    if(functionId==USER_INFORMATION_GET){
        QJsonArray user =jsonObject["user_info"].toArray();
        for(int i=0;i<user.size();i++){
            QJsonObject object=user[i].toObject();

            QString username=object["username"].toString();

            list.append(username);
        }

    }else{

    int state = jsonObject["state"].toInt();
    if(state!=0){
        QMessageBox::warning(NULL,"病人列表","获取病人列表信息失败",QMessageBox::Ok);
        return;
    }

    }
    if(!list.isEmpty()){
        adduserInformation(list);
    }
}

void doctorMainWindow::getUsername()
{
    AppointmentButton *dataButton = (AppointmentButton *)this->sender();
    user User=dataButton->getUser();
    login::loginUser=User.getUsername();
}

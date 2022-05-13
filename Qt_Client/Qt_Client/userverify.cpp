#include "userverify.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include "protocal.h"

Userverify::Userverify(QObject *parent) : QObject(parent)
{
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(readSocketData()));
}
void Userverify::readSocketData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;

    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){

        return;
    }

    QJsonObject jsonObject = jsonDoc.object();
    int function_id =jsonObject["function_id"].toInt();
    int state =jsonObject["state"].toInt();

    switch(function_id){
    case LOGIN_FUNCTION_ID:
        emit loginState(state);
        break;

    case REGISTER_FUNCTION_ID:
        emit registerState(state);
        break;
    
    case PASSWORD_FUNCTION_ID:
        QString password=jsonObject["password"].toString(); 
        emit getPasswordState(state,password);
        break;


    }
    if(function_id==LOGIN_DOCTOR_FUNCTION){
        emit loginState(state);
    }else if(function_id==PASSWORD_DOCTOR_FUNCTION){

        QString password=jsonObject["password"].toString();
        emit getPasswordState(state,password);
    }

}


void Userverify::verifyUserNamePassword(const QString &username, const QString &password){
    QJsonObject user;
    user["function_id"]=LOGIN_FUNCTION_ID;//代表登录
    user["username"]=username;
    user["password"]=password;

    QJsonDocument jsonDoc(user);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);}
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;

}
void Userverify::verifyDoctorNamePassword(const QString &username, const QString &password){
    QJsonObject doctor;
    doctor["function_id"]=LOGIN_DOCTOR_FUNCTION;//代表医生登录
    doctor["username"]=username;
    doctor["password"]=password;

    QJsonDocument jsonDoc(doctor);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);}
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;

}
void Userverify::verifyRegisterInformation(const QStringList &registerList){
    QJsonObject user;
    user["function_id"]=REGISTER_FUNCTION_ID;//代表注册
    user["username"]=registerList[0];
    user["password"]=registerList[1];
    user["telphone"]=registerList[2];
    user["fullname"]=registerList[3];
    user["id"]=registerList[4];
    QJsonDocument jsonDoc(user);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){

        tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;
}

void Userverify::verifyUserGetPassword(const QString &username ,const QString &telphone, const QString &ID)
{
    QJsonObject user;
    user["function_id"]=PASSWORD_FUNCTION_ID;//代表找回密码
      user["username"]=username;
    user["telphone"]=telphone;
    user["id"]=ID;
    QJsonDocument jsonDoc(user);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){

        tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;
}

void Userverify::verifyDoctorGetPassword(const QString &username, const QString &telphone, const QString &ID)
{
    QJsonObject doctor;
    doctor["function_id"]=PASSWORD_DOCTOR_FUNCTION;//代表医生找回密码
    doctor["username"]=username;
    doctor["telphone"]=telphone;
    doctor["id"]=ID;
    QJsonDocument jsonDoc(doctor);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){

        tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;
}

#include "doctorinformationget.h"
#include <QJsonObject>
#include "protocal.h"
#include <QJsonDocument>
#include <QMessageBox>
#include<QDebug>
#include <QJsonArray>
#define DOCTOR_INFORMATION_GET 4
#define DOCTOR_INFORMATIONBYID_GET 5

DoctorInformationget::DoctorInformationget()
{
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplayData()));
}

void DoctorInformationget::getDoctorInformation()
{
    QJsonObject user;
    user["function_id"]=DOCTOR_INFORMATION_GET;

    QJsonDocument jsonDoc(user);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);}
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;

}

void DoctorInformationget::analysisDoctorInformation(const QJsonObject &object)
{
    QJsonArray doctorInfo =object["doctor_info"].toArray();
    QJsonObject numberObject = doctorInfo[0].toObject();
    doctor Doctor;
    Doctor.setName(numberObject["fullname"].toString());
    Doctor.setEducation(numberObject["education"].toString());
    Doctor.setWorkTime(numberObject["worktime"].toString());
    Doctor.setBriefIntroduce(numberObject["briefIntroduction"].toString());
    Doctor.setProfession(numberObject["major"].toString());
    emit idInformationReady(Doctor);

    QString base64Text = object ["picture"].toString();
    QByteArray pictureData=QByteArray::fromBase64(base64Text.toLocal8Bit());
    emit doctorPictureReady(pictureData);
    return;
}

void DoctorInformationget::handleReplayData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;
    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){
        return;
    }
    QJsonObject jsonObject = jsonDoc.object();
    int functionId =jsonObject["function_id"].toInt();
    if(functionId==DOCTOR_INFORMATIONBYID_GET){
        analysisDoctorInformation(jsonObject);

    }else{

    int state = jsonObject["state"].toInt();
    if(state!=0){

        QMessageBox::warning(NULL,"注册","获取医生信息失败",QMessageBox::Ok);
        return;
    }
    displayDoctorInformation(jsonObject["doctor_info"].toArray());

}}

void DoctorInformationget::displayDoctorInformation(const QJsonArray &doctorArray)
{
    for(int i= 0;i<doctorArray.size();i++){
        doctor Doctor;
        QJsonObject object=doctorArray[i].toObject();
        Doctor.setId(object["id"].toString());
        Doctor.setName(object["fullname"].toString());
        Doctor.setWorkTime(object["worktime"].toString());
        Doctor.setEducation(object["education"].toString());
        Doctor.setProfession(object["major"].toString());
        emit doctorReady(Doctor);

    }
}

void DoctorInformationget::getDoctorInformationById(const QString &id)
{
    QJsonObject object;
    object["function_id"]=DOCTOR_INFORMATIONBYID_GET;
    object["id"]=id;
    QJsonDocument jsonDoc(object);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    tcpSocket.write(Protocal::toProtocalData(data));
    return ;
}

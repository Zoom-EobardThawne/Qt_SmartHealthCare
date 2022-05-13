#include "jaondata.h"
#include <QFile>
#include <QDebug>
JaonData::JaonData()
{

}

void JaonData::addString(const QString &key, const QString &value)
{
    object[key] =value;
}

void JaonData::addInt(const QString &key, int value)
{
    object[key]=value;
}

void JaonData::addPicture(const QString &key, const QString &filename)
{
    QFile file(filename);
    bool ok = file.open(QFile::ReadOnly);
    if(!ok){
        qDebug()<<"Fail to file"<<filename<<":"<<file.errorString()<<endl;
        return;
    }
    QByteArray data =file.readAll();
    file.close();
    QByteArray base64Data =data.toBase64();
    object[key]=QString (base64Data);
    return;
}

QByteArray JaonData::toByteArrayData (void)
{
    QJsonDocument jsonDoc(object);
    QByteArray data =jsonDoc.toJson();
    return data;
}

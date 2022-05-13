#include "protocal.h"


Protocal::Protocal()
{

}

QByteArray Protocal::toProtocalData(const QByteArray &data)
{
    QByteArray ProtocalData;
    quint32 datalen = data.size();
    ProtocalData.append(QByteArray((char *)&datalen,sizeof(quint32)));
    ProtocalData.append(data);

    return ProtocalData;

}

#ifndef PROTOCAL_H
#define PROTOCAL_H
#include <QString>
#include <QByteArray>
class Protocal
{
public:
    Protocal();
    static QByteArray toProtocalData(const QByteArray &data);
};

#endif // PROTOCAL_H

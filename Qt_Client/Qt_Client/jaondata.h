#ifndef JAONDATA_H
#define JAONDATA_H
#include <QJsonObject>
#include <QJsonDocument>

class JaonData
{
public:
    JaonData();
    void addString(const QString &key,const QString &value);
    void addInt(const QString &key,int value);
    void addPicture (const QString &key ,const QString &filename);
    QByteArray toByteArrayData (void);

private:
    QJsonObject object;
};

#endif // JAONDATA_H

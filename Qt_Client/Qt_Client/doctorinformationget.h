#ifndef DOCTORINFORMATIONGET_H
#define DOCTORINFORMATIONGET_H
#include <QTcpSocket>
#include <QJsonArray>
#include "doctor.h"

class DoctorInformationget:public QObject
{
    Q_OBJECT
public:
    DoctorInformationget();

    void getDoctorInformation(void);
    void analysisDoctorInformation(const QJsonObject &object);
signals:
    void doctorReady(const doctor &Doctor);
    void idInformationReady(const doctor &Doctor);
    void doctorPictureReady(const QByteArray &data);

public slots:
    void handleReplayData();
    void displayDoctorInformation(const QJsonArray &doctorArray);
    void getDoctorInformationById(const QString &id);
private:
    QTcpSocket tcpSocket;
};

#endif // DOCTORINFORMATIONGET_H

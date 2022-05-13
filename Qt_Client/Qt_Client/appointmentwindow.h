#ifndef APPOINTMENTWINDOW_H
#define APPOINTMENTWINDOW_H

#include <QMainWindow>
#include "doctor.h"
#include <QTcpSocket>
#include <QJsonObject>
#include "protocal.h"
#include <QJsonDocument>
#include <QMessageBox>

namespace Ui {
class AppointmentWindow;
}

class AppointmentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppointmentWindow(QWidget *parent = 0);
    ~AppointmentWindow();

    QString getDoctorId() const;
    void setDoctorId(const QString &value);

    QString getUserName() const;
    void setUserName(const QString &value);

private slots:
    void displayInformation(const doctor &Doctor);
    void displayPicture(const QByteArray &data);
    void displayDate(const QDate &date);
    void on_commitPushButton_clicked();
    void handleReplyData(void);

private:
    Ui::AppointmentWindow *ui;
    QString doctorId;
    QString userName;
    QTcpSocket tcpSocket;
};

#endif // APPOINTMENTWINDOW_H

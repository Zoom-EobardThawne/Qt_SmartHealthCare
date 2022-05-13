#ifndef DOCTORREGISTERWINDOW_H
#define DOCTORREGISTERWINDOW_H

#include <QMainWindow>
#include <qtcpsocket.h>
#define DOCTOR_REGISTER 3
#define REGISTER_SUCCESS_STATE 0
#define REGISTER_USERNAME_FAILE 1
#define REGISTER_TELPHONE_FAILE 2


namespace Ui {
class DoctorRegisterWindow;
}

class DoctorRegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorRegisterWindow(QWidget *parent = 0);
    ~DoctorRegisterWindow();
    void registerDoctor(const QByteArray &data);

private slots:
    void on_picturePushButton_clicked();

    void on_registerPushButton_clicked();

    void handleReplyData(void);

private:
    Ui::DoctorRegisterWindow *ui;
    QString fileName;
    QTcpSocket tcpSocket;
};

#endif // DOCTORREGISTERWINDOW_H

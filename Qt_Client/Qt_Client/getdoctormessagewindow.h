#ifndef GETDOCTORMESSAGEWINDOW_H
#define GETDOCTORMESSAGEWINDOW_H
#define DOCTOR_MESSAGE 13
#include <QTcpSocket>

#include <QMainWindow>

namespace Ui {
class getDoctorMessageWindow;
}

class getDoctorMessageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit getDoctorMessageWindow(QWidget *parent = 0);
    ~getDoctorMessageWindow();
    void sendDoctorMessage();

public slots:
    void handleReplyData();
private:
    Ui::getDoctorMessageWindow *ui;
    QTcpSocket tcpSocket;
};

#endif // GETDOCTORMESSAGEWINDOW_H

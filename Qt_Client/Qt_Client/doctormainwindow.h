#ifndef DOCTORMAINWINDOW_H
#define DOCTORMAINWINDOW_H
#include <QList>
#include <QTcpSocket>
#include "diagnosewindow.h"
#include "chartwindow.h"
#include <QMainWindow>

namespace Ui {
class doctorMainWindow;
}

class doctorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit doctorMainWindow(QWidget *parent = 0);
    ~doctorMainWindow();
   void adduserInformation(const QList<QString> &list);
   void getuserInformation();
   void initDoctorTableWidget();

public slots:
   void handleReplayData();
   void getUsername();

private:
    Ui::doctorMainWindow *ui;
    QTcpSocket tcpSocket;
    diagnoseWindow *diagnosewindow;
    ChartWindow *chartWindow;

};

#endif // DOCTORMAINWINDOW_H

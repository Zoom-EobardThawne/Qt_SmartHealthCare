#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "doctorwindow.h"
#include "datawindow.h"
#include "chartwindow.h"
#include "getdoctormessagewindow.h"
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_DoctorPushButton_clicked();



    void on_dataCollectionPushButton_clicked();

    void on_chartPushButton_clicked();

    void on_doctorMessagePushButton_clicked();

private:
    Ui::MainWindow *ui;
    DoctorWindow *doctorWindw;
    DataWindow *datawindow;
    ChartWindow *chartWindow;
    getDoctorMessageWindow *doctorMessageWindow;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    doctorWindw = new DoctorWindow;
    datawindow =new DataWindow;
    chartWindow =new ChartWindow;
    doctorMessageWindow =new getDoctorMessageWindow;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete doctorWindw;
    delete datawindow;
    delete chartWindow;
    delete doctorMessageWindow;
}



void MainWindow::on_DoctorPushButton_clicked()
{
    doctorWindw->show();
}



void MainWindow::on_dataCollectionPushButton_clicked()
{
    datawindow->cleanWindow();
    datawindow->show();
}

void MainWindow::on_chartPushButton_clicked()
{
    chartWindow->show();
}



void MainWindow::on_doctorMessagePushButton_clicked()
{
        doctorMessageWindow->sendDoctorMessage();
        doctorMessageWindow->show();
}

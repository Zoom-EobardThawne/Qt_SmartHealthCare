#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include <QTableWidgetItem>
#include "doctorinformationget.h"
#include "appointmentbutton.h"
#include "login.h"

DoctorWindow::DoctorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);
    initDoctorTableWidget();
    connect(&doctorget,SIGNAL(doctorReady(doctor)),this,SLOT(addDoctorInformation(doctor)));
    connect(&doctorget,SIGNAL(idInformationReady(doctor)),&appointwindow,SLOT(displayInformation(doctor)));
    connect(&doctorget,SIGNAL(doctorPictureReady(QByteArray)),&appointwindow,SLOT(displayPicture(QByteArray)));

}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}

void DoctorWindow::initDoctorTableWidget()
{
    ui->DoctorTableWidget->horizontalHeader()->setFixedHeight(30);
    ui->DoctorTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->DoctorTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void DoctorWindow::getDoctorInformation(const QString &id)
{

}

void DoctorWindow::addDoctorInformation(const doctor &thedoctor)
{
    int line =ui->DoctorTableWidget->rowCount();
    ui->DoctorTableWidget->insertRow(line);
    ui->DoctorTableWidget->setItem(line,0,new QTableWidgetItem(thedoctor.getName()));
    ui->DoctorTableWidget->setItem(line,1,new QTableWidgetItem(thedoctor.getWorkTime()));
    ui->DoctorTableWidget->setItem(line,2,new QTableWidgetItem(thedoctor.getEducation()));
    ui->DoctorTableWidget->setItem(line,3,new QTableWidgetItem(thedoctor.getProfession()));

    AppointmentButton *appointpushButton =new AppointmentButton;
    appointpushButton->setText("点击预约");

    appointpushButton->setDoctor(thedoctor);
    connect(appointpushButton,SIGNAL(clicked()),this,SLOT(displayDoctor()));
    
    ui->DoctorTableWidget->setCellWidget(line,4,appointpushButton);
}

void DoctorWindow::displayDoctor()
{
    //可以在槽函数中获取发送信号的对象地址
    AppointmentButton *appointmentButton = (AppointmentButton *)this->sender();
    doctor Doctor=appointmentButton->getDoctor();
    doctorget.getDoctorInformationById( Doctor.getId());
    appointwindow.setDoctorId(Doctor.getId());
    appointwindow.setUserName(login::loginUser);
    appointwindow.show();
}

void DoctorWindow::on_GetDoctorPushButton_clicked()
{
    ui->DoctorTableWidget->clearContents();
    ui->DoctorTableWidget->setRowCount(0);
    doctorget.getDoctorInformation();


}

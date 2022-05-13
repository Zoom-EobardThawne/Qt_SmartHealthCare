#include "appointmentwindow.h"
#include "ui_appointmentwindow.h"
#include "displaywindow.h"
#include <QMessageBox>
#define APPOINTMENT_DOCTOR_DATA 8

AppointmentWindow::AppointmentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppointmentWindow)
{
    ui->setupUi(this);
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(displayDate(QDate)));
     connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplyData()));
}

AppointmentWindow::~AppointmentWindow()
{
    delete ui;
}

void AppointmentWindow::displayInformation(const doctor &Doctor)
{
    ui->nameLabel->clear();
    ui->nameLabel->setText("姓名："+Doctor.getName());
    ui->majorLabel->clear();
    ui->majorLabel->setText("专业："+Doctor.getProfession());
    ui->worktimeLabel->clear();
    ui->worktimeLabel->setText("从业时间："+Doctor.getWorkTime());
    ui->briefIntroduceTextEdit->clear();
    ui->briefIntroduceTextEdit->insertPlainText(Doctor.getBriefIntroduce());

}

void AppointmentWindow::displayPicture(const QByteArray &data)
{
    ui->widget->updatePicture(data);
}

void AppointmentWindow::displayDate(const QDate &date)
{
    ui->dateLabel->clear();
    QString appointmentTime = date.toString("yyyy-MM-dd");
    QDate currentData = QDate::currentDate();
    QString currentTime = currentData.toString("yyyy-MM-dd");
    if(appointmentTime < currentTime){

        QMessageBox::warning(NULL,"预约日期","预约日期已失效",QMessageBox::Ok);
        return;
    }
    ui->dateLabel->setText(appointmentTime);
}

QString AppointmentWindow::getUserName() const
{
    return userName;
}

void AppointmentWindow::setUserName(const QString &value)
{
    userName = value;
}

QString AppointmentWindow::getDoctorId() const
{
    return doctorId;
}

void AppointmentWindow::setDoctorId(const QString &value)
{
    doctorId = value;
}

void AppointmentWindow::on_commitPushButton_clicked()
{
    if(ui->dateLabel->text().isEmpty()){
        QMessageBox::warning(NULL,"预约日期","请先选择预约日期",QMessageBox::Ok);
        return;
    }
    QJsonObject object;
    object["function_id"]=APPOINTMENT_DOCTOR_DATA;
    object["doctorid"]=doctorId;
    object["username"]=userName;
    object["date"] = ui->dateLabel->text();

    QJsonDocument jsonDoc(object);
    QByteArray data =jsonDoc.toJson();

    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);
    }
    tcpSocket.write(Protocal::toProtocalData(data));

}

void AppointmentWindow::handleReplyData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;
    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){
        return;
    }

    QString message;

    QJsonObject jsonObject = jsonDoc.object();

    int state = jsonObject["state"].toInt();
    int peoples =jsonObject["appointment-peoples"].toInt();
    if(state==1){

        message= QString("当前日期已预约,当前预约人数：%1").arg(peoples);
    }else if(state == 2){

        message =QString("该医生当前指定日期已预约满，请选择其他医生或日期，当前预约人数：%1").arg(peoples);

    }else if(state ==0){
        message=QString("恭喜您，预约成功，当前预约人数：%1").arg(peoples);
    }
        QMessageBox::warning(NULL,"预约",message,QMessageBox::Ok);
    return;
}

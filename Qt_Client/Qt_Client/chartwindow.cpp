#include "chartwindow.h"
#include "ui_chartwindow.h"
#include <QChart>
#include <QChartView>
#include <QJsonObject>
#include "protocal.h"
#include <QJsonDocument>
#include <QMessageBox>
#include<QDebug>
#include <QJsonArray>
#include <QValueAxis>
#include <QSplineSeries>
#include <QScatterSeries>
#include "login.h"
#include <string>
#include<QPair>
#define CHART_DATA 10
QT_CHARTS_USE_NAMESPACE
ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(handleReplayData()));



           ui->tabWidget->setStyleSheet("background-color:rgba(0,0,0,0)");
}

ChartWindow::~ChartWindow()
{
    delete ui;
}

void ChartWindow::getLine(const int i, QChart *dataChart, QList<QPointF> list, QPair<int, int> &range)
{
    QValueAxis *dataX =new QValueAxis;
    dataX->setTickCount(i+1);
    dataX->setGridLineVisible(false);
    dataX->setRange(0,i);

    QValueAxis *dataY =new QValueAxis;
    dataY->setTickCount(11);
    dataY->setRange(range.first,range.second);//范围

    series =new QSplineSeries;
    *series <<list;

    scatterSeries =new QScatterSeries;

    scatterSeries->setMarkerSize(10);
    *scatterSeries<<list;

    dataChart->addSeries(series);
    dataChart->addSeries(scatterSeries);

    dataChart->addAxis(dataX,Qt::AlignBottom);
    dataChart->addAxis(dataY,Qt::AlignLeft);
    series->attachAxis(dataX);
    scatterSeries->attachAxis(dataX);
    series->attachAxis(dataY);
    scatterSeries->attachAxis(dataY);
}

void ChartWindow::displayWindow()
{
    this->show();
}


void ChartWindow::drawTempereatureLine(const QJsonArray &drawTemperature)
{
    QList<QPointF> list ;
    QPair<int,int>range(30,50);
    int i;
    for(i=0;i<drawTemperature.size();i++){
        QJsonObject object=drawTemperature[i].toObject();

        QString temperature=object["temperature"].toString();

        list.append(QPointF(i,temperature.toDouble()));
    }
        QChart *temp=new QChart;
        ui->temperatureWidget->setChart(temp);
        ui->temperatureWidget->setRenderHint(QPainter::Antialiasing);
        temp->legend()->setShowToolTips(true);
        temp->legend()->setToolTip("温度");
        temp->setToolTip("温度曲线");

        getLine(i,temp,list,range);

}

void ChartWindow::drawBloodGluseLine(const QJsonArray &drawBloodGluse)
{
    QList<QPointF> list ;
    QPair<int,int>range(50,200);
    int i;
    for(i=0;i<drawBloodGluse.size();i++){
        QJsonObject object=drawBloodGluse[i].toObject();

        QString bloodgluse=object["bloodgluse"].toString();

        list.append(QPointF(i,bloodgluse.toDouble()));
    }
        QChart *gluse=new QChart;
        ui->bloodGluseWidget->setChart(gluse);
        ui->bloodGluseWidget->setRenderHint(QPainter::Antialiasing);
        gluse->legend()->setShowToolTips(true);
        gluse->legend()->setToolTip("血糖");
        gluse->setToolTip("血糖曲线");

        getLine(i,gluse,list,range);
}

void ChartWindow::drawBloodOxygenLine(const QJsonArray &drawBloodOxygen)
{
    QList<QPointF> list ;
    QPair<int,int>range(50,300);
    int i;
    for(i=0;i<drawBloodOxygen.size();i++){
        QJsonObject object=drawBloodOxygen[i].toObject();

        QString bloodoxygen=object["bloodoxygen"].toString();

        list.append(QPointF(i,bloodoxygen.toDouble()));
    }
        QChart *oxygen=new QChart;
        ui->bloodOxygenWidget->setChart(oxygen);
        ui->bloodOxygenWidget->setRenderHint(QPainter::Antialiasing);
        oxygen->legend()->setShowToolTips(true);
        oxygen->legend()->setToolTip("血氧");
        oxygen->setToolTip("血氧曲线");

        getLine(i,oxygen,list,range);
}

void ChartWindow::drawBloodPresureLine(const QJsonArray &drawBloodPresure)
{
    QList<QPointF> list ;
    QPair<int,int>range(30,200);
    int i;
    for(i=0;i<drawBloodPresure.size();i++){
        QJsonObject object=drawBloodPresure[i].toObject();

        QString bloodpresure=object["bloodpresure"].toString();

        list.append(QPointF(i,bloodpresure.toDouble()));
    }
        QChart *presure=new QChart;
        ui->bloodPretureWidget->setChart(presure);
        ui->bloodPretureWidget->setRenderHint(QPainter::Antialiasing);
        presure->legend()->setShowToolTips(true);
        presure->legend()->setToolTip("血压");
        presure->setToolTip("血压曲线");

        getLine(i,presure,list,range);
}

void ChartWindow::drawHeartRateLine(const QJsonArray &drawHeartRate)
{
    QList<QPointF> list ;
    QPair<int,int>range(30,200);
    int i;
    for(i=0;i<drawHeartRate.size();i++){
        QJsonObject object=drawHeartRate[i].toObject();

        QString heartrate=object["heartrate"].toString();

        list.append(QPointF(i,heartrate.toDouble()));
    }
        QChart *heartRate=new QChart;
        ui->heartRateWidget->setChart(heartRate);
        ui->heartRateWidget->setRenderHint(QPainter::Antialiasing);
        heartRate->legend()->setShowToolTips(true);
        heartRate->legend()->setToolTip("心率");
        heartRate->setToolTip("心率曲线");

        getLine(i,heartRate,list,range);
}


void ChartWindow::handleReplayData()
{
    QByteArray data =tcpSocket.readAll();
    QJsonDocument jsonDoc;
    jsonDoc =QJsonDocument::fromJson(data);
    if(jsonDoc.isNull()){
        return;
    }

    QJsonObject jsonObject = jsonDoc.object();

    int state = jsonObject["state"].toInt();

    if(state!=0){
        return ;
    }
    QJsonArray featureDataArray=jsonObject["feature_data"].toArray();
    drawTempereatureLine(featureDataArray);
    drawBloodGluseLine(featureDataArray);
    drawBloodOxygenLine(featureDataArray);
    drawBloodPresureLine(featureDataArray);
    drawHeartRateLine(featureDataArray);

}

void ChartWindow::on_commitPushButton_clicked()
{ QJsonObject object;
    object["function_id"]=CHART_DATA;
    object["username"]=login::loginUser;
    object["startDate"]=ui->lineEdit->text();
    object["endDate"]=ui->lineEdit_2->text();
    QJsonDocument jsonDoc(object);
    QByteArray data =jsonDoc.toJson();
    if(tcpSocket.state()==QTcpSocket::UnconnectedState){
    tcpSocket.connectToHost("39.99.172.64 ",8888);}
    tcpSocket.write(Protocal::toProtocalData(data));
}

#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtCharts>
#include <QChartView>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QJsonArray>
#include <QValueAxis>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QChart>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class ChartWindow;
}

class ChartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = 0);
    ~ChartWindow();
    void drawTempereatureLine(const QJsonArray &drawTemperature);
    void drawBloodGluseLine(const QJsonArray &drawBloodGluse);
    void drawBloodOxygenLine(const QJsonArray &drawBloodOxygen);
    void drawBloodPresureLine(const QJsonArray &drawBloodPresure);
    void drawHeartRateLine(const QJsonArray &drawHeartRate);
    void getLine(const int i, QChart *dataChart, QList<QPointF> list, QPair<int,int> &range);


public slots:
    void handleReplayData();
    void displayWindow();
    void on_commitPushButton_clicked();

private:
    Ui::ChartWindow *ui;
    QTcpSocket tcpSocket;
    QSplineSeries *series;
    QScatterSeries *scatterSeries;
};

#endif // CHARTWINDOW_H

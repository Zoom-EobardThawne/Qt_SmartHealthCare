/********************************************************************************
** Form generated from reading UI file 'chartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_ChartWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *commitPushButton;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *temperatureTab;
    QHBoxLayout *horizontalLayout;
    QtCharts::QChartView *temperatureWidget;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QtCharts::QChartView *heartRateWidget;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QtCharts::QChartView *bloodPretureWidget;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_4;
    QtCharts::QChartView *bloodOxygenWidget;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_5;
    QtCharts::QChartView *bloodGluseWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChartWindow)
    {
        if (ChartWindow->objectName().isEmpty())
            ChartWindow->setObjectName(QStringLiteral("ChartWindow"));
        ChartWindow->resize(1227, 765);
        ChartWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(ChartWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -50, 1231, 821));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        commitPushButton = new QPushButton(widget);
        commitPushButton->setObjectName(QStringLiteral("commitPushButton"));
        commitPushButton->setGeometry(QRect(700, 110, 111, 28));
        commitPushButton->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 85, 0);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;\n"
"}\n"
"QPushButton:pressed{\n"
"padding-top:3px;\n"
"padding-left:4px;\n"
"}"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(340, 110, 181, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 120, 61, 21));
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 20pt \"Copperplate Gothic Bold\";"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 110, 181, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 70, 72, 31));
        label->setStyleSheet(QLatin1String("color: rgb(255, 85, 0);\n"
"font: 12pt \"04b_21\";"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(80, 180, 1051, 571));
        tabWidget->setStyleSheet(QLatin1String("border-image: url(:/IMG_2027.JPG);\n"
"\n"
"height:50px; margin-right: 2px; margin-bottom:-2px;\n"
"\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"\n"
""));
        temperatureTab = new QWidget();
        temperatureTab->setObjectName(QStringLiteral("temperatureTab"));
        temperatureTab->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(temperatureTab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        temperatureWidget = new QtCharts::QChartView(temperatureTab);
        temperatureWidget->setObjectName(QStringLiteral("temperatureWidget"));
        temperatureWidget->setStyleSheet(QLatin1String("ackground-color:rgba(244,244,244,2);\n"
"border-image: url(:/IMG_2027.JPG);\n"
""));

        horizontalLayout->addWidget(temperatureWidget);

        tabWidget->addTab(temperatureTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setStyleSheet(QStringLiteral("border-image: url(:/IMG_2027.JPG);"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        heartRateWidget = new QtCharts::QChartView(tab_2);
        heartRateWidget->setObjectName(QStringLiteral("heartRateWidget"));

        horizontalLayout_2->addWidget(heartRateWidget);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        bloodPretureWidget = new QtCharts::QChartView(tab_3);
        bloodPretureWidget->setObjectName(QStringLiteral("bloodPretureWidget"));
        bloodPretureWidget->setStyleSheet(QStringLiteral("border-image: url(:/IMG_2027.JPG);"));

        horizontalLayout_3->addWidget(bloodPretureWidget);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalLayout_4 = new QHBoxLayout(tab_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        bloodOxygenWidget = new QtCharts::QChartView(tab_4);
        bloodOxygenWidget->setObjectName(QStringLiteral("bloodOxygenWidget"));

        horizontalLayout_4->addWidget(bloodOxygenWidget);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        horizontalLayout_5 = new QHBoxLayout(tab_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        bloodGluseWidget = new QtCharts::QChartView(tab_5);
        bloodGluseWidget->setObjectName(QStringLiteral("bloodGluseWidget"));
        bloodGluseWidget->setStyleSheet(QStringLiteral(""));

        horizontalLayout_5->addWidget(bloodGluseWidget);

        tabWidget->addTab(tab_5, QString());
        ChartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChartWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1227, 25));
        ChartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChartWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChartWindow->setStatusBar(statusbar);

        retranslateUi(ChartWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChartWindow)
    {
        ChartWindow->setWindowTitle(QApplication::translate("ChartWindow", "MainWindow", Q_NULLPTR));
        commitPushButton->setText(QApplication::translate("ChartWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChartWindow", "~", Q_NULLPTR));
        label->setText(QApplication::translate("ChartWindow", " \346\227\266\351\227\264", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(temperatureTab), QApplication::translate("ChartWindow", "\346\270\251\345\272\246", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ChartWindow", "\345\277\203\347\216\207", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ChartWindow", "\350\241\200\345\216\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ChartWindow", "\350\241\200\346\260\247", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("ChartWindow", "\350\241\200\347\263\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChartWindow: public Ui_ChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H

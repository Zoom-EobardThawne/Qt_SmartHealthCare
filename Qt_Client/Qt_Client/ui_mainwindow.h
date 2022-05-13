/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QPushButton *dataCollectionPushButton;
    QPushButton *DoctorPushButton;
    QPushButton *doctorMessagePushButton;
    QPushButton *chartPushButton;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(694, 608);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-70, -80, 831, 741));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"border-image: url(:/IMG_2027.JPG);}"));
        dataCollectionPushButton = new QPushButton(widget);
        dataCollectionPushButton->setObjectName(QStringLiteral("dataCollectionPushButton"));
        dataCollectionPushButton->setGeometry(QRect(450, 380, 111, 111));
        dataCollectionPushButton->setStyleSheet(QLatin1String("font-size:10px;\n"
"\n"
"font: 10pt \"04b_21\";\n"
"color: rgb(0,0,0);\n"
"border-radius:70px;\n"
"border-image: url(:/3.png);"));
        DoctorPushButton = new QPushButton(widget);
        DoctorPushButton->setObjectName(QStringLiteral("DoctorPushButton"));
        DoctorPushButton->setGeometry(QRect(430, 210, 161, 121));
        DoctorPushButton->setStyleSheet(QLatin1String("font-size:10px;\n"
"border-image: url(:/tray5.png);\n"
"font: 12pt \"04b_21\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius:50px;\n"
""));
        doctorMessagePushButton = new QPushButton(widget);
        doctorMessagePushButton->setObjectName(QStringLiteral("doctorMessagePushButton"));
        doctorMessagePushButton->setGeometry(QRect(200, 380, 111, 111));
        doctorMessagePushButton->setStyleSheet(QLatin1String("font-size:10px;\n"
"font: 12pt \"04b_21\";\n"
"color: rgb(0,0,0);\n"
"border-radius:50px;\n"
"border-image: url(:/0.png);"));
        chartPushButton = new QPushButton(widget);
        chartPushButton->setObjectName(QStringLiteral("chartPushButton"));
        chartPushButton->setGeometry(QRect(180, 210, 161, 131));
        chartPushButton->setStyleSheet(QLatin1String("font-size:10px;\n"
"border-image: url(:/tray4.png);\n"
"\n"
"font: 10pt \"04b_21\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius:60px;\n"
""));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 500, 181, 31));
        label_2->setStyleSheet(QLatin1String("font: 18pt \"Arial\";\n"
"color: rgb(255, 85, 0);"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 500, 121, 31));
        label_3->setStyleSheet(QLatin1String("font: 18pt \"Arial\";\n"
"color: rgb(255, 85, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 694, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        dataCollectionPushButton->setText(QString());
        DoctorPushButton->setText(QApplication::translate("MainWindow", "\351\242\204\347\272\246\345\214\273\347\224\237", Q_NULLPTR));
        doctorMessagePushButton->setText(QString());
        chartPushButton->setText(QApplication::translate("MainWindow", "\344\275\223\345\276\201\346\225\260\346\215\256\346\237\245\347\234\213", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\344\275\223\345\276\201\346\225\260\346\215\256\351\207\207\351\233\206", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\214\273\347\224\237\347\225\231\350\250\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

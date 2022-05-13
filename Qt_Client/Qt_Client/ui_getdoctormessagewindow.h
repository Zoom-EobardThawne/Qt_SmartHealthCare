/********************************************************************************
** Form generated from reading UI file 'getdoctormessagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDOCTORMESSAGEWINDOW_H
#define UI_GETDOCTORMESSAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_getDoctorMessageWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTextEdit *doctorMessageTextEdit;
    QLineEdit *doctornameLineEdit;
    QLabel *appointmentTimelabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *getDoctorMessageWindow)
    {
        if (getDoctorMessageWindow->objectName().isEmpty())
            getDoctorMessageWindow->setObjectName(QStringLiteral("getDoctorMessageWindow"));
        getDoctorMessageWindow->resize(810, 539);
        centralwidget = new QWidget(getDoctorMessageWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-90, 0, 911, 491));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        doctorMessageTextEdit = new QTextEdit(widget);
        doctorMessageTextEdit->setObjectName(QStringLiteral("doctorMessageTextEdit"));
        doctorMessageTextEdit->setGeometry(QRect(180, 100, 631, 341));
        doctorMessageTextEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"font: 10pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"color: rgb(255, 255, 255);"));
        doctornameLineEdit = new QLineEdit(widget);
        doctornameLineEdit->setObjectName(QStringLiteral("doctornameLineEdit"));
        doctornameLineEdit->setGeometry(QRect(310, 40, 131, 31));
        doctornameLineEdit->setStyleSheet(QStringLiteral("background-color:rgba(244,244,244,2)"));
        appointmentTimelabel = new QLabel(widget);
        appointmentTimelabel->setObjectName(QStringLiteral("appointmentTimelabel"));
        appointmentTimelabel->setGeometry(QRect(190, 40, 111, 31));
        appointmentTimelabel->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        getDoctorMessageWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(getDoctorMessageWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 810, 25));
        getDoctorMessageWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(getDoctorMessageWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        getDoctorMessageWindow->setStatusBar(statusbar);

        retranslateUi(getDoctorMessageWindow);

        QMetaObject::connectSlotsByName(getDoctorMessageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *getDoctorMessageWindow)
    {
        getDoctorMessageWindow->setWindowTitle(QApplication::translate("getDoctorMessageWindow", "MainWindow", Q_NULLPTR));
        appointmentTimelabel->setText(QApplication::translate("getDoctorMessageWindow", "\347\225\231\350\250\200\345\214\273\347\224\237\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class getDoctorMessageWindow: public Ui_getDoctorMessageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDOCTORMESSAGEWINDOW_H

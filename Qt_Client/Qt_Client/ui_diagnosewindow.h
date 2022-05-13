/********************************************************************************
** Form generated from reading UI file 'diagnosewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSEWINDOW_H
#define UI_DIAGNOSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diagnoseWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTextEdit *doctorOpinionTextEdit;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *diagnoseWindow)
    {
        if (diagnoseWindow->objectName().isEmpty())
            diagnoseWindow->setObjectName(QStringLiteral("diagnoseWindow"));
        diagnoseWindow->resize(783, 479);
        centralwidget = new QWidget(diagnoseWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -40, 801, 511));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        doctorOpinionTextEdit = new QTextEdit(widget);
        doctorOpinionTextEdit->setObjectName(QStringLiteral("doctorOpinionTextEdit"));
        doctorOpinionTextEdit->setGeometry(QRect(70, 110, 621, 351));
        doctorOpinionTextEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(72, 60, 121, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"font: 10pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(432, 57, 131, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;\n"
"}\n"
"QPushButton:pressed{\n"
"padding-top:3px;\n"
"padding-left:4px;\n"
"}"));
        diagnoseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(diagnoseWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 783, 25));
        diagnoseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(diagnoseWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        diagnoseWindow->setStatusBar(statusbar);

        retranslateUi(diagnoseWindow);

        QMetaObject::connectSlotsByName(diagnoseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *diagnoseWindow)
    {
        diagnoseWindow->setWindowTitle(QApplication::translate("diagnoseWindow", "MainWindow", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("diagnoseWindow", "\345\260\261\345\214\273\346\204\217\350\247\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("diagnoseWindow", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class diagnoseWindow: public Ui_diagnoseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSEWINDOW_H

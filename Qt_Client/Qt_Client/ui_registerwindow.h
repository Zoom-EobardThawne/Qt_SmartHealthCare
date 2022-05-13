/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLineEdit *usernameLineEdit;
    QPushButton *pushButton_2;
    QLineEdit *passwordLineEdit;
    QPushButton *pushButton_3;
    QLineEdit *telphoneLineEdit;
    QPushButton *pushButton_4;
    QLineEdit *IDLineEdit;
    QPushButton *pushButton_5;
    QLineEdit *RealNameLineEdit;
    QPushButton *pushButton_6;
    QPushButton *registerPushButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *registerWindow)
    {
        if (registerWindow->objectName().isEmpty())
            registerWindow->setObjectName(QStringLiteral("registerWindow"));
        registerWindow->resize(552, 620);
        centralwidget = new QWidget(registerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-50, -40, 671, 831));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);}\n"
""));
        usernameLineEdit = new QLineEdit(widget);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(250, 130, 261, 31));
        usernameLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
""));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 130, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(250, 190, 261, 31));
        passwordLineEdit->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
""));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 190, 93, 28));
        pushButton_3->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        telphoneLineEdit = new QLineEdit(widget);
        telphoneLineEdit->setObjectName(QStringLiteral("telphoneLineEdit"));
        telphoneLineEdit->setGeometry(QRect(250, 250, 261, 31));
        telphoneLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
""));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 250, 93, 28));
        pushButton_4->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        IDLineEdit = new QLineEdit(widget);
        IDLineEdit->setObjectName(QStringLiteral("IDLineEdit"));
        IDLineEdit->setGeometry(QRect(250, 310, 261, 31));
        IDLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
""));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(122, 310, 101, 28));
        pushButton_5->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        RealNameLineEdit = new QLineEdit(widget);
        RealNameLineEdit->setObjectName(QStringLiteral("RealNameLineEdit"));
        RealNameLineEdit->setGeometry(QRect(250, 370, 261, 31));
        RealNameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
""));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 370, 93, 28));
        pushButton_6->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        registerPushButton = new QPushButton(widget);
        registerPushButton->setObjectName(QStringLiteral("registerPushButton"));
        registerPushButton->setGeometry(QRect(270, 440, 91, 91));
        registerPushButton->setStyleSheet(QStringLiteral("border-image: url(:/Chh5.png);"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 540, 191, 31));
        label->setStyleSheet(QLatin1String("font: 20pt \"Arial\";\n"
"color: rgb(255, 85, 0);"));
        registerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(registerWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 552, 25));
        registerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(registerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        registerWindow->setStatusBar(statusbar);

        retranslateUi(registerWindow);

        QMetaObject::connectSlotsByName(registerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *registerWindow)
    {
        registerWindow->setWindowTitle(QApplication::translate("registerWindow", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("registerWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("registerWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("registerWindow", "\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("registerWindow", "\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("registerWindow", "\347\234\237\345\256\236\345\247\223\345\220\215", Q_NULLPTR));
        registerPushButton->setText(QString());
        label->setText(QApplication::translate("registerWindow", "\347\202\271\346\210\221\346\263\250\345\206\214\345\223\237\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registerWindow: public Ui_registerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'passwordwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDWINDOW_H
#define UI_PASSWORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *retrievePasswordPushButton;
    QLineEdit *IDLineEdit;
    QLineEdit *UsernameLineEdit;
    QLineEdit *TelphoneLineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QRadioButton *doctorRadioButton;
    QRadioButton *userRadioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PasswordWindow)
    {
        if (PasswordWindow->objectName().isEmpty())
            PasswordWindow->setObjectName(QStringLiteral("PasswordWindow"));
        PasswordWindow->resize(524, 600);
        centralwidget = new QWidget(PasswordWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -10, 551, 571));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);}\n"
""));
        retrievePasswordPushButton = new QPushButton(widget);
        retrievePasswordPushButton->setObjectName(QStringLiteral("retrievePasswordPushButton"));
        retrievePasswordPushButton->setGeometry(QRect(120, 420, 241, 61));
        retrievePasswordPushButton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        IDLineEdit = new QLineEdit(widget);
        IDLineEdit->setObjectName(QStringLiteral("IDLineEdit"));
        IDLineEdit->setGeometry(QRect(220, 280, 251, 31));
        IDLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
"\n"
""));
        UsernameLineEdit = new QLineEdit(widget);
        UsernameLineEdit->setObjectName(QStringLiteral("UsernameLineEdit"));
        UsernameLineEdit->setGeometry(QRect(220, 130, 251, 31));
        UsernameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
"\n"
"\n"
""));
        TelphoneLineEdit = new QLineEdit(widget);
        TelphoneLineEdit->setObjectName(QStringLiteral("TelphoneLineEdit"));
        TelphoneLineEdit->setGeometry(QRect(220, 200, 251, 31));
        TelphoneLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145,120);\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #e1e0e0;\n"
"border-color: rgb(255, 255, 255);\n"
"\n"
""));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 280, 93, 28));
        pushButton_3->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 210, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 130, 93, 28));
        pushButton->setStyleSheet(QLatin1String("	bcakground-color: rgb(255,132,139,0);\n"
"font: 12pt \"04b_21\";\n"
"	border-radius:3px;\n"
"	color:rgb(255,255,255);"));
        doctorRadioButton = new QRadioButton(widget);
        doctorRadioButton->setObjectName(QStringLiteral("doctorRadioButton"));
        doctorRadioButton->setGeometry(QRect(260, 360, 115, 19));
        doctorRadioButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        userRadioButton = new QRadioButton(widget);
        userRadioButton->setObjectName(QStringLiteral("userRadioButton"));
        userRadioButton->setEnabled(true);
        userRadioButton->setGeometry(QRect(120, 360, 115, 19));
        userRadioButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        userRadioButton->setChecked(true);
        PasswordWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PasswordWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 524, 25));
        PasswordWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PasswordWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PasswordWindow->setStatusBar(statusbar);

        retranslateUi(PasswordWindow);

        QMetaObject::connectSlotsByName(PasswordWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PasswordWindow)
    {
        PasswordWindow->setWindowTitle(QApplication::translate("PasswordWindow", "MainWindow", Q_NULLPTR));
        retrievePasswordPushButton->setText(QApplication::translate("PasswordWindow", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("PasswordWindow", "\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PasswordWindow", "\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PasswordWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        doctorRadioButton->setText(QApplication::translate("PasswordWindow", "\345\214\273\347\224\237", Q_NULLPTR));
        userRadioButton->setText(QApplication::translate("PasswordWindow", "\347\224\250\346\210\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PasswordWindow: public Ui_PasswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDWINDOW_H

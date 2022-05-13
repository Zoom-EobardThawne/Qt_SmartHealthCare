/********************************************************************************
** Form generated from reading UI file 'doctorregisterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORREGISTERWINDOW_H
#define UI_DOCTORREGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "displaywindow.h"

QT_BEGIN_NAMESPACE

class Ui_DoctorRegisterWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *telphoneLineEdit;
    QLineEdit *realNameLineEdit;
    QLineEdit *IDLineEdit;
    QLineEdit *workTimeLineEdit;
    QLineEdit *majorLineEdit;
    QLineEdit *educationLineEdit;
    QPushButton *registerPushButton;
    QPushButton *educationPushButton;
    QPushButton *majorPushButton;
    QPushButton *wordTimePushButton;
    QPushButton *IDPushButton;
    QPushButton *realNamePushButton;
    QPushButton *telphonePushButton;
    QPushButton *passwordPushButton;
    QPushButton *usernamePushButton;
    QPushButton *picturePushButton;
    DisplayWindow *displayWidget;
    QGroupBox *groupBox;
    QTextEdit *briefIntroductionTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorRegisterWindow)
    {
        if (DoctorRegisterWindow->objectName().isEmpty())
            DoctorRegisterWindow->setObjectName(QStringLiteral("DoctorRegisterWindow"));
        DoctorRegisterWindow->resize(1074, 638);
        centralwidget = new QWidget(DoctorRegisterWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-10, -90, 1101, 761));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);\n"
"}"));
        usernameLineEdit = new QLineEdit(widget);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(730, 110, 231, 31));
        usernameLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
""));
        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(730, 160, 231, 31));
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        telphoneLineEdit = new QLineEdit(widget);
        telphoneLineEdit->setObjectName(QStringLiteral("telphoneLineEdit"));
        telphoneLineEdit->setGeometry(QRect(730, 210, 231, 31));
        telphoneLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        realNameLineEdit = new QLineEdit(widget);
        realNameLineEdit->setObjectName(QStringLiteral("realNameLineEdit"));
        realNameLineEdit->setGeometry(QRect(730, 260, 231, 31));
        realNameLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        IDLineEdit = new QLineEdit(widget);
        IDLineEdit->setObjectName(QStringLiteral("IDLineEdit"));
        IDLineEdit->setGeometry(QRect(730, 310, 231, 31));
        IDLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        workTimeLineEdit = new QLineEdit(widget);
        workTimeLineEdit->setObjectName(QStringLiteral("workTimeLineEdit"));
        workTimeLineEdit->setGeometry(QRect(730, 360, 231, 31));
        workTimeLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        majorLineEdit = new QLineEdit(widget);
        majorLineEdit->setObjectName(QStringLiteral("majorLineEdit"));
        majorLineEdit->setGeometry(QRect(730, 420, 231, 31));
        majorLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        educationLineEdit = new QLineEdit(widget);
        educationLineEdit->setObjectName(QStringLiteral("educationLineEdit"));
        educationLineEdit->setGeometry(QRect(730, 470, 231, 31));
        educationLineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        registerPushButton = new QPushButton(widget);
        registerPushButton->setObjectName(QStringLiteral("registerPushButton"));
        registerPushButton->setGeometry(QRect(630, 580, 261, 51));
        registerPushButton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        educationPushButton = new QPushButton(widget);
        educationPushButton->setObjectName(QStringLiteral("educationPushButton"));
        educationPushButton->setGeometry(QRect(600, 470, 93, 28));
        educationPushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);\n"
"	"));
        majorPushButton = new QPushButton(widget);
        majorPushButton->setObjectName(QStringLiteral("majorPushButton"));
        majorPushButton->setGeometry(QRect(600, 420, 93, 28));
        majorPushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        wordTimePushButton = new QPushButton(widget);
        wordTimePushButton->setObjectName(QStringLiteral("wordTimePushButton"));
        wordTimePushButton->setGeometry(QRect(600, 350, 93, 41));
        wordTimePushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        IDPushButton = new QPushButton(widget);
        IDPushButton->setObjectName(QStringLiteral("IDPushButton"));
        IDPushButton->setGeometry(QRect(600, 310, 93, 28));
        IDPushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        realNamePushButton = new QPushButton(widget);
        realNamePushButton->setObjectName(QStringLiteral("realNamePushButton"));
        realNamePushButton->setGeometry(QRect(600, 260, 93, 28));
        realNamePushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        telphonePushButton = new QPushButton(widget);
        telphonePushButton->setObjectName(QStringLiteral("telphonePushButton"));
        telphonePushButton->setGeometry(QRect(600, 210, 93, 28));
        telphonePushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        passwordPushButton = new QPushButton(widget);
        passwordPushButton->setObjectName(QStringLiteral("passwordPushButton"));
        passwordPushButton->setGeometry(QRect(600, 160, 93, 28));
        passwordPushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        usernamePushButton = new QPushButton(widget);
        usernamePushButton->setObjectName(QStringLiteral("usernamePushButton"));
        usernamePushButton->setGeometry(QRect(600, 110, 93, 28));
        usernamePushButton->setStyleSheet(QLatin1String("bcakground-color: rgb(255,132,139,0);\n"
"\n"
"font: 12pt \"04b_21\";\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        picturePushButton = new QPushButton(widget);
        picturePushButton->setObjectName(QStringLiteral("picturePushButton"));
        picturePushButton->setGeometry(QRect(140, 320, 211, 41));
        picturePushButton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        displayWidget = new DisplayWindow(widget);
        displayWidget->setObjectName(QStringLiteral("displayWidget"));
        displayWidget->setGeometry(QRect(100, 120, 291, 181));
        displayWidget->setStyleSheet(QLatin1String("\n"
"border:1px solid #e1e0e0;\n"
"color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 370, 441, 281));
        groupBox->setStyleSheet(QStringLiteral("font: 12pt \"04b_21\";"));
        briefIntroductionTextEdit = new QTextEdit(groupBox);
        briefIntroductionTextEdit->setObjectName(QStringLiteral("briefIntroductionTextEdit"));
        briefIntroductionTextEdit->setGeometry(QRect(10, 20, 421, 241));
        briefIntroductionTextEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(244,244,244,2);\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 255, 255);"));
        DoctorRegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorRegisterWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1074, 25));
        DoctorRegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DoctorRegisterWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DoctorRegisterWindow->setStatusBar(statusbar);

        retranslateUi(DoctorRegisterWindow);

        QMetaObject::connectSlotsByName(DoctorRegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DoctorRegisterWindow)
    {
        DoctorRegisterWindow->setWindowTitle(QApplication::translate("DoctorRegisterWindow", "MainWindow", Q_NULLPTR));
        registerPushButton->setText(QApplication::translate("DoctorRegisterWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        educationPushButton->setText(QApplication::translate("DoctorRegisterWindow", "\345\255\246\345\216\206", Q_NULLPTR));
        majorPushButton->setText(QApplication::translate("DoctorRegisterWindow", "\344\270\223\344\270\232", Q_NULLPTR));
        wordTimePushButton->setText(QApplication::translate("DoctorRegisterWindow", "\345\267\245\344\275\234\346\227\266\351\227\264", Q_NULLPTR));
        IDPushButton->setText(QApplication::translate("DoctorRegisterWindow", "\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        realNamePushButton->setText(QApplication::translate("DoctorRegisterWindow", "\347\234\237\345\256\236\345\247\223\345\220\215", Q_NULLPTR));
        telphonePushButton->setText(QApplication::translate("DoctorRegisterWindow", "\347\224\265\350\257\235\345\217\267", Q_NULLPTR));
        passwordPushButton->setText(QApplication::translate("DoctorRegisterWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        usernamePushButton->setText(QApplication::translate("DoctorRegisterWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        picturePushButton->setText(QApplication::translate("DoctorRegisterWindow", "\351\200\211\346\213\251\345\233\276\347\211\207", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DoctorRegisterWindow", "\347\256\200\344\273\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DoctorRegisterWindow: public Ui_DoctorRegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORREGISTERWINDOW_H

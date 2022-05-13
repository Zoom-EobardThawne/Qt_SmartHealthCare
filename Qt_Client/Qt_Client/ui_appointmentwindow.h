/********************************************************************************
** Form generated from reading UI file 'appointmentwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTWINDOW_H
#define UI_APPOINTMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "displaywindow.h"

QT_BEGIN_NAMESPACE

class Ui_AppointmentWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_2;
    DisplayWindow *widget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *briefIntroduceTextEdit;
    QLabel *nameLabel;
    QLabel *majorLabel;
    QLabel *worktimeLabel;
    QCalendarWidget *calendarWidget;
    QLabel *appointmentTimelabel;
    QLabel *dateLabel;
    QPushButton *commitPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AppointmentWindow)
    {
        if (AppointmentWindow->objectName().isEmpty())
            AppointmentWindow->setObjectName(QStringLiteral("AppointmentWindow"));
        AppointmentWindow->resize(1064, 611);
        centralwidget = new QWidget(AppointmentWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1071, 571));
        widget_2->setStyleSheet(QLatin1String("#widget_2{\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        widget = new DisplayWindow(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(130, 10, 251, 211));
        widget->setStyleSheet(QLatin1String("border:1px solid #e1e0e0;\n"
"color: rgb(199, 199, 199);"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 250, 391, 271));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        briefIntroduceTextEdit = new QTextEdit(groupBox);
        briefIntroduceTextEdit->setObjectName(QStringLiteral("briefIntroduceTextEdit"));
        briefIntroduceTextEdit->setStyleSheet(QString::fromUtf8("	background-color:rgba(244,244,244,2);\n"
"font: 10pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(briefIntroduceTextEdit);

        nameLabel = new QLabel(widget_2);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(590, 50, 291, 21));
        nameLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"	"));
        majorLabel = new QLabel(widget_2);
        majorLabel->setObjectName(QStringLiteral("majorLabel"));
        majorLabel->setGeometry(QRect(590, 100, 311, 21));
        majorLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 85, 0);"));
        worktimeLabel = new QLabel(widget_2);
        worktimeLabel->setObjectName(QStringLiteral("worktimeLabel"));
        worktimeLabel->setGeometry(QRect(580, 140, 311, 31));
        worktimeLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 85, 0);"));
        calendarWidget = new QCalendarWidget(widget_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(560, 195, 371, 251));
        calendarWidget->setStyleSheet(QLatin1String("background-color: rgb(170, 170, 255);\n"
"font: 9pt \"Agency FB\";\n"
"	border-radius:3px;\n"
"	color:rgb(0,0,0);\n"
""));
        appointmentTimelabel = new QLabel(widget_2);
        appointmentTimelabel->setObjectName(QStringLiteral("appointmentTimelabel"));
        appointmentTimelabel->setGeometry(QRect(560, 460, 81, 31));
        appointmentTimelabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 85, 0);"));
        dateLabel = new QLabel(widget_2);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(650, 460, 161, 31));
        dateLabel->setStyleSheet(QLatin1String("border:1px solid #e1e0e0;\n"
"\n"
"font: 11pt \"Algerian\";\n"
"color: rgb(199, 199, 199);\n"
""));
        commitPushButton = new QPushButton(widget_2);
        commitPushButton->setObjectName(QStringLiteral("commitPushButton"));
        commitPushButton->setGeometry(QRect(830, 460, 111, 31));
        commitPushButton->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"	background-color: rgb(141, 141, 141,120);\n"
"	\n"
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
        AppointmentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AppointmentWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1064, 25));
        AppointmentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AppointmentWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AppointmentWindow->setStatusBar(statusbar);

        retranslateUi(AppointmentWindow);

        QMetaObject::connectSlotsByName(AppointmentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AppointmentWindow)
    {
        AppointmentWindow->setWindowTitle(QApplication::translate("AppointmentWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AppointmentWindow", "\344\270\252\344\272\272\347\256\200\344\273\213", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("AppointmentWindow", "\345\247\223\345\220\215", Q_NULLPTR));
        majorLabel->setText(QApplication::translate("AppointmentWindow", "\344\270\223\344\270\232", Q_NULLPTR));
        worktimeLabel->setText(QApplication::translate("AppointmentWindow", "\344\273\216\344\270\232\346\227\266\351\227\264", Q_NULLPTR));
        appointmentTimelabel->setText(QApplication::translate("AppointmentWindow", "\351\242\204\347\272\246\346\227\266\351\227\264", Q_NULLPTR));
        dateLabel->setText(QString());
        commitPushButton->setText(QApplication::translate("AppointmentWindow", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppointmentWindow: public Ui_AppointmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTWINDOW_H

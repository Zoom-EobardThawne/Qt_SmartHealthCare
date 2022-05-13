/********************************************************************************
** Form generated from reading UI file 'datawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWINDOW_H
#define UI_DATAWINDOW_H

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

class Ui_DataWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLineEdit *temperatureLineEdit;
    QLabel *label;
    QLineEdit *bloodGluseLineEdit;
    QLabel *label_2;
    QLineEdit *bloodOxygenLineEdit;
    QLabel *label_3;
    QLineEdit *heartRateLineEdit;
    QLabel *label_4;
    QLineEdit *bloodPresureLineEdit;
    QLabel *label_5;
    QPushButton *commitPushButton;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QStringLiteral("DataWindow"));
        DataWindow->resize(1037, 676);
        centralwidget = new QWidget(DataWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -10, 1091, 651));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        temperatureLineEdit = new QLineEdit(widget);
        temperatureLineEdit->setObjectName(QStringLiteral("temperatureLineEdit"));
        temperatureLineEdit->setGeometry(QRect(490, 230, 211, 31));
        temperatureLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 230, 72, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(150, 150, 150,120);\n"
"	color: rgb(255, 255, 255);\n"
"color: rgb(255, 85, 0);"));
        bloodGluseLineEdit = new QLineEdit(widget);
        bloodGluseLineEdit->setObjectName(QStringLiteral("bloodGluseLineEdit"));
        bloodGluseLineEdit->setGeometry(QRect(490, 280, 211, 31));
        bloodGluseLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 280, 72, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(150, 150, 150,120);\n"
""));
        bloodOxygenLineEdit = new QLineEdit(widget);
        bloodOxygenLineEdit->setObjectName(QStringLiteral("bloodOxygenLineEdit"));
        bloodOxygenLineEdit->setGeometry(QRect(490, 340, 211, 31));
        bloodOxygenLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 340, 72, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(150, 150, 150,120);\n"
""));
        heartRateLineEdit = new QLineEdit(widget);
        heartRateLineEdit->setObjectName(QStringLiteral("heartRateLineEdit"));
        heartRateLineEdit->setGeometry(QRect(490, 400, 211, 31));
        heartRateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(380, 400, 72, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(150, 150, 150,120);\n"
""));
        bloodPresureLineEdit = new QLineEdit(widget);
        bloodPresureLineEdit->setObjectName(QStringLiteral("bloodPresureLineEdit"));
        bloodPresureLineEdit->setGeometry(QRect(490, 450, 211, 31));
        bloodPresureLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(141, 141, 141,120);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(0, 170, 255);\n"
"\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"	border-radius:3px;"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 450, 72, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color: rgb(150, 150, 150,120);\n"
""));
        commitPushButton = new QPushButton(widget);
        commitPushButton->setObjectName(QStringLiteral("commitPushButton"));
        commitPushButton->setGeometry(QRect(330, 540, 381, 41));
        commitPushButton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 100, 301, 41));
        label_6->setStyleSheet(QLatin1String("font: 26pt \"Arial\";\n"
"color: rgb(255, 85, 0);"));
        DataWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1037, 25));
        DataWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DataWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DataWindow->setStatusBar(statusbar);

        retranslateUi(DataWindow);

        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataWindow)
    {
        DataWindow->setWindowTitle(QApplication::translate("DataWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("DataWindow", "\346\270\251\345\272\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("DataWindow", "\350\241\200\347\263\226", Q_NULLPTR));
        label_3->setText(QApplication::translate("DataWindow", "\350\241\200\346\260\247", Q_NULLPTR));
        label_4->setText(QApplication::translate("DataWindow", "\345\277\203\347\216\207", Q_NULLPTR));
        label_5->setText(QApplication::translate("DataWindow", "\350\241\200\345\216\213", Q_NULLPTR));
        commitPushButton->setText(QApplication::translate("DataWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        label_6->setText(QApplication::translate("DataWindow", "\350\257\267\350\276\223\345\205\245\344\275\223\345\276\201\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H

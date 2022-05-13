/********************************************************************************
** Form generated from reading UI file 'doctorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORWINDOW_H
#define UI_DOCTORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTableWidget *DoctorTableWidget;
    QPushButton *GetDoctorPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorWindow)
    {
        if (DoctorWindow->objectName().isEmpty())
            DoctorWindow->setObjectName(QStringLiteral("DoctorWindow"));
        DoctorWindow->resize(824, 652);
        centralwidget = new QWidget(DoctorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 961, 601));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        DoctorTableWidget = new QTableWidget(widget);
        if (DoctorTableWidget->columnCount() < 5)
            DoctorTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        DoctorTableWidget->setObjectName(QStringLiteral("DoctorTableWidget"));
        DoctorTableWidget->setGeometry(QRect(10, 0, 761, 471));
        DoctorTableWidget->setStyleSheet(QLatin1String("	background-color:rgba(244,244,244,2);\n"
"font: 12pt \"Algerian\";\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(255, 255, 255);"));
        GetDoctorPushButton = new QPushButton(widget);
        GetDoctorPushButton->setObjectName(QStringLiteral("GetDoctorPushButton"));
        GetDoctorPushButton->setGeometry(QRect(590, 490, 181, 41));
        GetDoctorPushButton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        DoctorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 824, 25));
        DoctorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DoctorWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DoctorWindow->setStatusBar(statusbar);

        retranslateUi(DoctorWindow);

        QMetaObject::connectSlotsByName(DoctorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DoctorWindow)
    {
        DoctorWindow->setWindowTitle(QApplication::translate("DoctorWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = DoctorTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DoctorWindow", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = DoctorTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DoctorWindow", "\344\273\216\344\270\232\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = DoctorTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DoctorWindow", "\345\255\246\345\216\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = DoctorTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DoctorWindow", "\344\270\223\344\270\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = DoctorTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DoctorWindow", "\351\242\204\347\272\246", Q_NULLPTR));
        GetDoctorPushButton->setText(QApplication::translate("DoctorWindow", "\350\216\267\345\217\226\345\214\273\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DoctorWindow: public Ui_DoctorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORWINDOW_H

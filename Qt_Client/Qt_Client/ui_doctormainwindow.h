/********************************************************************************
** Form generated from reading UI file 'doctormainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORMAINWINDOW_H
#define UI_DOCTORMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctorMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QTableWidget *DoctorTableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *doctorMainWindow)
    {
        if (doctorMainWindow->objectName().isEmpty())
            doctorMainWindow->setObjectName(QStringLiteral("doctorMainWindow"));
        doctorMainWindow->resize(891, 602);
        centralwidget = new QWidget(doctorMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -30, 921, 631));
        widget->setStyleSheet(QLatin1String("#widget\n"
"{\n"
"	border-image: url(:/IMG_2027.JPG);}"));
        DoctorTableWidget = new QTableWidget(widget);
        if (DoctorTableWidget->columnCount() < 4)
            DoctorTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        DoctorTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        DoctorTableWidget->setObjectName(QStringLiteral("DoctorTableWidget"));
        DoctorTableWidget->setGeometry(QRect(30, 30, 801, 541));
        DoctorTableWidget->setStyleSheet(QString::fromUtf8("	background-color:rgba(244,244,244,2);\n"
"font: 10pt \"\351\273\221\344\275\223\";\n"
"font: 12pt \"Algerian\";\n"
"border:1px solid #e1e0e0;\n"
"	border-color: rgb(255, 255, 255);"));
        doctorMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(doctorMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 891, 25));
        doctorMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(doctorMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        doctorMainWindow->setStatusBar(statusbar);

        retranslateUi(doctorMainWindow);

        QMetaObject::connectSlotsByName(doctorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *doctorMainWindow)
    {
        doctorMainWindow->setWindowTitle(QApplication::translate("doctorMainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = DoctorTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("doctorMainWindow", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = DoctorTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("doctorMainWindow", "\350\257\212\346\226\255\346\203\205\345\206\265", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = DoctorTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("doctorMainWindow", "\347\227\205\344\272\272\347\227\205\345\206\265\346\237\245\347\234\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = DoctorTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("doctorMainWindow", "\346\217\220\345\207\272\346\204\217\350\247\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class doctorMainWindow: public Ui_doctorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMAINWINDOW_H

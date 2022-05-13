/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pushButton_2;
    QPushButton *PasswordPushButton;
    QLineEdit *NameLineEdit;
    QLineEdit *PasswordLineEdit;
    QPushButton *pushButton;
    QPushButton *RegistrationPushbutton;
    QPushButton *RegistrationPushbutton_2;
    QComboBox *comboBox;
    QRadioButton *userRadioButton;
    QRadioButton *doctorRadioButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 551);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 801, 501));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"	border-image: url(:/IMG_2027.JPG);\n"
"}"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 180, 61, 61));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/Chh5.png);"));
        PasswordPushButton = new QPushButton(widget);
        PasswordPushButton->setObjectName(QStringLiteral("PasswordPushButton"));
        PasswordPushButton->setGeometry(QRect(210, 260, 61, 61));
        PasswordPushButton->setStyleSheet(QStringLiteral("border-image: url(:/594b8af4c6fcb.png);"));
        NameLineEdit = new QLineEdit(widget);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));
        NameLineEdit->setGeometry(QRect(330, 200, 291, 31));
        NameLineEdit->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background:transparent;border-width:1;border-style:outset"));
        PasswordLineEdit = new QLineEdit(widget);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(330, 270, 291, 31));
        PasswordLineEdit->setStyleSheet(QLatin1String("font: 14pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background:transparent;border-width:1;border-style:outset"));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 340, 351, 51));
        pushButton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        RegistrationPushbutton = new QPushButton(widget);
        RegistrationPushbutton->setObjectName(QStringLiteral("RegistrationPushbutton"));
        RegistrationPushbutton->setGeometry(QRect(0, 450, 91, 41));
        RegistrationPushbutton->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        RegistrationPushbutton_2 = new QPushButton(widget);
        RegistrationPushbutton_2->setObjectName(QStringLiteral("RegistrationPushbutton_2"));
        RegistrationPushbutton_2->setGeometry(QRect(680, 450, 111, 41));
        RegistrationPushbutton_2->setStyleSheet(QLatin1String("font: 16pt \"Arial\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 127);"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(0, 420, 87, 22));
        comboBox->setStyleSheet(QLatin1String("\n"
"background-color: rgb(145, 145, 145,120);\n"
"border-radius:3px;\n"
""));
        userRadioButton = new QRadioButton(widget);
        userRadioButton->setObjectName(QStringLiteral("userRadioButton"));
        userRadioButton->setGeometry(QRect(230, 420, 115, 19));
        userRadioButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 10pt \"04b_21\";"));
        userRadioButton->setChecked(true);
        doctorRadioButton = new QRadioButton(widget);
        doctorRadioButton->setObjectName(QStringLiteral("doctorRadioButton"));
        doctorRadioButton->setGeometry(QRect(480, 420, 115, 19));
        doctorRadioButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 10pt \"04b_21\";"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 50, 161, 51));
        label->setStyleSheet(QLatin1String("color: rgb(255, 85, 0);\n"
"font: 24pt \"Arial\";"));
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QString());
        PasswordPushButton->setText(QString());
        NameLineEdit->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        PasswordLineEdit->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
        RegistrationPushbutton->setText(QApplication::translate("login", "\346\263\250\345\206\214", Q_NULLPTR));
        RegistrationPushbutton_2->setText(QApplication::translate("login", "\345\277\230\350\256\260\345\257\206\347\240\201", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("login", "\346\263\250\345\206\214\347\224\250\346\210\267", Q_NULLPTR)
         << QApplication::translate("login", "\346\263\250\345\206\214\345\214\273\347\224\237", Q_NULLPTR)
        );
        userRadioButton->setText(QApplication::translate("login", "\347\224\250\346\210\267", Q_NULLPTR));
        doctorRadioButton->setText(QApplication::translate("login", "\345\214\273\347\224\237", Q_NULLPTR));
        label->setText(QApplication::translate("login", "\346\254\242\350\277\216\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

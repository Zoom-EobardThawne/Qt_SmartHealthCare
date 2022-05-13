#-------------------------------------------------
#
# Project created by QtCreator 2020-07-09T15:49:41
#
#-------------------------------------------------

QT       += core gui
QT +=network
QT += charts
CONFIG += resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHealthcare
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    userverify.cpp \
    registerwindow.cpp \
    passwordwindow.cpp \
    doctorwindow.cpp \
    doctor.cpp \
    doctorregisterwindow.cpp \
    displaywindow.cpp \
    jaondata.cpp \
    protocal.cpp \
    doctorinformationget.cpp \
    appointmentwindow.cpp \
    appointmentbutton.cpp \
    datawindow.cpp \
    chartwindow.cpp \
    datachartview.cpp \
    doctormainwindow.cpp \
    diagnosewindow.cpp \
    user.cpp \
    getdoctormessagewindow.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    userverify.h \
    registerwindow.h \
    passwordwindow.h \
    doctorwindow.h \
    doctor.h \
    doctorregisterwindow.h \
    displaywindow.h \
    jaondata.h \
    protocal.h \
    doctorinformationget.h \
    appointmentwindow.h \
    appointmentbutton.h \
    datawindow.h \
    chartwindow.h \
    datachartview.h \
    doctormainwindow.h \
    diagnosewindow.h \
    user.h \
    getdoctormessagewindow.h

FORMS += \
        mainwindow.ui \
    login.ui \
    registerwindow.ui \
    passwordwindow.ui \
    doctorwindow.ui \
    doctorregisterwindow.ui \
    appointmentwindow.ui \
    datawindow.ui \
    chartwindow.ui \
    doctormainwindow.ui \
    diagnosewindow.ui \
    getdoctormessagewindow.ui

RESOURCES += \
    resource.qrc

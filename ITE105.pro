#-------------------------------------------------
#
# Project created by QtCreator 2017-01-05T15:29:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ITE105
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    mainwindow.cpp \
    treeview.cpp \
    newprojectdialog.cpp

HEADERS  += logindialog.h \
    mainwindow.h \
    newprojectdialog.h \
    treeview.h

FORMS    += logindialog.ui \
    mainwindow.ui \
    newprojectdialog.ui

DISTFILES +=

RESOURCES += \
    login_bg.qrc

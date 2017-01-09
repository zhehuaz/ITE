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
<<<<<<< HEAD
    treeview.cpp

HEADERS  += logindialog.h \
    mainwindow.h \
    treeview.h
=======
    newprojectdialog.cpp

HEADERS  += logindialog.h \
    mainwindow.h \
    newprojectdialog.h
>>>>>>> 0258d79c0005aafabc61e51e66c921e4dfaa54b4

FORMS    += logindialog.ui \
    mainwindow.ui \
    newprojectdialog.ui

DISTFILES +=

RESOURCES += \
    login_bg.qrc

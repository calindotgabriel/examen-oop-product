#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T20:17:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = examen-product
TEMPLATE = app

SOURCES += main.cpp\
    product.cpp \
    productrepo.cpp \
    productctrl.cpp \
    appwindow.cpp \
    chartswidget.cpp

HEADERS  += \
    product.h \
    productrepo.h \
    productctrl.h \
    viewholder.h \
    appwindow.h \
    chartswidget.h

FORMS    +=

DISTFILES += \
    f1.txt \
    f2.txt

CONFIG += c++11


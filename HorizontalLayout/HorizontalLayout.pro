#-------------------------------------------------
#
# Project created by QtCreator 2015-01-29T11:05:38
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HorizontalLayout
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ticker.cpp \
    WidgetMarqueeLabel.cpp \
    myrect.cpp

HEADERS  += mainwindow.h \
    ticker.h \
    WidgetMarqueeLabel.h \
    myrect.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res.qrc


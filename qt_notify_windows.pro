#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T10:11:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_notify_windows
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        widget.cpp \
    prettyosd/osdpretty.cpp \
    prettyosd/qtwin.cpp \
    qosd.cpp \
    qtitledosd.cpp

HEADERS  += widget.h \
    prettyosd/osdpretty.h \
    prettyosd/qtwin.h \
    qosd.h \
    qtitledosd.h

FORMS    += widget.ui \
    prettyosd/osdpretty.ui

RESOURCES += \
    prettyosd/images.qrc \
    res.qrc

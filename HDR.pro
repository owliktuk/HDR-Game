#-------------------------------------------------
#
# Project created by QtCreator 2012-02-27T20:31:04
#
#-------------------------------------------------

QT       += core gui

TARGET = HDR
TEMPLATE = app


SOURCES += main.cpp\
        hdr.cpp

HEADERS  += hdr.h

FORMS    += hdr.ui

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/HDR/bin
    INSTALLS += target
}

OTHER_FILES +=










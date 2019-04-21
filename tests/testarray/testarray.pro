QT += testlib
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += \
        ../../src/

SOURCES += \
        testarray.cpp \

HEADERS += \
        ../../src/array.h

TEMPLATE = app

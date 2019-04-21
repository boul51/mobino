QT += testlib
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += \
        ../../src/

SOURCES += \
        testactions.cpp \
        ../../src/iaction.cpp \
        ../../src/ledaction.cpp \

TEMPLATE = app

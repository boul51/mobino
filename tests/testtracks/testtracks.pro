QT += testlib
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += \
        ../../src/

SOURCES += \
        testtracks.cpp \
        ../../src/track.cpp \
        ../../src/logicalleddevice.cpp \
        ../../src/ledaction.cpp \

TEMPLATE = app

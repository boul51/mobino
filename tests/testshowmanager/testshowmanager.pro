QT += testlib
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += \
        ../../src/

SOURCES += \
        testshowmanager.cpp \
        ../../src/logicalmotordevice.cpp \
        ../../src/logicalleddevice.cpp \
        ../../src/ishowmanager.cpp \
        ../../src/sleepyshowmanager.cpp \
        ../../src/track.cpp \
        ../../src/ledaction.cpp \

HEADERS += \
        ../../src/ilogicaldevice.h \
        ../../src/ihardwaredevice.h \
        ../../src/track.h \

TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += PC_BUILD

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
        ../../src/motoraction.cpp \
        ../../src/devicesmanager.cpp \
        ../../src/hardwaredevicefactory.cpp \
        ../../src/hardwareleddevice.cpp \
        ../../src/hardwaremotordevice.cpp \

HEADERS += \
        ../../src/ilogicaldevice.h \
        ../../src/ihardwaredevice.h \
        ../../src/track.h \

TEMPLATE = app

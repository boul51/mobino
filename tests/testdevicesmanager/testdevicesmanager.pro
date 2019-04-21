QT += testlib
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += \
        ../../src/

SOURCES += \
        testdevicesmanager.cpp \
        ../../src/devicesmanager.cpp \
        ../../src/logicalmotordevice.cpp \
        ../../src/logicalleddevice.cpp \
        ../../src/hardwareleddevice.cpp \
        ../../src/hardwaremotordevice.cpp \
        ../../src/hardwaredevicefactory.cpp \

HEADERS += \
        ../../src/ilogicaldevice.h \
        ../../src/ihardwaredevice.h \

TEMPLATE = app

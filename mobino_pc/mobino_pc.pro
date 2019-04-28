QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS PC_BUILD

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/devicesmanager.cpp \
    ../src/hardwaredevicefactory.cpp \
    ../src/hardwareleddevice.cpp \
    ../src/hardwaremotordevice.cpp \
    ../src/iaction.cpp \
    ../src/ishowmanager.cpp \
    ../src/ledaction.cpp \
    ../src/logicalleddevice.cpp \
    ../src/logicalmotordevice.cpp \
    ../src/main.cpp \
    ../src/motoraction.cpp \
    ../src/sleepyshowmanager.cpp \
    ../src/track.cpp \

HEADERS += \
    ../src/array.h \
    ../src/debugprint.h \
    ../src/devicesmanager.h \
    ../src/devicetype.h \
    ../src/hardwaredevicefactory.h \
    ../src/hardwareleddevice.h \
    ../src/hardwaremotordevice.h \
    ../src/iaction.h \
    ../src/ihardwaredevice.h \
    ../src/ilogicaldevice.h \
    ../src/ishowmanager.h \
    ../src/ledaction.h \
    ../src/logicalleddevice.h \
    ../src/logicalmotordevice.h \
    ../src/motoraction.h \
    ../src/printint.h \
    ../src/sleepyshowmanager.h \
    ../src/track.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

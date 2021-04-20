QT       += core gui
QT       += sql
QT       += multimedia
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH +="/usr/local/include/opencv4"
LIBS += -L"/usr/local/lib/"
LIBS += \
-lopencv_calib3d -lopencv_imgproc -lopencv_core -lopencv_ml -lopencv_videoio -lopencv_features2d -lopencv_objdetect -lopencv_flann -lopencv_video -lopencv_highgui

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accessmanager.cpp \
    adddevice.cpp \
    authorization.cpp \
    cameravideocapture.cpp \
    checkconnection.cpp \
    checkstring.cpp \
    createuser.cpp \
    databaseconnection.cpp \
    datacryptor.cpp \
    devices.cpp \
    editmandatorygroup.cpp \
    eventlog.cpp \
    main.cpp \
    buksanspy.cpp \
    mandatorygroups.cpp \
    networkinfo.cpp \
    registration.cpp \
    sendalert.cpp \
    setupconnection.cpp \
    users.cpp

HEADERS += \
    accessmanager.h \
    adddevice.h \
    authorization.h \
    buksanspy.h \
    cameravideocapture.h \
    checkconnection.h \
    checkstring.h \
    createuser.h \
    databaseconnection.h \
    datacryptor.h \
    devices.h \
    editmandatorygroup.h \
    eventlog.h \
    mandatorygroups.h \
    networkinfo.h \
    registration.h \
    sendalert.h \
    setupconnection.h \
    users.h

FORMS += \
    adddevice.ui \
    authorization.ui \
    buksanspy.ui \
    createuser.ui \
    devices.ui \
    editmandatorygroup.ui \
    eventlog.ui \
    mandatorygroups.ui \
    registration.ui \
    setupconnection.ui \
    users.ui
TRANSLATIONS += \
    BuksanSpy_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

QT       += core gui widgets
QT       += sql
QT       += multimedia
QT       += network

CONFIG += c++17

# Требуем Qt6 и отключаем старые API
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
# OpenCV: минимальный набор модулей без opencv_viz/VTK
INCLUDEPATH += /usr/include/opencv4
LIBS += -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CBuksanSpyApp.cpp \
    CBuksanSpy.cpp \
    main.cpp \
    camera/CBuksanViewFinder.cpp \
    camera/CCameraVideoCapture.cpp \
    utils/CCheckConnection.cpp \
    utils/CCheckString.cpp \
    security/CCreateUser.cpp \
    database/CDatabaseConnection.cpp \
    database/CDataCryptor.cpp \
    ui/CDevices.cpp \
    ui/CEditMandatoryGroup.cpp \
    ui/CEventLog.cpp \
    ui/CMandatoryGroups.cpp \
    ui/CMandatoryMarkCreator.cpp \
    ui/CMandatoryMarksEditor.cpp \
    utils/CNetworkInfo.cpp \
    utils/CSendAlert.cpp \
    security/CUsers.cpp \
    security/CAccessManager.cpp \
    ui/CAddDevice.cpp \
    security/CAuthorization.cpp

HEADERS += \
    CBuksanSpy.h \
    CBuksanSpyApp.h \
    camera/CBuksanViewFinder.h \
    camera/CCameraVideoCapture.h \
    utils/CCheckConnection.h \
    utils/CCheckString.h \
    security/CCreateUser.h \
    database/CDatabaseConnection.h \
    database/CDataCryptor.h \
    ui/CDevices.h \
    ui/CEditMandatoryGroup.h \
    ui/CEventLog.h \
    ui/CMandatoryGroups.h \
    ui/CMandatoryMarkCreator.h \
    ui/CMandatoryMarksEditor.h \
    utils/CNetworkInfo.h \
    utils/CSendAlert.h \
    security/CUsers.h \
    security/CAccessManager.h \
    ui/CAddDevice.h \
    security/CAuthorization.h

FORMS += \
    CBuksanSpy.ui \
    ui/CAddDevice.ui \
    security/CAuthorization.ui \
    security/CCreateUser.ui \
    ui/CDevices.ui \
    ui/CEditMandatoryGroup.ui \
    ui/CEventLog.ui \
    ui/CMandatoryGroups.ui \
    ui/CMandatoryMarkCreator.ui \
    ui/CMandatoryMarksEditor.ui \
    security/CUsers.ui

TRANSLATIONS += \
    BuksanSpy_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

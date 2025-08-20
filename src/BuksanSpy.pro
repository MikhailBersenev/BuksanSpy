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
    CAccessManager.cpp \
    CAddDevice.cpp \
    CAuthorization.cpp \
    CBuksanSpyApp.cpp \
    CBuksanViewFinder.cpp \
    CCameraVideoCapture.cpp \
    CCheckConnection.cpp \
    CCheckString.cpp \
    CCreateUser.cpp \
    CDatabaseConnection.cpp \
    CDataCryptor.cpp \
    CDevices.cpp \
    CEditMandatoryGroup.cpp \
    CEventLog.cpp \
    main.cpp \
    CBuksanSpy.cpp \
    CMandatoryGroups.cpp \
    CMandatoryMarkCreator.cpp \
    CMandatoryMarksEditor.cpp \
    CNetworkInfo.cpp \
    CSendAlert.cpp \
    CUsers.cpp

HEADERS += \
    CAccessManager.h \
    CAddDevice.h \
    CAuthorization.h \
    CBuksanSpy.h \
    CBuksanSpyApp.h \
    CBuksanViewFinder.h \
    CCameraVideoCapture.h \
    CCheckConnection.h \
    CCheckString.h \
    CCreateUser.h \
    CDatabaseConnection.h \
    CDataCryptor.h \
    CDevices.h \
    CEditMandatoryGroup.h \
    CEventLog.h \
    CMandatoryGroups.h \
    CMandatoryMarkCreator.h \
    CMandatoryMarksEditor.h \
    CNetworkInfo.h \
    CSendAlert.h \
    CUsers.h

FORMS += \
    CAddDevice.ui \
    CAuthorization.ui \
    CBuksanSpy.ui \
    CCreateUser.ui \
    CDevices.ui \
    CEditMandatoryGroup.ui \
    CEventLog.ui \
    CMandatoryGroups.ui \
    CMandatoryMarkCreator.ui \
    CMandatoryMarksEditor.ui \
    CUsers.ui

TRANSLATIONS += \
    BuksanSpy_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

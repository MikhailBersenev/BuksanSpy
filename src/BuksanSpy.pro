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
    camera/CBuksanViewFinder.cpp \
    camera/CCameraVideoCapture.cpp \
    main.cpp \
    utils/CCheckConnection.cpp \
    utils/CUserCheck.cpp \
    utils/CStringUtils.cpp \
    utils/CEventHelper.cpp \
    security/CCreateUser.cpp \
    db/CDatabaseConnection.cpp \
    db/CDatabaseConnectionPSQL.cpp \
    db/CDataCryptor.cpp \
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
    security/CAuthorization.cpp \
    core/CCamera.cpp \
    core/CMediaFile.cpp \
    MRBAC/auth/CUser.cpp \
    MRBAC/objects/CSecLabeledObject.cpp \
    MRBAC/objects/CSecurityGroup.cpp \
    EventEngine/CEventEngine.cpp \
    EventEngine/CEventSender.cpp \
    EventEngine/CSQLEventEngine.cpp \
    EventEngine/events/CEvent.cpp \
    EventEngine/events/systemEvents/CSystemEvent.cpp \
    EventEngine/events/serverEvents/CServerEvent.cpp \
    EventEngine/events/serverEvents/CServerConnectEvent.cpp \
    EventEngine/events/serverEvents/CInternetLostConnectionEvent.cpp \
    EventEngine/events/serverEvents/CInternetConnectionRecoveredEvent.cpp \
    EventEngine/events/securityEvents/CSecurityEvent.cpp \
    EventEngine/events/securityEvents/CUserAuthEvent.cpp \
    EventEngine/events/securityEvents/CUserRegisterEvent.cpp \
    EventEngine/events/securityEvents/CUserChangePasswordEvent.cpp \
    EventEngine/events/securityEvents/CUserBanAccountEvent.cpp \
    EventEngine/events/securityEvents/CUserDeleteAccountEvent.cpp \
    EventEngine/events/securityEvents/CUserChangeUserNameEvent.cpp \
    EventEngine/events/securityEvents/CUserLogoutAccountEvent.cpp \
    EventEngine/events/securityEvents/CUserUnlockAccountEvent.cpp \
    EventEngine/events/securityEvents/CMandatoryMarkChangedEvent.cpp \
    EventEngine/events/salesEvents/CSalesEvent.cpp \
    EventEngine/events/salesEvents/CNewItemInReceiptEvent.cpp \
    EventEngine/events/salesEvents/CExportReceiptToFileEvent.cpp \
    EventEngine/events/salesEvents/CShiftOpeningEvent.cpp \
    EventEngine/events/salesEvents/CShiftClosingEvent.cpp

HEADERS += \
    CBuksanSpy.h \
    CBuksanSpyApp.h \
    camera/CBuksanViewFinder.h \
    camera/CCameraVideoCapture.h \
    utils/CCheckConnection.h \
    utils/CUserCheck.h \
    utils/CStringUtils.h \
    utils/CEventHelper.h \
    security/CCreateUser.h \
    db/CDatabaseConnection.h \
    db/CDatabaseConnectionPSQL.h \
    db/CDataCryptor.h \
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
    security/CAuthorization.h \
    core/CCamera.h \
    core/CMediaFile.h \
    MRBAC/auth/CUser.h \
    MRBAC/objects/CSecLabeledObject.h \
    MRBAC/objects/CSecurityGroup.h \
    EventEngine/CEventEngine.h \
    EventEngine/CEventSender.h \
    EventEngine/CSQLEventEngine.h \
    EventEngine/events/CEvent.h \
    EventEngine/events/systemEvents/CSystemEvent.h \
    EventEngine/events/serverEvents/CServerEvent.h \
    EventEngine/events/serverEvents/CServerConnectEvent.h \
    EventEngine/events/serverEvents/CInternetLostConnectionEvent.h \
    EventEngine/events/serverEvents/CInternetConnectionRecoveredEvent.h \
    EventEngine/events/securityEvents/CSecurityEvent.h \
    EventEngine/events/securityEvents/CUserAuthEvent.h \
    EventEngine/events/securityEvents/CUserRegisterEvent.h \
    EventEngine/events/securityEvents/CUserChangePasswordEvent.h \
    EventEngine/events/securityEvents/CUserBanAccountEvent.h \
    EventEngine/events/securityEvents/CUserDeleteAccountEvent.h \
    EventEngine/events/securityEvents/CUserChangeUserNameEvent.h \
    EventEngine/events/securityEvents/CUserLogoutAccountEvent.h \
    EventEngine/events/securityEvents/CUserUnlockAccountEvent.h \
    EventEngine/events/securityEvents/CMandatoryMarkChangedEvent.h \
    EventEngine/events/salesEvents/CSalesEvent.h \
    EventEngine/events/salesEvents/CNewItemInReceiptEvent.h \
    EventEngine/events/salesEvents/CExportReceiptToFileEvent.h \
    EventEngine/events/salesEvents/CShiftOpeningEvent.h \
    EventEngine/events/salesEvents/CShiftClosingEvent.h

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

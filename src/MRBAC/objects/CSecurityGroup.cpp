#include "CSecurityGroup.h"
#include <QDebug>

// Конструкторы
CSecurityGroup::CSecurityGroup(QObject *parent)
    : CSecLabeledObject{parent}
    , m_nRightId{0}
    , m_bUsersControl{false}
    , m_bAddDevice{false}
    , m_bEditDevice{false}
    , m_bDeleteDevice{false}
    , m_bAlertsView{false}
    , m_bAlertsDelete{false}
    , m_bGeneralSettingsView{false}
    , m_bGeneralSettingsChange{false}
    , m_bVideosView{false}
    , m_bVideosDelete{false}
{
    // Инициализируем мандатную метку по умолчанию
    m_lMandatoryMark.strName = "";
    m_lMandatoryMark.nLevel = 0;
}

CSecurityGroup::CSecurityGroup(qint64 nRightId, const QString &strDescription, const CSecLabeledObject::SecurityLabel &lMandatoryMark, QObject *parent)
    : CSecLabeledObject{parent}
    , m_nRightId{nRightId}
    , m_strDescription{strDescription.trimmed()}
    , m_bUsersControl{false}
    , m_bAddDevice{false}
    , m_bEditDevice{false}
    , m_bDeleteDevice{false}
    , m_bAlertsView{false}
    , m_bAlertsDelete{false}
    , m_bGeneralSettingsView{false}
    , m_bGeneralSettingsChange{false}
    , m_bVideosView{false}
    , m_bVideosDelete{false}
    , m_lMandatoryMark{lMandatoryMark}
{
}

CSecurityGroup::~CSecurityGroup()
{
}

// Основные геттеры
qint64 CSecurityGroup::fGetRightId() const
{
    return m_nRightId;
}

QString CSecurityGroup::fGetDescription() const
{
    return m_strDescription;
}

bool CSecurityGroup::fGetUsersControl() const
{
    return m_bUsersControl;
}

bool CSecurityGroup::fGetAddDevice() const
{
    return m_bAddDevice;
}

bool CSecurityGroup::fGetEditDevice() const
{
    return m_bEditDevice;
}

bool CSecurityGroup::fGetDeleteDevice() const
{
    return m_bDeleteDevice;
}

bool CSecurityGroup::fGetAlertsView() const
{
    return m_bAlertsView;
}

bool CSecurityGroup::fGetAlertsDelete() const
{
    return m_bAlertsDelete;
}

bool CSecurityGroup::fGetGeneralSettingsView() const
{
    return m_bGeneralSettingsView;
}

bool CSecurityGroup::fGetGeneralSettingsChange() const
{
    return m_bGeneralSettingsChange;
}

bool CSecurityGroup::fGetVideosView() const
{
    return m_bVideosView;
}

bool CSecurityGroup::fGetVideosDelete() const
{
    return m_bVideosDelete;
}

CSecLabeledObject::SecurityLabel CSecurityGroup::fGetMandatoryMark() const
{
    return m_lMandatoryMark;
}

// Основные сеттеры
void CSecurityGroup::fSetRightId(qint64 nRightId)
{
    if (m_nRightId != nRightId) {
        m_nRightId = nRightId;
        fEmitDataChanged();
    }
}

void CSecurityGroup::fSetDescription(const QString &strDescription)
{
    if (m_strDescription != strDescription) {
        m_strDescription = strDescription.trimmed();
        fEmitDataChanged();
    }
}

void CSecurityGroup::fSetUsersControl(bool bUsersControl)
{
    if (m_bUsersControl != bUsersControl) {
        m_bUsersControl = bUsersControl;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetAddDevice(bool bAddDevice)
{
    if (m_bAddDevice != bAddDevice) {
        m_bAddDevice = bAddDevice;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetEditDevice(bool bEditDevice)
{
    if (m_bEditDevice != bEditDevice) {
        m_bEditDevice = bEditDevice;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetDeleteDevice(bool bDeleteDevice)
{
    if (m_bDeleteDevice != bDeleteDevice) {
        m_bDeleteDevice = bDeleteDevice;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetAlertsView(bool bAlertsView)
{
    if (m_bAlertsView != bAlertsView) {
        m_bAlertsView = bAlertsView;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetAlertsDelete(bool bAlertsDelete)
{
    if (m_bAlertsDelete != bAlertsDelete) {
        m_bAlertsDelete = bAlertsDelete;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetGeneralSettingsView(bool bGeneralSettingsView)
{
    if (m_bGeneralSettingsView != bGeneralSettingsView) {
        m_bGeneralSettingsView = bGeneralSettingsView;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetGeneralSettingsChange(bool bGeneralSettingsChange)
{
    if (m_bGeneralSettingsChange != bGeneralSettingsChange) {
        m_bGeneralSettingsChange = bGeneralSettingsChange;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetVideosView(bool bVideosView)
{
    if (m_bVideosView != bVideosView) {
        m_bVideosView = bVideosView;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetVideosDelete(bool bVideosDelete)
{
    if (m_bVideosDelete != bVideosDelete) {
        m_bVideosDelete = bVideosDelete;
        fEmitRightsChanged();
    }
}

void CSecurityGroup::fSetMandatoryMark(const CSecLabeledObject::SecurityLabel &lMandatoryMark)
{
    if (m_lMandatoryMark.strName != lMandatoryMark.strName || 
        m_lMandatoryMark.nLevel != lMandatoryMark.nLevel) {
        m_lMandatoryMark = lMandatoryMark;
        fEmitDataChanged();
    }
}

// Методы для массовой установки прав доступа
void CSecurityGroup::fSetAllRights(bool bValue)
{
    m_bUsersControl = bValue;
    m_bAddDevice = bValue;
    m_bEditDevice = bValue;
    m_bDeleteDevice = bValue;
    m_bAlertsView = bValue;
    m_bAlertsDelete = bValue;
    m_bGeneralSettingsView = bValue;
    m_bGeneralSettingsChange = bValue;
    m_bVideosView = bValue;
    m_bVideosDelete = bValue;
    fEmitRightsChanged();
}

void CSecurityGroup::fSetDeviceRights(bool bAdd, bool bEdit, bool bDelete)
{
    m_bAddDevice = bAdd;
    m_bEditDevice = bEdit;
    m_bDeleteDevice = bDelete;
    fEmitRightsChanged();
}

void CSecurityGroup::fSetAlertRights(bool bView, bool bDelete)
{
    m_bAlertsView = bView;
    m_bAlertsDelete = bDelete;
    fEmitRightsChanged();
}

void CSecurityGroup::fSetGeneralSettingsRights(bool bView, bool bChange)
{
    m_bGeneralSettingsView = bView;
    m_bGeneralSettingsChange = bChange;
    fEmitRightsChanged();
}

void CSecurityGroup::fSetVideoRights(bool bView, bool bDelete)
{
    m_bVideosView = bView;
    m_bVideosDelete = bDelete;
    fEmitRightsChanged();
}

// Утилитарные методы
bool CSecurityGroup::fIsValid() const
{
    return m_nRightId > 0 && !m_strDescription.isEmpty();
}

QString CSecurityGroup::fToString() const
{
    return QString("SecurityGroup[ID: %1, Description: %2, MandatoryMark: %3 (Level: %4)]")
           .arg(m_nRightId)
           .arg(m_strDescription)
           .arg(m_lMandatoryMark.strName)
           .arg(m_lMandatoryMark.nLevel);
}

bool CSecurityGroup::fHasAnyRights() const
{
    return m_bUsersControl || m_bAddDevice || m_bEditDevice || m_bDeleteDevice ||
           m_bAlertsView || m_bAlertsDelete || m_bGeneralSettingsView || 
           m_bGeneralSettingsChange || m_bVideosView || m_bVideosDelete;
}

bool CSecurityGroup::fHasDeviceRights() const
{
    return m_bAddDevice || m_bEditDevice || m_bDeleteDevice;
}

bool CSecurityGroup::fHasAlertRights() const
{
    return m_bAlertsView || m_bAlertsDelete;
}

bool CSecurityGroup::fHasGeneralSettingsRights() const
{
    return m_bGeneralSettingsView || m_bGeneralSettingsChange;
}

bool CSecurityGroup::fHasVideoRights() const
{
    return m_bVideosView || m_bVideosDelete;
}

// Защищенные методы
void CSecurityGroup::fEmitDataChanged()
{
    emit securityGroupDataChanged();
}

void CSecurityGroup::fEmitRightsChanged()
{
    emit rightsChanged();
}

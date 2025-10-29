#ifndef CSECURITYGROUP_H
#define CSECURITYGROUP_H

#include "CSecLabeledObject.h"
#include <QString>
#include <QObject>

class CSecurityGroup : public CSecLabeledObject
{
    Q_OBJECT

public:
    explicit CSecurityGroup(QObject *parent = nullptr);
    explicit CSecurityGroup(qint64 nRightId, const QString &strDescription, const CSecLabeledObject::SecurityLabel &lMandatoryMark, QObject *parent = nullptr);
    virtual ~CSecurityGroup();

    // Основные геттеры
    qint64 fGetRightId() const;
    QString fGetDescription() const;
    bool fGetUsersControl() const;
    bool fGetAddDevice() const;
    bool fGetEditDevice() const;
    bool fGetDeleteDevice() const;
    bool fGetAlertsView() const;
    bool fGetAlertsDelete() const;
    bool fGetGeneralSettingsView() const;
    bool fGetGeneralSettingsChange() const;
    bool fGetVideosView() const;
    bool fGetVideosDelete() const;
    CSecLabeledObject::SecurityLabel fGetMandatoryMark() const;

    // Основные сеттеры
    void fSetRightId(qint64 nRightId);
    void fSetDescription(const QString &strDescription);
    void fSetUsersControl(bool bUsersControl);
    void fSetAddDevice(bool bAddDevice);
    void fSetEditDevice(bool bEditDevice);
    void fSetDeleteDevice(bool bDeleteDevice);
    void fSetAlertsView(bool bAlertsView);
    void fSetAlertsDelete(bool bAlertsDelete);
    void fSetGeneralSettingsView(bool bGeneralSettingsView);
    void fSetGeneralSettingsChange(bool bGeneralSettingsChange);
    void fSetVideosView(bool bVideosView);
    void fSetVideosDelete(bool bVideosDelete);
    void fSetMandatoryMark(const CSecLabeledObject::SecurityLabel &lMandatoryMark);

    // Методы для массовой установки прав доступа
    void fSetAllRights(bool bValue);
    void fSetDeviceRights(bool bAdd, bool bEdit, bool bDelete);
    void fSetAlertRights(bool bView, bool bDelete);
    void fSetGeneralSettingsRights(bool bView, bool bChange);
    void fSetVideoRights(bool bView, bool bDelete);

    // Утилитарные методы
    bool fIsValid() const;
    QString fToString() const;
    bool fHasAnyRights() const;
    bool fHasDeviceRights() const;
    bool fHasAlertRights() const;
    bool fHasGeneralSettingsRights() const;
    bool fHasVideoRights() const;

signals:
    void securityGroupDataChanged();
    void rightsChanged();

protected:
    // Внутренние методы
    void fEmitDataChanged();
    void fEmitRightsChanged();

private:
    qint64 m_nRightId;                    // Первичный ключ
    QString m_strDescription;              // Название мандатной группы
    bool m_bUsersControl;                  // Атрибут доступа к разделу "пользователи"
    bool m_bAddDevice;                     // Атрибут доступа для добавления устройств
    bool m_bEditDevice;                    // Атрибут доступа для редактирования устройств
    bool m_bDeleteDevice;                  // Атрибут доступа для удаления устройств
    bool m_bAlertsView;                    // Атрибут доступа к логу событий
    bool m_bAlertsDelete;                  // Атрибут доступа к очистке лога событий
    bool m_bGeneralSettingsView;           // Атрибут доступа к основным настройкам ПС
    bool m_bGeneralSettingsChange;         // Атрибут доступа к изменению основных настроек ПС
    bool m_bVideosView;                    // Атрибут доступа к просмотру видеоархива
    bool m_bVideosDelete;                  // Атрибут доступа к очистке видеоархива
    CSecLabeledObject::SecurityLabel m_lMandatoryMark;  // Мандатная метка группы
};

#endif // CSECURITYGROUP_H

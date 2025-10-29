#include "CUser.h"
#include <QDebug>

// Конструкторы
CUser::CUser(QObject *parent)
    : CSecLabeledObject{parent}
    , m_nUserId{0}
{
    // Инициализируем мандатную метку по умолчанию
    m_lRights.strName = "";
    m_lRights.nLevel = 0;
}

CUser::CUser(qint64 nUserId, const QString &strUsername, const QDate &dateAddDate, const CSecLabeledObject::SecurityLabel &lRights, QObject *parent)
    : CSecLabeledObject{parent}
    , m_nUserId{nUserId}
    , m_strUsername{strUsername.trimmed()}
    , m_dateAddDate{dateAddDate}
    , m_lRights{lRights}
{
}

CUser::~CUser()
{
}

// Основные геттеры
qint64 CUser::fGetUserId() const
{
    return m_nUserId;
}

QString CUser::fGetUsername() const
{
    return m_strUsername;
}

QDate CUser::fGetAddDate() const
{
    return m_dateAddDate;
}

CSecLabeledObject::SecurityLabel CUser::fGetRights() const
{
    return m_lRights;
}

// Основные сеттеры
void CUser::fSetUserId(qint64 nUserId)
{
    if (m_nUserId != nUserId) {
        m_nUserId = nUserId;
        fEmitDataChanged();
    }
}

void CUser::fSetUsername(const QString &strUsername)
{
    if (m_strUsername != strUsername) {
        m_strUsername = strUsername.trimmed();
        fEmitDataChanged();
    }
}

void CUser::fSetAddDate(const QDate &dateAddDate)
{
    if (m_dateAddDate != dateAddDate) {
        m_dateAddDate = dateAddDate;
        fEmitDataChanged();
    }
}

void CUser::fSetRights(const CSecLabeledObject::SecurityLabel &lRights)
{
    if (m_lRights.strName != lRights.strName || 
        m_lRights.nLevel != lRights.nLevel) {
        m_lRights = lRights;
        fEmitDataChanged();
    }
}

// Утилитарные методы
bool CUser::fIsValid() const
{
    return m_nUserId > 0 && !m_strUsername.isEmpty();
}

QString CUser::fToString() const
{
    return QString("User[ID: %1, Username: %2, AddDate: %3, Rights: %4 (Level: %5)]")
           .arg(m_nUserId)
           .arg(m_strUsername)
           .arg(m_dateAddDate.toString("yyyy-MM-dd"))
           .arg(m_lRights.strName)
           .arg(m_lRights.nLevel);
}

// Защищенные методы
void CUser::fEmitDataChanged()
{
    emit userDataChanged();
}

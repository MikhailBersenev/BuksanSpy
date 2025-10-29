#ifndef CUSER_H
#define CUSER_H

#include "../objects/CSecLabeledObject.h"
#include <QString>
#include <QDate>

class CUser : public CSecLabeledObject
{
    Q_OBJECT

public:
    explicit CUser(QObject *parent = nullptr);
    explicit CUser(qint64 nUserId, const QString &strUsername, const QDate &dateAddDate, const CSecLabeledObject::SecurityLabel &lRights, QObject *parent = nullptr);
    virtual ~CUser();

    // Основные геттеры
    qint64 fGetUserId() const;
    QString fGetUsername() const;
    QDate fGetAddDate() const;
    CSecLabeledObject::SecurityLabel fGetRights() const;

    // Основные сеттеры
    void fSetUserId(qint64 nUserId);
    void fSetUsername(const QString &strUsername);
    void fSetAddDate(const QDate &dateAddDate);
    void fSetRights(const CSecLabeledObject::SecurityLabel &lRights);

    // Утилитарные методы
    bool fIsValid() const;
    QString fToString() const;

signals:
    void userDataChanged();

protected:
    // Внутренние методы
    void fEmitDataChanged();

private:
    qint64 m_nUserId;        // Первичный ключ
    QString m_strUsername;    // Имя пользователя
    QDate m_dateAddDate;     // Дата регистрации
    CSecLabeledObject::SecurityLabel m_lRights;  // Мандатная метка группы
};

#endif // CUSER_H

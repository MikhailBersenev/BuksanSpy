#ifndef SENDALERT_H
#define SENDALERT_H
#include <QtSql>
#include <QMainWindow>
#include <QObject>
#include <QTime>
#include <QDate>
#include <QDateTime>
class SendAlert : public QObject
{
    Q_OBJECT
public:
    explicit SendAlert(QObject *parent = nullptr);
    void prepare();
    void setUser(QString user);
    void setSignature(qint16 signature);
    void setDevice(QString device);
    bool send();

private:
    QSqlQuery *MainQuery;
    QSqlQuery *FindItem_Query;
    QString CreateFullLog(QString data);
    QString fldata;

signals:

};

#endif // SENDALERT_H

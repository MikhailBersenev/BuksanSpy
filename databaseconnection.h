#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include <QtSql>
#include <QObject>
#include "sendalert.h"
class SendAlert;
class DataBaseConnection : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseConnection(QObject *parent = nullptr);
    bool CreateConnection(QString HostName, QString DBName, QString UserName, QString Password, int Port);
    QSqlDatabase db;
    SendAlert *SendAlert_var;
private slots:

signals:

};

#endif // DATABASECONNECTION_H

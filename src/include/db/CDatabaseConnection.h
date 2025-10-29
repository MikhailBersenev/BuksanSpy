#ifndef CDATABASECONNECTION_H
#define CDATABASECONNECTION_H

#include <QObject>
#include <QtSql>

class CDatabaseConnection : public QObject
{
    Q_OBJECT
public:
    explicit CDatabaseConnection(QObject *parent = nullptr);
    enum NDMSType {
        PostgreSQL
    };

    struct SDBConnection {
        QString strHostName = "";
        QString strDBName = "";
        QString strUserName = "";
        QString strPassword = "";
        int nPort;
    };
    virtual bool fCreateConnection(SDBConnection& lConnection) = 0;
    const QSqlDatabase fGetDatabase();
    bool fCloseConnection();

public:
    QSqlDatabase m_db;

signals:

};

#endif // CDATABASECONNECTION_H

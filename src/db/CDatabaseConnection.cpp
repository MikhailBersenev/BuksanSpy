#include "CDatabaseConnection.h"

CDatabaseConnection::CDatabaseConnection(QObject *parent)
    : QObject{parent}
{}

const QSqlDatabase CDatabaseConnection::fGetDatabase()
{
    return m_db;
}

bool CDatabaseConnection::fCloseConnection()
{
    if(!m_db.isValid()) {
        qDebug() << "database is not valid";
        return false;
    }
    if(m_db.isOpen()) {
        m_db.close();
        qDebug() << "connection closed";
        return true;
    }
    else
        qDebug() << "connection was not open";
    return false;

}

#include "CDatabaseConnection.h"
#include "Loggerd.h"

CDatabaseConnection::CDatabaseConnection(QObject *parent)
    : QObject{parent}
{
    LOG_TRACE_MSG("CDatabaseConnection constructed");
}

const QSqlDatabase CDatabaseConnection::fGetDatabase()
{
    return m_db;
}

bool CDatabaseConnection::fCloseConnection()
{
    if(!m_db.isValid()) {
        LOG_INFO_MSG("fCloseConnection: database is not valid");
        return false;
    }
    if(m_db.isOpen()) {
        m_db.close();
        LOG_INFO_MSG("Database connection closed");
        return true;
    }
    else
        LOG_DEBUG_MSG("fCloseConnection: connection was not open");
    return false;

}

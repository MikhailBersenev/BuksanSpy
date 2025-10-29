#include "CMediaFile.h"
#include <QDebug>

QString CMediaFile::fGetPath()
{
    qDebug() << "fGetPath m_strPath = " << m_strPath;
    if(!m_strPath.isEmpty())
        return m_strPath;
    return QString();
}

void CMediaFile::fSetPath(QString strPath)
{
    if(strPath.isEmpty())
        return;
    m_strPath = strPath;
}

QString CMediaFile::fGetFileName()
{
    if(!m_strFileName.isEmpty())
        return m_strFileName;
    return QString();
}

void CMediaFile::fSetFileName(QString strFileName)
{
    if(strFileName.isEmpty())
        return;
    m_strFileName = strFileName;
}

CMediaFile::CMediaFile(QString &strPath, QString strFileName, QObject *parent)
    : CSecLabeledObject{parent}, m_strPath{strPath}, m_strFileName{strFileName}
{

}


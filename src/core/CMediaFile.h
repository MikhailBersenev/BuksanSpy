#ifndef CMEDIAFILE_H
#define CMEDIAFILE_H

#include "../MRBAC/objects/CSecLabeledObject.h"

class CMediaFile : public CSecLabeledObject
{
public:
    virtual bool fOpen() = 0;
    virtual bool fClose() = 0;
    virtual QString fGetPath();
    virtual void fSetPath(QString strPath);
    virtual QString fGetFileName();
    virtual void fSetFileName(QString strFileName);


private:
    QString m_strPath;
    QString m_strFileName;
protected:
    explicit CMediaFile(QString &strPath, QString strFileName, QObject *parent = nullptr);
};

#endif // CMEDIAFILE_H

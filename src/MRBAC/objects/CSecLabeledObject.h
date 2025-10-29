#ifndef CSECLABELEDOBJECT_H
#define CSECLABELEDOBJECT_H

#include <QObject>

class CSecLabeledObject : public QObject
{
    Q_OBJECT
public:
    struct SecurityLabel {
        QString strName = "";
        unsigned int nLevel = 0;
    };
protected:
    explicit CSecLabeledObject(QObject *parent = nullptr);
    SecurityLabel fGetSecurityLabel();
    void fSetSecurityLabel(SecurityLabel& lSecLabel);
    bool fCanRead(CSecLabeledObject& lObject);
    bool fCanWrite(CSecLabeledObject& lObject);
private:
    SecurityLabel m_SecurityLabel;
    unsigned int m_nId;
signals:
};

#endif // CSECLABELEDOBJECT_H

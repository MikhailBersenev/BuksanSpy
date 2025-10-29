#include "CSecLabeledObject.h"

CSecLabeledObject::CSecLabeledObject(QObject *parent)
    : QObject{parent}, m_nId{0}
{}

void CSecLabeledObject::fSetSecurityLabel(SecurityLabel &lSecLabel)
{
    m_SecurityLabel = lSecLabel;
}

bool CSecLabeledObject::fCanRead(CSecLabeledObject &lObject)
{
    return lObject.fGetSecurityLabel().nLevel <= this->fGetSecurityLabel().nLevel;
}

bool CSecLabeledObject::fCanWrite(CSecLabeledObject &lObject)
{
    return lObject.fGetSecurityLabel().nLevel >= this->fGetSecurityLabel().nLevel;
}

CSecLabeledObject::SecurityLabel CSecLabeledObject::fGetSecurityLabel()
{
    return m_SecurityLabel;
}

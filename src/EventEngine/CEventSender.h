#ifndef CEVENTSENDER_H
#define CEVENTSENDER_H

#include <QObject>

#include "CEventEngine.h"

class CEventSender : public QObject
{
    Q_OBJECT
public:
    explicit CEventSender(QObject *parent = nullptr);
    ~CEventSender();
    bool fSendEvent(CEvent* pEvent);
    bool fAddEngine(CEventEngine* pEngine);
private:
    QList<CEventEngine*> *m_vEngines;
signals:
};

#endif // CEVENTSENDER_H

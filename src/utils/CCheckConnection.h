#ifndef CCHECKCONNECTION_H
#define CCHECKCONNECTION_H
#include <QThread>
#include <QObject>
#include <QTimer>

class CSendAlert;
class CCheckConnection : public QTimer
{
    Q_OBJECT
public:
    explicit CCheckConnection(QObject *parent = nullptr);
    QString m_strUsername;

signals:

private:
    CSendAlert *m_pSendAlert;
    int m_nPreviousState;

private slots:
    void fCheckInternet();
};

#endif // CCHECKCONNECTION_H

#ifndef CCHECKCONNECTION_H
#define CCHECKCONNECTION_H
#include <QThread>
#include <QObject>
#include <QTimer>

class CEventHelper;

class CCheckConnection : public QTimer
{
    Q_OBJECT
public:
    explicit CCheckConnection(QObject *parent = nullptr);
    QString m_strUsername;

signals:

private:
    CEventHelper *m_pEventHelper;
    int m_nPreviousState;

private slots:
    void fCheckInternet();
};

#endif // CCHECKCONNECTION_H

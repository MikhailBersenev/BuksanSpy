#ifndef CHECKCONNECTION_H
#define CHECKCONNECTION_H
#include <QThread>
#include <QObject>
#include <QNetworkConfigurationManager>
#include <QTimer>
#include "sendalert.h"
class CheckConnection : public QThread
{
    Q_OBJECT
public:
    explicit CheckConnection(QObject *parent = nullptr);
    QString username;
    ~CheckConnection();

signals:
private:
QTimer *timer;
SendAlert *SendAlert_var;
int previousstate;

private slots:
void CheckInternet();

};

#endif // CHECKCONNECTION_H

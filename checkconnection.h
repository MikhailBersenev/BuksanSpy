#ifndef CHECKCONNECTION_H
#define CHECKCONNECTION_H
#include <QThread>
#include <QObject>
#include <QTimer>
#include "sendalert.h"
class CheckConnection : public QTimer
{
    Q_OBJECT
public:
    explicit CheckConnection(QObject *parent = nullptr);
    QString username;


signals:
private:
SendAlert *SendAlert_var;
int previousstate;

private slots:
void CheckInternet();

};

#endif // CHECKCONNECTION_H

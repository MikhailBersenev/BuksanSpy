#ifndef NETWORKINFO_H
#define NETWORKINFO_H
#include <QObject>
#include <QTimer>
#include<QNetworkConfigurationManager>
class NetworkInfo : public  QNetworkConfigurationManager
{
    Q_OBJECT
public:
    explicit NetworkInfo(QObject *parent = nullptr);
    QString GetIPAddress();



signals:

};

#endif // NETWORKINFO_H

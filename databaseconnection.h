#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QObject>

class DataBaseConnection : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseConnection(QObject *parent = nullptr);

signals:

};

#endif // DATABASECONNECTION_H

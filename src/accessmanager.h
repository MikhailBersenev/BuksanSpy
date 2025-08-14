#ifndef ACCESSMANAGER_H
#define ACCESSMANAGER_H
#include <QObject>
#include <QtSql>
class AccessManager : public QObject
{
    Q_OBJECT
public:
    explicit AccessManager(QObject *parent = nullptr);
    bool checkright(QString username, int right);
    QString GetMandatoryGroup(QString username);
    qint64 GetAccessLevel(QString username);


private:
    QSqlQuery *MainQuery;

signals:

};

#endif // ACCESSMANAGER_H

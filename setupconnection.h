#ifndef SETUPCONNECTION_H
#define SETUPCONNECTION_H
#include <sendalert.h>
#include <QDialog>
#include <QtSql>
namespace Ui {
class SetupConnection;
class SendAlert;
}

class SetupConnection : public QDialog
{
    Q_OBJECT

public:
    explicit SetupConnection(QWidget *parent = nullptr);
    ~SetupConnection();
    QSqlDatabase db;
    bool CreateConnection(QString HostName, QString DBName, QString UserName, QString Password, int Port);

private slots:
    void on_TryConnect_Button_clicked();

private:

    Ui::SetupConnection *ui;
    SendAlert *SendAlert_var;

};

#endif // SETUPCONNECTION_H

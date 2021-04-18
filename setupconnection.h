#ifndef SETUPCONNECTION_H
#define SETUPCONNECTION_H
#include "databaseconnection.h"
#include <QDialog>
#include <QtSql>
namespace Ui {
class SetupConnection;
}

class SetupConnection : public QDialog
{
    Q_OBJECT

public:
    explicit SetupConnection(QWidget *parent = nullptr);
    ~SetupConnection();
    DataBaseConnection *PostgresConnection = new DataBaseConnection;

private slots:
    void on_TryConnect_Button_clicked();


private:

    Ui::SetupConnection *ui;


};

#endif // SETUPCONNECTION_H

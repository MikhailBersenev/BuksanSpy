#ifndef EVENTLOG_H
#define EVENTLOG_H
#include <QtSql>
#include <QDialog>

namespace Ui {
class eventlog;
}

class eventlog : public QDialog
{
    Q_OBJECT

public:
    explicit eventlog(QWidget *parent = nullptr);
    ~eventlog();



private slots:
    void on_TryFind_Button_clicked();
    void UpdateModels();


    void on_StrToSearch_Edit_textChanged(const QString &arg1);

private:
    Ui::eventlog *ui;
    QSqlQueryModel *alerts_model;

};

#endif // EVENTLOG_H

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

private:
    Ui::eventlog *ui;
    QSqlQueryModel *alerts_model;
    void UpdateModels();
};

#endif // EVENTLOG_H

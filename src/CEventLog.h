#ifndef CEVENTLOG_H
#define CEVENTLOG_H
#include <QtSql>
#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class CEventLog;
}

class CEventLog : public QDialog
{
    Q_OBJECT

public:
    explicit CEventLog(QWidget *parent = nullptr);
    ~CEventLog();

private slots:
    void on_TryFind_Button_clicked();
    void fUpdateModels(QString strSort);
    void on_StrToSearch_Edit_textChanged(const QString &strArg1);
    void on_sort_comboBox_currentIndexChanged(int nIndex);

private:
    Ui::CEventLog *m_pUi;
    QSqlQueryModel *m_pAlertsModel;
    void fSetHeaders();
};

#endif // CEVENTLOG_H

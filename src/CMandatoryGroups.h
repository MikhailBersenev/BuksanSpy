#ifndef CMANDATORYGROUPS_H
#define CMANDATORYGROUPS_H
#include <QtSql>
#include <QDialog>
#include "CAccessManager.h"
#include "CEditMandatoryGroup.h"

namespace Ui {
class CMandatoryGroups;
}

class CMandatoryGroups : public QDialog
{
    Q_OBJECT

public:
    explicit CMandatoryGroups(QWidget *parent = nullptr, QString strUser = nullptr);
    ~CMandatoryGroups();
    void fUpdateModels();

private slots:
    void on_DeleteMandatoryGroup_Button_clicked();
    void on_AddMandatoryGroup_Button_clicked();
    void on_MandatoryGroupslistView_clicked(const QModelIndex &index);
    void on_EditMandatoryGroup_pushButton_clicked();

private:
    Ui::CMandatoryGroups *m_pUi;
    QSqlQueryModel m_mandatoryGroupsModel;
    QSqlQuery *m_pMainQuery;
    CAccessManager *m_pAccessManager;
    CEditMandatoryGroup *m_pWindow;
    QString m_strUsername;
    int m_nRALCounter;
};

#endif // CMANDATORYGROUPS_H

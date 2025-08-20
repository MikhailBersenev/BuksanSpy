#ifndef CEDITMANDATORYGROUP_H
#define CEDITMANDATORYGROUP_H
#include <QtSql>
#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class CEditMandatoryGroup;
}

class CEditMandatoryGroup : public QDialog
{
    Q_OBJECT

public:
    explicit CEditMandatoryGroup(QWidget *parent = nullptr, int nMode = 0, int nMandatoryGroupId = 0, QString strMandatoryGroupDescription = nullptr);
    ~CEditMandatoryGroup();

private slots:
    void on_buttonBox_rejected();
    void on_UserControl_checkBox_stateChanged(int nArg1);
    void on_AddDevice_checkBox_stateChanged(int nArg1);
    void on_editDevice_checkBox_stateChanged(int nArg1);
    void on_DeleteDevice_checkBox_stateChanged(int nArg1);
    void on_alertsView_checkBox_stateChanged(int nArg1);
    void on_alertsDelete_checkBox_stateChanged(int nArg1);
    void on_generalSettingsView_checkBox_stateChanged(int nArg1);
    void on_generalSettingsChange_checkBox_stateChanged(int nArg1);
    void on_VideosView_checkBox_stateChanged(int nArg1);
    void on_VideosDecrypt_checkBox_stateChanged(int nArg1);
    void on_videosDelete_checkBox_stateChanged(int nArg1);
    void on_buttonBox_accepted();

private:
    Ui::CEditMandatoryGroup *m_pUi;
    QSqlQuery *m_pMainQuery;
    QSqlQueryModel m_mandatoryGroupsModel;
    int m_nMode;
    void fSetDefaultValues();
    void fRightsParser(int nMandatoryGroupId);
};

#endif // CEDITMANDATORYGROUP_H

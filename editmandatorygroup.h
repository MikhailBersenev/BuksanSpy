#ifndef EDITMANDATORYGROUP_H
#define EDITMANDATORYGROUP_H
#include <QtSql>
#include <QDialog>

namespace Ui {
class EditMandatoryGroup;
}

class EditMandatoryGroup : public QDialog
{
    Q_OBJECT

public:
    explicit EditMandatoryGroup(QWidget *parent = nullptr);
    ~EditMandatoryGroup();
    int mode;

private slots:
    void on_buttonBox_rejected();

    void on_UserControl_checkBox_stateChanged(int arg1);

    void on_AddDevice_checkBox_stateChanged(int arg1);

    void on_editDevice_checkBox_stateChanged(int arg1);

    void on_DeleteDevice_checkBox_stateChanged(int arg1);

    void on_alertsView_checkBox_stateChanged(int arg1);

    void on_alertsDelete_checkBox_stateChanged(int arg1);

    void on_generalSettingsView_checkBox_stateChanged(int arg1);

    void on_generalSettingsChange_checkBox_stateChanged(int arg1);

    void on_VideosView_checkBox_stateChanged(int arg1);

    void on_VideosDecrypt_checkBox_stateChanged(int arg1);

    void on_videosDelete_checkBox_stateChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::EditMandatoryGroup *ui;
    QSqlQuery *MainQuery;
    void SetDefaultValues();

};

#endif // EDITMANDATORYGROUP_H

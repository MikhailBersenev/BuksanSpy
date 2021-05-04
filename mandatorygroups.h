#ifndef MANDATORYGROUPS_H
#define MANDATORYGROUPS_H
#include <QtSql>
#include <QDialog>
#include "accessmanager.h"
#include "editmandatorygroup.h"

namespace Ui {
class MandatoryGroups;
}

class MandatoryGroups : public QDialog
{
    Q_OBJECT

public:
    explicit MandatoryGroups(QWidget *parent = nullptr, QString user = nullptr);
    ~MandatoryGroups();
    void UpdateModels();

private slots:
    void on_DeleteMandatoryGroup_Button_clicked();

    void on_AddMandatoryGroup_Button_clicked();


    void on_MandatoryGroupslistView_clicked(const QModelIndex &index);

    void on_EditMandatoryGroup_pushButton_clicked();

private:
    Ui::MandatoryGroups *ui;
    QSqlQueryModel MandatoryGroups_model;
    QSqlQuery *MainQuery;
    AccessManager *AccessManager_var;
    EditMandatoryGroup *Window;
    QString username;
    int RALCounter;
};

#endif // MANDATORYGROUPS_H

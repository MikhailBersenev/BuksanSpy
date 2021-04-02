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
    explicit MandatoryGroups(QWidget *parent = nullptr);
    ~MandatoryGroups();
    QString username;

private slots:
    void on_DeleteMandatoryGroup_Button_clicked();

    void on_AddMandatoryGroup_Button_clicked();
    void UpdateModels();

private:
    Ui::MandatoryGroups *ui;
    QSqlQueryModel MandatoryGroups_model;
    QSqlQuery *MainQuery;
    AccessManager *AccessManager_var;
    EditMandatoryGroup *Window;
};

#endif // MANDATORYGROUPS_H

#ifndef CUSERS_H
#define CUSERS_H
#include "CCreateUser.h"
#include "CAccessManager.h"
#include <QDialog>
#include <QtSql>
#include <QtWidgets>
#include <QLabel>
#include <QWidget>

namespace Ui {
class CUsers;
}

class CUsers : public QDialog
{
    Q_OBJECT

public:
    explicit CUsers(QWidget *parent = nullptr, QString strUser = nullptr);
    ~CUsers();
    QSqlQueryModel m_usersModel;
    CCreateUser *m_pCreateUser;
    QString m_strUsername;
    void fUpdateModels();

private slots:
    void on_AddUser_Button_clicked();
    void on_DeleteUser_Button_clicked();
    void on_users_listView_clicked(const QModelIndex &index);
    void on_MandatoryMarksEditor_toolButton_clicked();
    void on_MandatoryGroupsEditor_toolButton_clicked();
    void on_ChangePassword_action_triggered();

private:
    Ui::CUsers *m_pUi;
    QSqlQuery *m_pMainQuery;
    CAccessManager *m_pAccessManager;
    void fRoleAtributesParser(QString strUsername);
    QLabel *m_pRoleAtributeLabel;
    int m_nRALCounter;
    QWidget *m_pRoleAtrParent;
    bool fCheckForRoot();
};

#endif // CUSERS_H

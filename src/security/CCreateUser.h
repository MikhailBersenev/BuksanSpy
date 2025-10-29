#ifndef CCREATEUSER_H
#define CCREATEUSER_H
#include "utils/CStringUtils.h"
#include "utils/CUserCheck.h"
#include "utils/CEventHelper.h"
#include <QDialog>
#include <QtSql>

namespace Ui {
class CCreateUser;
}

class CCreateUser : public QDialog
{
    Q_OBJECT

public:
    explicit CCreateUser(QWidget *parent = nullptr);
    ~CCreateUser();

private slots:
    void on_ShowPassword_CheckBox_stateChanged(int nArg1);
    void on_Confirm_Button_clicked();

private:
    Ui::CCreateUser *m_pUi;
    QSqlQueryModel m_rightsModel;
    CUserCheck *m_pUserCheck;
    QSqlQuery *m_pCreateUserQuery;
    CEventHelper *m_pEventHelper;
};

#endif // CCREATEUSER_H

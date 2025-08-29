#ifndef CCREATEUSER_H
#define CCREATEUSER_H
#include "utils/CCheckString.h"
#include "utils/CSendAlert.h"
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
    CCheckString *m_pCheckPassword;
    QSqlQuery *m_pCreateUserQuery;
    CSendAlert *m_pSendAlert;
};

#endif // CCREATEUSER_H

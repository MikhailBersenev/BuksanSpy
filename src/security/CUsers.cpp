#include "CUsers.h"
#include "ui_CUsers.h"
#include <QtWidgets>
#include "ui/CMandatoryMarksEditor.h"
#include "ui/CMandatoryGroups.h"
#include <QMessageBox>
#include <QDebug>

CUsers::CUsers(QWidget *parent, QString strUser) :
    QDialog(parent),
    m_pUi(new Ui::CUsers)
{
    m_pUi->setupUi(this);
    m_strUsername = strUser;
    fUpdateModels();
}

CUsers::~CUsers()
{
    delete m_pUi;
}

void CUsers::on_AddUser_Button_clicked()
{
    m_pCreateUser = new CCreateUser; //показываем форму
    m_pCreateUser->exec();
    delete m_pCreateUser;
    fUpdateModels();
}

void CUsers::on_DeleteUser_Button_clicked()
{
    m_pAccessManager = new CAccessManager(this);
    QMessageBox::StandardButton l_reply;
    l_reply = QMessageBox::question(this, "Удаление пользователя", "Вы уверены, что хотите удалить пользователя? \n ВНИМАНИЕ! Удаление пользователя приведет к "
                                                                 "удалению всех связанных с ним данных", QMessageBox::Yes|QMessageBox::No);
    if(l_reply==QMessageBox::No)
    {
        return;
    }
    else
    {
        m_pMainQuery = new QSqlQuery;
        m_pMainQuery->prepare("DELETE FROM users WHERE username = :current;");
        m_pMainQuery->bindValue(":current", m_usersModel.data(m_usersModel.index(m_pUi->users_listView->currentIndex().row(),0)).toString());
        if(!m_pMainQuery->exec() || m_usersModel.query().value(1).toString()==m_strUsername)
        {
            qDebug() << "Unable to delete user" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить пользователя");
            return;
        }
        if(!m_pMainQuery->exec("DROP ROLE "+m_usersModel.data(m_usersModel.index(m_pUi->users_listView->currentIndex().row(),1)).toString()+";"))
        {
            qDebug() << "Unable to delete user" << m_pMainQuery->lastError() << m_pMainQuery->lastQuery();
        }
        else
        {
            QMessageBox::information(this, "Пользователи и группы", "Пользователь удален");
            fUpdateModels();
        }
    }
}

void CUsers::fUpdateModels()
{
    m_pAccessManager = new CAccessManager(this);
    m_usersModel.setQuery("SELECT  * FROM \"vUsers\" WHERE \"accessLevel\" >="+QString::number(m_pAccessManager->fGetAccessLevel(m_strUsername))+";");
    m_pUi->users_listView->setModel(&m_usersModel);
    m_pUi->users_listView->setModelColumn(1);
    qDebug() << m_pAccessManager->fGetAccessLevel(m_strUsername) << m_strUsername;
    delete m_pAccessManager;
}

void CUsers::on_users_listView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    addActions({m_pUi->ChangePassword_action});
    m_pUi->mandatorygroup_label_2->setText(m_usersModel.data(m_usersModel.index(m_pUi->users_listView->currentIndex().row(),3)).toString());
    m_pUi->registrationdate_label_2->setText(m_usersModel.data(m_usersModel.index(m_pUi->users_listView->currentIndex().row(),2)).toString());
    m_pUi->macm_label_2->setText(m_usersModel.data(m_usersModel.index(m_pUi->users_listView->currentIndex().row(),4)).toString());
    fRoleAtributesParser(m_usersModel.data(m_usersModel.index(m_pUi->users_listView->currentIndex().row(),1)).toString());
}

void CUsers::fRoleAtributesParser(QString strUsername)
{
    m_pMainQuery = new QSqlQuery;
    QStringList l_list;
    l_list << "Управление пользователями и группами" << "Добавление устройств" << "Редактирование устройств" << "Удаление устройств" << "Просмотр журнала событий" << "Очистка журнала событий" << "Просмотр настроек ПС" << "Изменение настроек ПС" << "Просмотр журнала видеозаписей" << "Выгрузка видеозаписей в файл" << "Удаление видеозаписей";
    if(m_nRALCounter!=0)
    {
        m_pUi->RoleAtributes_listWidget->clear();
        m_nRALCounter=0;
    }
    for (int l_i=0;l_i<l_list.size();l_i++) {
        if(m_usersModel.query().value(l_i+2).toBool())
        {
            m_pUi->RoleAtributes_listWidget->addItem(l_list.value(l_i));
        }
        m_nRALCounter++;
    }
}

void CUsers::on_MandatoryMarksEditor_toolButton_clicked()
{
    CMandatoryMarksEditor *l_pEditor = new CMandatoryMarksEditor(this, m_strUsername);
    l_pEditor->setModal(true);
    l_pEditor->exec();
    delete l_pEditor;
    fUpdateModels();
}

void CUsers::on_MandatoryGroupsEditor_toolButton_clicked()
{
    CMandatoryGroups *l_pGroups = new CMandatoryGroups(this, m_strUsername);
    l_pGroups->setModal(true);
    l_pGroups->exec();
    delete l_pGroups;
    fUpdateModels();
}

void CUsers::on_ChangePassword_action_triggered()
{
    // Реализация изменения пароля
    QMessageBox::information(this, "Изменение пароля", "Функция изменения пароля будет реализована позже");
}

bool CUsers::fCheckForRoot()
{
    // Проверка на права root
    return m_strUsername == "root";
}

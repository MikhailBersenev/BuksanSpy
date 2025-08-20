#include "CEventLog.h"
#include "CDatabaseConnection.h"
#include "ui_CEventLog.h"
#include <QDebug>

CEventLog::CEventLog(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CEventLog)
{
    m_pUi->setupUi(this);
    fUpdateModels("DESC"); //Обновление таблицы при запуске формы
    fSetHeaders();
}

CEventLog::~CEventLog()
{
    delete m_pAlertsModel;
    delete m_pUi;
}

void CEventLog::fUpdateModels(QString strSort)
{ //Задаем модель
    m_pAlertsModel = new QSqlQueryModel;
    m_pAlertsModel->setQuery("SELECT * FROM \"vAlerts\" ORDER BY timestamp " + strSort + ";");
    m_pAlertsModel->removeColumn(0);
    m_pAlertsModel->removeColumn(4);
    m_pUi->alerts_table->setColumnWidth(0, 200);
    m_pUi->alerts_table->setColumnWidth(4, 250);
    fSetHeaders();
}

void CEventLog::on_TryFind_Button_clicked()
{
    //Поиск по записям
    const QString l_strSearchQuery = m_pUi->StrToSearch_Edit->text();
    m_pAlertsModel->setQuery("SELECT * FROM \"vAlerts\" WHERE \"fullLog\" LIKE '%" + l_strSearchQuery + "%';");
    m_pAlertsModel->removeColumn(0);
    m_pAlertsModel->removeColumn(4);
    fSetHeaders();
}

void CEventLog::on_StrToSearch_Edit_textChanged(const QString &strArg1)
{
    Q_UNUSED(strArg1)
    if(m_pUi->StrToSearch_Edit->text().isEmpty())
    {
        fUpdateModels("DESC"); //Возврат ко всем записям при пустом поле поиска
    }
}

void CEventLog::fSetHeaders()
{//Задаем заголовки столбцов
    QVariantList l_headersList;
    l_headersList << "IP Адрес" << "Пользователь" << "Время" << "Дата" << "Событие" << "Тип события" << "Подробно";
    int l_nI = 0;
    foreach(QVariant l_header, l_headersList)
    {
        m_pAlertsModel->setHeaderData(l_nI, Qt::Horizontal, l_header);
        l_nI++;
    }
    m_pUi->alerts_table->setModel(&*m_pAlertsModel);
}

void CEventLog::on_sort_comboBox_currentIndexChanged(int nIndex)
{
    switch (nIndex) {
    case 0:
        fUpdateModels("DESC");
        break;
    case 1:
        fUpdateModels("ASC");
        break;
    }
}

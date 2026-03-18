#include "CEventLog.h"
#include "ui_CEventLog.h"
#include "Loggerd.h"
#include <QString>

CEventLog::CEventLog(QWidget *parent) :
    QDialog(parent),
    m_pUi(new Ui::CEventLog)
{
    m_pUi->setupUi(this);
    fUpdateModels("DESC"); //Обновление таблицы при запуске формы
    fSetHeaders();
    LOG_INFO_MSG("CEventLog dialog opened");
}

CEventLog::~CEventLog()
{
    LOG_INFO_MSG("CEventLog dialog closed");
    delete m_pAlertsModel;
    delete m_pUi;
}

void CEventLog::fUpdateModels(QString strSort)
{ //Задаем модель
    LOG_DEBUG_MSG((QStringLiteral("CEventLog::fUpdateModels sort=") + strSort).toStdString());
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
    const QString l_strSearchQuery = m_pUi->StrToSearch_Edit->text();
    LOG_INFO_MSG((QStringLiteral("CEventLog search: ") + l_strSearchQuery).toStdString());
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
    l_headersList << "IP Address" << "Username" << "Time" << "Date" << "Event" << "Event type" << "Additional Information";
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

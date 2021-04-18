#include "eventlog.h"
#include "setupconnection.h"
#include "databaseconnection.h"
#include "ui_eventlog.h"
eventlog::eventlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventlog)
{
    ui->setupUi(this);
    UpdateModels(); //Обновление таблицы при запуске формы




}

eventlog::~eventlog()
{
    delete alerts_model;
    delete ui;
}

void eventlog::UpdateModels()
{ //Задаем заголовки столбцов и модель
    QVariantList headers_list;
    headers_list << "IP Адрес" << "Пользователь" << "Время" << "Дата" << "Событие" << "Тип события" << "Подробно";
    int i;
    alerts_model = new QSqlQueryModel(this);
    alerts_model->setQuery("SELECT * FROM \"vAlerts\" ORDER BY timestamp DESC;");
    alerts_model->removeColumn(0);
    alerts_model->removeColumn(4);
    ui->alerts_table->setColumnWidth(0,250);
    ui->alerts_table->setColumnWidth(4,300);
    foreach(headers_list.value(i), headers_list)
    {
        alerts_model->setHeaderData(i, Qt::Horizontal, headers_list.value(i));
        i++;
    }
    ui->alerts_table->setModel(&*alerts_model);

}

void eventlog::on_TryFind_Button_clicked()
{
    //Поиск по записям
    QString search_field;
    const QString search_query = ui->StrToSearch_Edit->text();
    switch (ui->Field_ComboBox->currentIndex()) {
    case 0:
        search_field = "host";
        break;
    case 1:
        search_field = "signature";
        break;
    case 2:
        search_field ="\"alertType\"";
        break;
    case 3:
        search_field = "user";
        break;
    case 4:
        search_field = "time";
        break;
    case 5:
        search_field = "date";
        break;
    case 6:
        search_field = "\"fullLog\"";
        break;
    default:
        search_field = "host";
        break;

    }
    alerts_model->query().bindValue(":field", search_field);
    alerts_model->query().bindValue(":query", search_query);
    alerts_model->setQuery("SELECT * FROM \"vAlerts\" WHERE :field = :query ORDER BY timestamp DESC;");
    ui->alerts_table->setModel(&*alerts_model);
    qDebug() << alerts_model->query().lastQuery();


}

void eventlog::on_StrToSearch_Edit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    if(ui->StrToSearch_Edit->text().isEmpty())
    {
        UpdateModels(); //Возврат ко всем записям при пустом поле поиска
    }
}

#include "eventlog.h"
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
{
    QVariantList headers_list;
    headers_list << "IP Адрес" << "Пользователь" << "Время" << "Дата" << "Событие" << "Тип события" << "Подробно";
    int i;
    alerts_model = new QSqlQueryModel(this);
    alerts_model->setQuery("SELECT * FROM \"vAlerts\" ORDER BY timestamp ASC;");
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

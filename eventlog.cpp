#include "eventlog.h"
#include "setupconnection.h"
#include "databaseconnection.h"
#include "ui_eventlog.h"
eventlog::eventlog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventlog)
{
    ui->setupUi(this);
    UpdateModels("DESC"); //Обновление таблицы при запуске формы
    SetHeaders();

}

eventlog::~eventlog()
{
    delete alerts_model;
    delete ui;
}

void eventlog::UpdateModels(QString sort)
{ //Задаем модель

    alerts_model = new QSqlQueryModel;
    alerts_model->setQuery("SELECT * FROM \"vAlerts\" ORDER BY timestamp "+sort+";");
    alerts_model->removeColumn(0);
    alerts_model->removeColumn(4);
    ui->alerts_table->setColumnWidth(0,200);
    ui->alerts_table->setColumnWidth(4,250);
    SetHeaders();


}

void eventlog::on_TryFind_Button_clicked()
{
    //Поиск по записям

    const QString search_query = ui->StrToSearch_Edit->text();
    alerts_model->setQuery("SELECT * FROM \"vAlerts\" WHERE \"fullLog\" LIKE '%"+search_query+"%';");
    alerts_model->removeColumn(0);
    alerts_model->removeColumn(4);
    SetHeaders();

}

void eventlog::on_StrToSearch_Edit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    if(ui->StrToSearch_Edit->text().isEmpty())
    {
        UpdateModels("DESC"); //Возврат ко всем записям при пустом поле поиска

    }
}

void eventlog::SetHeaders()
{//Задаем заголовки столбцов
    QVariantList headers_list;
    headers_list << "IP Адрес" << "Пользователь" << "Время" << "Дата" << "Событие" << "Тип события" << "Подробно";
    int i;
    foreach(headers_list.value(i), headers_list)
    {
        alerts_model->setHeaderData(i, Qt::Horizontal, headers_list.value(i));
        i++;
    }
    ui->alerts_table->setModel(&*alerts_model);
}

void eventlog::on_sort_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        UpdateModels("DESC");
        break;
    case 1:
        UpdateModels("ASC");
        break;
    }
}

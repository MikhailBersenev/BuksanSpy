#ifndef DEVICES_H
#define DEVICES_H

#include <QDialog>
#include <QtSql>
#include <QtWidgets>
#include "cameravideocapture.h"
namespace Ui {
class Devices;
}

class Devices : public QDialog
{
    Q_OBJECT

public:
    explicit Devices(QWidget *parent = nullptr);
    ~Devices();

private slots:
    void on_AddDevice_Button_clicked();

    void on_DeleteDevice_Button_clicked();

private:
    Ui::Devices *ui;
    QSqlQuery *Dev_Query;
    QLabel *devpic_Label;
    QLabel *devtype_Label;
    QLabel *devtitle_Label;
    QBoxLayout *devndesc_Layout;
    int ic;
};

#endif // DEVICES_H

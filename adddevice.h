#ifndef ADDDEVICE_H
#define ADDDEVICE_H
#include <QtSql>
#include <QDialog>
#include <QCameraInfo>
namespace Ui {
class AddDevice;
}

class AddDevice : public QDialog
{
    Q_OBJECT

public:
    explicit AddDevice(QWidget *parent = nullptr);
    ~AddDevice();




private slots:
    void on_buttonBox_accepted();



    void on_DevType_ComboBox_currentIndexChanged(int index);



private:
    Ui::AddDevice *ui;
    QSqlQueryModel *dev_types_model;
    void SetMode(int mode);
    QLineEdit  *rtsp_edit;
    QComboBox *webcamera_ComboBox;
    QString devid;
    QSqlQueryModel *resolutions_model;


};

#endif // ADDDEVICE_H

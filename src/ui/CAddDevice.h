#ifndef CADDDEVICE_H
#define CADDDEVICE_H
#include <QtSql>
#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QSqlQueryModel>

namespace Ui {
class CAddDevice;
}

class CAddDevice : public QDialog
{
    Q_OBJECT

public:
    explicit CAddDevice(QWidget *parent = nullptr);
    ~CAddDevice();

private slots:
    void on_buttonBox_accepted();
    void on_DevType_ComboBox_currentIndexChanged(int index);

private:
    Ui::CAddDevice *m_pUi;
    QSqlQueryModel *m_pDevTypesModel;
    void fSetMode(int nMode);
    QLineEdit  *m_pRtspEdit;
    QComboBox *m_pWebcameraComboBox;
    QString m_strDevId;
    QSqlQueryModel *m_pResolutionsModel;
};

#endif // CADDDEVICE_H

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

class CCameraVideoCapture;
class CAddDevicePreviewViewFinder;

class CAddDevice : public QDialog
{
    Q_OBJECT

public:
    explicit CAddDevice(QWidget *parent = nullptr);
    ~CAddDevice();

private slots:
    void on_buttonBox_accepted();
    void on_DevType_ComboBox_currentIndexChanged(int index);
    void onOnvifSetupClicked();
    void onPreviewButtonClicked();
    void onPreviewFrameReady();

private:
    Ui::CAddDevice *m_pUi;
    void fSetMode(int nMode);
    void stopPreview();
    QLineEdit  *m_pRtspEdit;
    QComboBox *m_pWebcameraComboBox;
    QSqlQueryModel *m_pResolutionsModel;
    CCameraVideoCapture *m_pPreviewCapture = nullptr;
    CAddDevicePreviewViewFinder *m_pPreviewViewFinder = nullptr;
};

#endif // CADDDEVICE_H

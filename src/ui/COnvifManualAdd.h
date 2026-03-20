#ifndef CONVIFMANUALADD_H
#define CONVIFMANUALADD_H

#include <QDialog>
#include <QString>

#include "camera/OnvifClient.h"

namespace Ui {
class COnvifManualAdd;
}

/**
 * @brief Manual ONVIF dialog: device service URL, profile, credentials, RTSP retrieval.
 */
class COnvifManualAdd : public QDialog
{
    Q_OBJECT

public:
    explicit COnvifManualAdd(QWidget *parent = nullptr);
    ~COnvifManualAdd() override;

    /** Last successfully obtained RTSP URL (for Add device form). */
    QString rtspUrl() const;

    /** Pre-fill credentials from parent (e.g. Add device). */
    void setInitialCredentials(const QString &username, const QString &password);

private slots:
    void onGetRtspClicked();
    void onAccepted();


private:
    Ui::COnvifManualAdd *m_pUi;
    OnvifClient *m_pOnvifClient;
    QString m_rtspUrl;
};

#endif // CONVIFMANUALADD_H

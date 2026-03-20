#ifndef CONVIFSETUPDIALOG_H
#define CONVIFSETUPDIALOG_H

#include <QDialog>
#include <QString>
#include <QVector>

#include "camera/OnvifClient.h"

namespace Ui {
class COnvifSetupDialog;
}

/**
 * @brief Dialog for ONVIF camera discovery and RTSP retrieval (multicast, by IP, manual IP).
 *
 * Opened from Add device for IP cameras; keeps ONVIF separate from the main form.
 */
class COnvifSetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit COnvifSetupDialog(QWidget *parent = nullptr);
    ~COnvifSetupDialog() override;

    /** RTSP URL to fill into the connection field after OK. */
    QString selectedRtspUrl() const;

    /** Suggested device caption (model / camera name). */
    QString suggestedCaption() const;

private slots:
    void onSearchByIpClicked();
    void onDiscoverClicked();
    void onCameraSelected(int index);
    void onManualAddClicked();
    void onDialogAccepted();

private:
    Ui::COnvifSetupDialog *m_pUi;
    OnvifClient *m_pOnvifClient;
    QVector<OnvifCamera> m_cameras;

    QString m_storedRtspUrl;
    QString m_storedCaption;
};

#endif // CONVIFSETUPDIALOG_H

#ifndef CCAMERA_H
#define CCAMERA_H

#include "../MRBAC/objects/CSecLabeledObject.h"

class CCamera : public CSecLabeledObject
{
public:
    explicit CCamera(QObject *parent = nullptr);
    virtual ~CCamera() = default;

    // --- Connection ---
    virtual bool fConnect(const QString& url, const QString& user, const QString& password) = 0;
    virtual void fDisconnect() = 0;
    virtual bool fIsConnected() const = 0;

    // --- Device Management ---
    virtual QString fGetDeviceInformation() { return "Not supported"; }
    virtual QString fGetSystemDateAndTime() { return "Not supported"; }
    virtual QString fGetCapabilities() { return "Not supported"; }
    virtual QString fGetNetworkInterfaces() { return "Not supported"; }

    // --- Media ---
    virtual QStringList fGetProfiles() { return {}; }
    virtual QString fGetStreamUri(const QString& /*profileToken*/) { return {}; }
    virtual QString fGetSnapshotUri(const QString& /*profileToken*/) { return {}; }

    // --- PTZ ---
    virtual bool fContinuousMove(float /*pan*/, float /*tilt*/, float /*zoom*/) { return false; }
    virtual bool fRelativeMove(float /*pan*/, float /*tilt*/, float /*zoom*/) { return false; }
    virtual bool fAbsoluteMove(float /*pan*/, float /*tilt*/, float /*zoom*/) { return false; }
    virtual bool fStop() { return false; }
    virtual QStringList fGetPresets() { return {}; }
    virtual bool fGotoPreset(const QString& /*presetToken*/) { return false; }

    // --- Events ---
    virtual bool fSubscribeEvents() { return false; }
    virtual bool fUnsubscribeEvents() { return false; }
    virtual QList<QString> fPullMessages() { return {}; }

    // --- Imaging ---
    virtual bool fSetImagingSettings(float /*brightness*/, float /*contrast*/, float /*saturation*/, float /*sharpness*/) { return false; }
    virtual QString fGetImagingSettings() { return "Not supported"; }
};

#endif // CCAMERA_H

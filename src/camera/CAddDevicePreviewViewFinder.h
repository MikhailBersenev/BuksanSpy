#ifndef CADDDEVICEPREVIEWVIEWFINDER_H
#define CADDDEVICEPREVIEWVIEWFINDER_H

#include "AbstractViewFinder.h"

/**
 * @brief View finder for RTSP preview in the Add device dialog.
 *
 * Forwards frames to AbstractViewFinder via updateCurrentFrame().
 */
class CAddDevicePreviewViewFinder : public AbstractViewFinder
{
public:
    explicit CAddDevicePreviewViewFinder(QWidget *parent = nullptr)
        : AbstractViewFinder(parent)
    {
    }

    void displayFrame(const QImage &frame) override { updateCurrentFrame(frame); }

    void clearFrame() { updateCurrentFrame(QImage()); }
};

#endif // CADDDEVICEPREVIEWVIEWFINDER_H

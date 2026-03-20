#ifndef ABSTRACTVIEWFINDER_H
#define ABSTRACTVIEWFINDER_H

#include <QImage>
#include <QMutex>
#include <QWidget>

/**
 * @brief Abstract base widget for displaying live video frames.
 *
 * This class provides common, thread-safe frame storage and paint logic for
 * view finder widgets. Subclasses implement `displayFrame()` for specific
 * stream backends (for example FFmpeg, HLS, or RTSP) and should call
 * `updateCurrentFrame()` after receiving a decoded frame.
 */
class AbstractViewFinder : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Defines how incoming frames are mapped to the widget area.
     */
    enum class ScalingMode {
        Fit,             ///< Keep aspect ratio and fit into widget
        Stretch,         ///< Stretch to fill widget, may distort aspect ratio
        KeepAspectRatio  ///< Keep aspect ratio and cover available area
    };
    Q_ENUM(ScalingMode)

    explicit AbstractViewFinder(QWidget *parent = nullptr);
    ~AbstractViewFinder() override = default;

    /**
     * @brief Display a new decoded frame.
     *
     * Subclasses should receive frames from their backend and forward them to
     * `updateCurrentFrame(frame)`.
     */
    virtual void displayFrame(const QImage &frame) = 0;

    void setScalingMode(ScalingMode mode);
    ScalingMode scalingMode() const;

signals:
    /**
     * @brief Emitted whenever a new frame is accepted for display.
     */
    void frameUpdated();

protected:
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief Thread-safe helper to store frame and request repaint.
     *
     * Safe to call from worker threads.
     */
    void updateCurrentFrame(const QImage &frame);

private:
    mutable QMutex m_frameMutex;
    QImage m_currentFrame;
    ScalingMode m_scalingMode;
};

#endif // ABSTRACTVIEWFINDER_H

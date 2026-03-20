#include "AbstractViewFinder.h"

#include <QMetaObject>
#include <QMutexLocker>
#include <QPaintEvent>
#include <QPainter>

AbstractViewFinder::AbstractViewFinder(QWidget *parent)
    : QWidget(parent)
    , m_scalingMode(ScalingMode::Fit)
{
    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setAutoFillBackground(false);
}

void AbstractViewFinder::setScalingMode(ScalingMode mode)
{
    if (m_scalingMode == mode) {
        return;
    }
    m_scalingMode = mode;
    update();
}

AbstractViewFinder::ScalingMode AbstractViewFinder::scalingMode() const
{
    return m_scalingMode;
}

void AbstractViewFinder::updateCurrentFrame(const QImage &frame)
{
    {
        QMutexLocker locker(&m_frameMutex);
        m_currentFrame = frame.copy();
    }

    QMetaObject::invokeMethod(this, [this]() { update(); }, Qt::QueuedConnection);
    emit frameUpdated();
}

void AbstractViewFinder::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillRect(rect(), palette().window());

    QImage frameToPaint;
    {
        QMutexLocker locker(&m_frameMutex);
        frameToPaint = m_currentFrame;
    }

    if (frameToPaint.isNull()) {
        return;
    }

    const QRect targetRect = rect();

    switch (m_scalingMode) {
    case ScalingMode::Stretch:
        painter.drawImage(targetRect, frameToPaint);
        break;
    case ScalingMode::KeepAspectRatio: {
        const QImage scaled = frameToPaint.scaled(
            targetRect.size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        const QPoint topLeft(
            (targetRect.width() - scaled.width()) / 2,
            (targetRect.height() - scaled.height()) / 2);
        painter.drawImage(topLeft, scaled);
        break;
    }
    case ScalingMode::Fit:
    default: {
        const QImage scaled = frameToPaint.scaled(
            targetRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        const QPoint topLeft(
            (targetRect.width() - scaled.width()) / 2,
            (targetRect.height() - scaled.height()) / 2);
        painter.drawImage(topLeft, scaled);
        break;
    }
    }
}

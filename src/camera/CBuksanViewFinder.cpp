#include "CBuksanViewFinder.h"
#include "Loggerd.h"
#include <QLabel>
#include "CCameraVideoCapture.h"
#include <QString>
#include <QThread>
#include <opencv2/opencv.hpp>

CBuksanViewFinder::CBuksanViewFinder(QWidget *parent, QString strConnectionString, int nWidth, int nHeight)
    : QLabel(parent)
{
    m_pCameraVideoCapture = new CCameraVideoCapture(this);
    m_pCameraVideoCapture->mVideoCap = cv::VideoCapture(strConnectionString.toStdString(), cv::CAP_GSTREAMER);
    m_pCameraVideoCapture->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH, nWidth);
    m_pCameraVideoCapture->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT, nHeight);
    m_pCameraVideoCapture->start(QThread::HighestPriority);
    
    connect(m_pCameraVideoCapture, &CCameraVideoCapture::newPixmapCaptured, this, [&]() {
        //setPixmap(m_pCameraVideoCapture->pixmap().scaled(nWidth, nHeight));
    });
    
    this->setMinimumSize(nWidth, nHeight);
    LOG_INFO_MSG((QStringLiteral("CBuksanViewFinder: stream opened w=") + QString::number(nWidth) + QLatin1String(" h=") + QString::number(nHeight)).toStdString());
}

#include "CCameraVideoCapture.h"
#include "Loggerd.h"
#include <QString>
CCameraVideoCapture::CCameraVideoCapture(QObject *parent) : QThread(parent)
{
    LOG_TRACE_MSG("CCameraVideoCapture constructed");
}

void CCameraVideoCapture::run()
{

    Width = mVideoCap.get(cv::CAP_PROP_FRAME_WIDTH);
    Height = mVideoCap.get(cv::CAP_PROP_FRAME_HEIGHT);

    if(!mVideoCap.isOpened())
    {
        LOG_CRITICAL_MSG("Error opening camera (VideoCapture not opened)");
        return;
    }
    else
    {
        LOG_INFO_MSG("CCameraVideoCapture: capture thread running");
        while (!isInterruptionRequested()) {
            mVideoCap >> mFrame;
            if(!mFrame.empty())
            {
                mPixmap = cvMatToQPixmap(mFrame);
                emit newPixmapCaptured();
                if(isRecording) { //если идет запись то записываем кадр в видео
                    video.write(mFrame);
                }

            }

        }
        mVideoCap.release();
    }

}
QImage  CCameraVideoCapture::cvMatToQImage( const cv::Mat &inMat )
{
    switch ( inMat.type() )
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
        static QVector<QRgb>  sColorTable;

        // only create our color table once
        if ( sColorTable.isEmpty() )
        {
            for ( int i = 0; i < 256; ++i )
                sColorTable.push_back( qRgb( i, i, i ) );
        }

        QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

        image.setColorTable( sColorTable );

        return image;
    }

    default:
        LOG_INFO_MSG((QStringLiteral("cvMatToQImage: unhandled cv::Mat type ") + QString::number(inMat.type())).toStdString());
        break;
    }

    return QImage();
}

QPixmap CCameraVideoCapture::cvMatToQPixmap( const cv::Mat &inMat )
{
    return QPixmap::fromImage( cvMatToQImage( inMat ) );
}


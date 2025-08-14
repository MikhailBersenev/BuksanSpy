#include "cameravideocapture.h"
#include <QDebug>
CameraVideoCapture::CameraVideoCapture(QObject *parent) : QThread(parent)

{

}

void CameraVideoCapture::run()
{

    Width = mVideoCap.get(cv::CAP_PROP_FRAME_WIDTH);
    Height = mVideoCap.get(cv::CAP_PROP_FRAME_HEIGHT);

    if(!mVideoCap.isOpened())
    {
        qDebug() << "error openning camera";
        return;
    }
    else
    {
        while(true) {
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

    }

}
QImage  CameraVideoCapture::cvMatToQImage( const cv::Mat &inMat )
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
        qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
        break;
    }

    return QImage();
}

QPixmap CameraVideoCapture::cvMatToQPixmap( const cv::Mat &inMat )
{
    return QPixmap::fromImage( cvMatToQImage( inMat ) );
}


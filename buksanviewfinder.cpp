#include "buksanviewfinder.h"
#include <QLabel>
#include <cameravideocapture.h>
BuksanViewFinder::BuksanViewFinder(QWidget *parent,  QString ConnectionString, int Width, int Height):
QLabel(parent)
{
  CameraVideoCapture *CameraVideoCapture_var  = new CameraVideoCapture(this);
    CameraVideoCapture_var->mVideoCap = cv::VideoCapture(ConnectionString.toStdString(),
                                                        cv::CAP_GSTREAMER);
    CameraVideoCapture_var->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH,Width);
    CameraVideoCapture_var->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT,Height);
    CameraVideoCapture_var->start(QThread::HighestPriority);
    connect(CameraVideoCapture_var, &CameraVideoCapture::newPixmapCaptured, this, [&]()
    {


        //setPixmap(CameraVideoCapture_var->pixmap().scaled(Width,Height));


    } );
    this->setMinimumSize(Width,Height);
}

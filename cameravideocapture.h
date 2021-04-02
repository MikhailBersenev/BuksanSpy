#ifndef CAMERAVIDEOCAPTURE_H
#define CAMERAVIDEOCAPTURE_H
#include <QObject>
#include <QThread>
#include <QPixmap>
#include <QImage>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

class CameraVideoCapture : public QThread
{
    Q_OBJECT
public:
    explicit CameraVideoCapture(QObject *parent = nullptr);
    QPixmap pixmap() const {
        return mPixmap;

    }
    QPixmap mPixmap;
        cv::Mat mFrame;
        cv::VideoCapture mVideoCap;
        cv::VideoWriter video;
        QString name;
        QString ConnectionString;
        int Width;
        int Height;
        bool isRecording;

signals:
    void newPixmapCaptured();
protected:
    void run() override;
private:

    QImage  cvMatToQImage( const cv::Mat &inMat );
    QPixmap cvMatToQPixmap( const cv::Mat &inMat );

};

#endif // CAMERAVIDEOCAPTURE_H

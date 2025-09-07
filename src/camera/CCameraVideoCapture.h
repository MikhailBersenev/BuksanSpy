#ifndef CCAMERAVIDEOCAPTURE_H
#define CCAMERAVIDEOCAPTURE_H
#include <QObject>
#include <QThread>
#include <QPixmap>
#include <QImage>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/videoio.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>

/**
 * @brief Camera video capture and processing thread class
 * 
 * This class handles real-time video capture from surveillance cameras using OpenCV.
 * It runs in a separate thread to prevent blocking the main UI and provides
 * continuous video stream processing capabilities.
 * 
 * The class supports video recording, frame capture, and real-time video display
 * with automatic format conversion between OpenCV Mat and Qt image formats.
 */
class CCameraVideoCapture : public QThread
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the camera video capture thread
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the video capture system and prepares OpenCV
     * components for camera operations.
     */
    explicit CCameraVideoCapture(QObject *parent = nullptr);
    
    /**
     * @brief Returns the current captured video frame as a QPixmap
     * @return QPixmap containing the latest video frame
     * 
     * Provides access to the most recently captured video frame
     * for display in the user interface.
     */
    QPixmap pixmap() const {
        return mPixmap;
    }
    
    /** @brief Current video frame as a QPixmap for display */
    QPixmap mPixmap;
    
    /** @brief Current video frame as an OpenCV Mat for processing */
    cv::Mat mFrame;
    
    /** @brief OpenCV video capture object for camera input */
    cv::VideoCapture mVideoCap;
    
    /** @brief OpenCV video writer for recording functionality */
    cv::VideoWriter video;
    
    /** @brief Camera name or identifier */
    QString name;
    
    /** @brief Camera connection string or URL */
    QString ConnectionString;
    
    /** @brief Video frame width in pixels */
    int Width;
    
    /** @brief Video frame height in pixels */
    int Height;
    
    /** @brief Flag indicating if video recording is currently active */
    bool isRecording;

signals:
    /**
     * @brief Signal emitted when a new video frame is captured
     * 
     * Notifies connected objects that a new video frame is available
     * for processing or display.
     */
    void newPixmapCaptured();

protected:
    /**
     * @brief Main thread execution function
     * 
     * Continuously captures video frames from the camera, processes them,
     * and emits signals when new frames are available. This method runs
     * in a separate thread to prevent UI blocking.
     */
    void run() override;

private:
    /**
     * @brief Converts OpenCV Mat to QImage format
     * @param inMat Input OpenCV Mat image
     * @return QImage representation of the input Mat
     * 
     * Performs format conversion for display and processing purposes.
     */
    QImage cvMatToQImage(const cv::Mat &inMat);
    
    /**
     * @brief Converts OpenCV Mat to QPixmap format
     * @param inMat Input OpenCV Mat image
     * @return QPixmap representation of the input Mat
     * 
     * Performs format conversion for display purposes in Qt widgets.
     */
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);

};

#endif // CCAMERAVIDEOCAPTURE_H

#ifndef BUKSANVIEWFINDER_H
#define BUKSANVIEWFINDER_H
#include "cameravideocapture.h"
#include <QObject>
#include <QWidget>
#include <QLabel>
class BuksanViewFinder : public QLabel
{
    Q_OBJECT
public:
    BuksanViewFinder(QWidget *parent, QString ConnectionString, int Width, int Height);
private:
CameraVideoCapture *CameraVideoCapture_var;




};

#endif // BUKSANVIEWFINDER_H
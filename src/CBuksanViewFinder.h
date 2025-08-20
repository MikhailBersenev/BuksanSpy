#ifndef CBUKSANVIEWFINDER_H
#define CBUKSANVIEWFINDER_H
#include "CCameraVideoCapture.h"
#include <QObject>
#include <QWidget>
#include <QLabel>

class CBuksanViewFinder : public QLabel
{
    Q_OBJECT
public:
    CBuksanViewFinder(QWidget *parent, QString strConnectionString, int nWidth, int nHeight);

private:
    CCameraVideoCapture *m_pCameraVideoCapture;
};

#endif // CBUKSANVIEWFINDER_H

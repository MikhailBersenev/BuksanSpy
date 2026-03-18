#include "CCamera.h"
#include "Loggerd.h"

CCamera::CCamera(QObject *parent)
    : CSecLabeledObject{parent}
{
    LOG_TRACE_MSG("CCamera constructed");
}

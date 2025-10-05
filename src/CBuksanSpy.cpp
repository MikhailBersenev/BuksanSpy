#include "CBuksanSpy.h"
#include "ui_CBuksanSpy.h"
#include "security/CCreateUser.h"
#include <QtWidgets>
#include <QMenuBar>
#include "ui/CAddDevice.h"
#include "utils/CNetworkInfo.h"
#include "ui/CDevices.h"
#include "ui/CEventLog.h"
#include "security/CUsers.h"
#include "utils/CCheckConnection.h"
#include <opencv2/opencv.hpp>
#include "camera/CBuksanViewFinder.h"

CBuksanSpy::CBuksanSpy(QWidget *parent)
    : QMainWindow(parent)
    , m_pUi(new Ui::CBuksanSpy)
{
    m_pUi->setupUi(this);
    m_pUi->pushButton_2->addAction(m_pUi->Quit_Action);
    m_pUi->pushButton_2->addAction(m_pUi->action_Qt);
}

CBuksanSpy::~CBuksanSpy()
{
    delete m_pUi;
}

void CBuksanSpy::fSetTitle()
{
    CNetworkInfo l_ip;
    m_pAccessManager = new CAccessManager(this);
    //Назначение заголовка окна
    setWindowTitle(l_ip.fGetIPAddress()+" "+"User: "+m_strUsername+"("+m_pAccessManager->fGetMandatoryGroup(m_strUsername)+") - BuksanSpy");
    delete m_pAccessManager;
}

void CBuksanSpy::on_Quit_Action_triggered()
{
    QApplication::quit();
}

void CBuksanSpy::on_pushButton_2_clicked()
{
    m_pFinder = new CBuksanViewFinder(this, "tcpclientsrc host=127.0.0.1 port=5000 ! gdpdepay ! appsink",640,480);
    m_pFinder->setObjectName("cam");
    m_pFinder->show();
}

void CBuksanSpy::fStartCap()
{
    
}

bool CBuksanSpy::fCheckRights(int nRight)
{
    m_pAccessManager = new CAccessManager(this);
    if(!m_pAccessManager->fCheckRight(m_strUsername, nRight)) {
        QMessageBox::warning(this, "Warning!", "You do not have sufficient rights to access this section.");
        return false;
    }
    else
    {
        return true;
    }
}

void CBuksanSpy::on_pushButton_4_clicked()
{
    QSqlQuery l_devices;
    l_devices.prepare("SELECT devices.\"connectionString\", devices.resolution, devices.transform, resolutions.width, resolutions.height FROM devices INNER JOIN resolutions ON devices.resolution = resolutions.\"resolutionId\";");
    if(!l_devices.exec())
    {
        qDebug() << "Unable to initialize devices" << l_devices.lastError() << l_devices.lastQuery();
        return;
    }
    // l_devices.first();
    while (l_devices.next()) {
        m_pCamRotate = new QTransform;
        m_pCameraVideoCapture = new CCameraVideoCapture(this);
        m_pCameraVideoCapture->isRecording = false;
        switch (l_devices.value(1).toInt()) {
        case 1:
            m_pCameraVideoCapture->mVideoCap = cv::VideoCapture(l_devices.value(0).toInt(), cv::CAP_V4L2);
            break;
        case 2:
            m_pCameraVideoCapture->mVideoCap = cv::VideoCapture(l_devices.value(0).toString().toStdString(), cv::CAP_V4L2);
            break;
        }
        m_pCameraVideoCapture->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH, l_devices.value(2).toInt());
        m_pCameraVideoCapture->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT, l_devices.value(3).toInt());
        m_pCamRotate->rotate(l_devices.value(2).toDouble());
        m_pCameraViewLabel = new QLabel;
        m_pUi->camslay->addWidget(m_pCameraViewLabel);
        m_pCameraViewLabel->show();
        m_pCameraVideoCapture->start(QThread::HighestPriority);
        connect(m_pCameraVideoCapture, &CCameraVideoCapture::newPixmapCaptured, this, [&]()
        {
            m_pCameraViewLabel->setPixmap(m_pCameraVideoCapture->pixmap().scaled(m_pCameraVideoCapture->Width,m_pCameraVideoCapture->Height).transformed(*m_pCamRotate));
        } );
        m_pCameraViewLabel->setMinimumSize(l_devices.value(3).toInt(), l_devices.value(4).toInt());
    }
}

void CBuksanSpy::on_users_Action_triggered()
{
    if(fCheckRights(0))
    {
        m_pUsers = new CUsers(this, m_strUsername);
        m_pUsers->setModal(true);
        m_pUsers->exec();
        delete m_pUsers;
    }
}

void CBuksanSpy::on_MandatoryGroups_Action_triggered()
{
    if(fCheckRights(0))
    {
        m_pRights = new CMandatoryGroups(this, m_strUsername);
        m_pRights->exec();
        delete m_pRights;
    }
}

void CBuksanSpy::on_pushButton_3_clicked()
{
    QSqlQuery l_role;
    QString l_strName;
    l_strName = "astratest";
    l_role.exec("CREATE ROLE \""+l_strName+"\" LOGIN PASSWORD '123456' CREATEDB  VALID UNTIL 'infinity';");
}

void CBuksanSpy::on_InitCams_action_triggered()
{
    QSqlQuery l_devices;
    l_devices.prepare("SELECT devices.\"connectionString\", devices.resolution, devices.transform, resolutions.width, resolutions.height FROM devices INNER JOIN resolutions ON devices.resolution = resolutions.\"resolutionId\";");
    if(!l_devices.exec())
    {
        qDebug() << "Unable to initialize devices" << l_devices.lastError() << l_devices.lastQuery();
        return;
    }
    l_devices.first();
    while (l_devices.next()) {
        m_pCamRotate = new QTransform;
        m_pCameraVideoCapture = new CCameraVideoCapture(this);
        m_pCameraVideoCapture->isRecording = false;
        m_pCameraVideoCapture->mVideoCap = cv::VideoCapture(l_devices.value(0).toInt(),cv::CAP_V4L2);
        m_pCameraVideoCapture->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH, l_devices.value(2).toInt());
        m_pCameraVideoCapture->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT, l_devices.value(3).toInt());
        m_pCamRotate->rotate(l_devices.value(2).toDouble());
        m_pCameraViewLabel = new QLabel(m_pUi->AllCams);
        m_pCameraViewLabel->show();
        m_pCameraVideoCapture->start(QThread::HighestPriority);
        connect(m_pCameraVideoCapture, &CCameraVideoCapture::newPixmapCaptured, this, [&]()
        {
            m_pCameraViewLabel->setPixmap(m_pCameraVideoCapture->pixmap().scaled(m_pCameraVideoCapture->Width,m_pCameraVideoCapture->Height).transformed(*m_pCamRotate));
        } );
        m_pCameraViewLabel->setMinimumSize(m_pCameraVideoCapture->Width,m_pCameraVideoCapture->Height);
    }
}

void CBuksanSpy::on_AddDev_Action_triggered()
{
    if(!fCheckRights(1)) //проверка прав доступа
    {
        return;
    }
    else
    {
        CAddDevice l_dev;
        l_dev.setModal(true);
        l_dev.exec(); //показываем форму
    }
}

void CBuksanSpy::on_ShowDevList_Action_triggered()
{
    CDevices l_devlist;
    l_devlist.setModal(true);
    l_devlist.exec();
}

void CBuksanSpy::on_eventlog_Action_triggered()
{
    //Показать форму журнала событий
    CEventLog l_log;
    l_log.setModal(true);
    l_log.exec();
}

void CBuksanSpy::fUpdateModels()
{
    qDebug() << "new event";
}

void CBuksanSpy::fSubscribe()
{/*
    CDatabaseConnection l_postgresConnection;
    l_postgresConnection.db.driver()->subscribeToNotification("delete_alerts_notf");
    l_postgresConnection.db.driver()->subscribeToNotification("insert_alerts_notf");
    connect(l_postgresConnection.db.driver(), SIGNAL(notification(QString)), this, SLOT(fUpdateModels()));*/
}

void CBuksanSpy::on_action_Qt_triggered()
{
    //Показать оконо About Qt
    QMessageBox::aboutQt(this, "BuksanSpy uses Qt");
}

#include "buksanspy.h"
#include "ui_buksanspy.h"
#include "createuser.h"
#include <QtWidgets>
#include <QMenuBar>
#include "adddevice.h"
#include "devices.h"
#include "eventlog.h"
BuksanSpy::BuksanSpy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BuksanSpy)
{
    ui->setupUi(this);
    
    
    
    
}

BuksanSpy::~BuksanSpy()
{
    delete ui;
}





void BuksanSpy::on_Quit_Action_triggered()
{
    QApplication::quit();
}

void BuksanSpy::on_pushButton_2_clicked()
{
    QTransform CamRotate;
    m_cam = new CameraVideoCapture(this);
    m_cam->isRecording = false;
    m_cam->ConnectionString = "0";
    m_cam->mVideoCap =cv::VideoCapture(0);
    m_cam->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH,640);
    m_cam->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT,480);
    m_cam->name = "hello.avi";
    m_cam->start(QThread::HighestPriority);
    
    test = new QLabel(ui->AllCams);
    // test = new QLabel;
    //ui->Cams_TabWidget->addTab(test, "test");
    test->setObjectName("CAM");
    trans.rotate(180);
    QLabel* label = new QLabel(test);
    label->setText("<h2 style=\"color:red\">Камера 1 (Улица)</h2>");
    
    // test->setLayout(ui->AllTab_Layout);
    test->show();
    connect(m_cam, &CameraVideoCapture::newPixmapCaptured, this, [&]()
    {
        
        
        test->setPixmap(m_cam->pixmap().scaled(m_cam->Width,m_cam->Height).transformed(trans));
        
        
    } );
    test->setMinimumSize(m_cam->Width,m_cam->Height);
    /* AccessManager_var = new AccessManager(this);
    if (!AccessManager_var->checkright("adminwwe", 0)) {
        QMessageBox::critical(this, "warning", "warning");
    }*/
    
}

void BuksanSpy::StartCap()
{
    
}

bool BuksanSpy::CheckRights(int right)
{
    AccessManager_var = new AccessManager(this);
    if(!AccessManager_var->checkright(username, right)) {
        QMessageBox::warning(this, "Внимание!", "У вас недостаточно прав для доступа к этому разделу");
        return false;
    }
    else
    {
        return true;
    }
}





void BuksanSpy::on_pushButton_4_clicked()
{
    QSqlQuery devices;
    devices.prepare("SELECT devices.\"connectionString\", devices.resolution, devices.transform, resolutions.width, resolutions.height FROM devices INNER JOIN resolutions ON devices.resolution = resolutions.\"resolutionId\";");
    if(!devices.exec())
    {
        qDebug() << "Unable to initialize devices" << devices.lastError() << devices.lastQuery();
        return;
    }
    // devices.first();
    while (devices.next()) {
        CamRotate = new QTransform;
        CameraVideoCapture_var = new CameraVideoCapture(this);
        CameraVideoCapture_var->isRecording = false;
        switch (devices.value(1).toInt()) {
        case 1:
            CameraVideoCapture_var->mVideoCap = cv::VideoCapture(devices.value(0).toInt());
            break;
        case 2:
            CameraVideoCapture_var->mVideoCap = cv::VideoCapture(devices.value(0).toString().toStdString());
            break;

        }
        CameraVideoCapture_var->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH, devices.value(2).toInt());
        CameraVideoCapture_var->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT, devices.value(3).toInt());
        CamRotate->rotate(devices.value(2).toDouble());
        CameraView_Label = new QLabel;
        ui->camslay->addWidget(CameraView_Label);
        //CameraView_Label->setObjectName(camc.toString())
        CameraView_Label->show();
        CameraVideoCapture_var->start(QThread::HighestPriority);
        connect(CameraVideoCapture_var, &CameraVideoCapture::newPixmapCaptured, this, [&]()
        {


            CameraView_Label->setPixmap(CameraVideoCapture_var->pixmap().scaled(CameraVideoCapture_var->Width,CameraVideoCapture_var->Height).transformed(*CamRotate));


        } );
        CameraView_Label->setMinimumSize(devices.value(3).toInt(), devices.value(4).toInt());


    }

}




void BuksanSpy::on_users_Action_triggered()
{
    if(CheckRights(0))
    {
        Users_var = new Users(this);
        
        Users_var->exec();
        delete Users_var;
    }
    
}

void BuksanSpy::on_MandatoryGroups_Action_triggered()
{
    if(CheckRights(0))
    {
        rights = new MandatoryGroups(this);
        rights->username = username;
        rights->exec();
        delete rights;
    }
}



void BuksanSpy::on_pushButton_3_clicked()
{
    //QMessageBox::information(this, "Добро пожаловать!, mikhail!", "Вы являетесь членом группы buksan-admin");
}




void BuksanSpy::on_InitCams_action_triggered()
{
    QSqlQuery devices;
    devices.prepare("SELECT devices.\"connectionString\", devices.resolution, devices.transform, resolutions.width, resolutions.height FROM devices INNER JOIN resolutions ON devices.resolution = resolutions.\"resolutionId\";");
    if(!devices.exec())
    {
        qDebug() << "Unable to initialize devices" << devices.lastError() << devices.lastQuery();
        return;
    }
    devices.first();
    while (devices.next()) {
        CamRotate = new QTransform;
        CameraVideoCapture_var = new CameraVideoCapture(this);
        CameraVideoCapture_var->isRecording = false;
        CameraVideoCapture_var->mVideoCap = cv::VideoCapture(devices.value(0).toInt());
        CameraVideoCapture_var->mVideoCap.set(cv::CAP_PROP_FRAME_WIDTH, devices.value(2).toInt());
        CameraVideoCapture_var->mVideoCap.set(cv::CAP_PROP_FRAME_HEIGHT, devices.value(3).toInt());
        CamRotate->rotate(devices.value(2).toDouble());
        CameraView_Label = new QLabel(ui->AllCams);
        CameraView_Label->show();
        CameraVideoCapture_var->start(QThread::HighestPriority);
        connect(CameraVideoCapture_var, &CameraVideoCapture::newPixmapCaptured, this, [&]()
        {


            CameraView_Label->setPixmap(CameraVideoCapture_var->pixmap().scaled(CameraVideoCapture_var->Width,CameraVideoCapture_var->Height).transformed(*CamRotate));


        } );
        CameraView_Label->setMinimumSize(m_cam->Width,m_cam->Height);


    }

}

void BuksanSpy::on_AddDev_Action_triggered()
{
if(!CheckRights(1)) //проверка прав доступа
{
    return;
}
else
{
    AddDevice dev;
    dev.setModal(true);
    dev.exec(); //показываем форму
}
}

void BuksanSpy::on_ShowDevList_Action_triggered()
{
 Devices devlist;
 devlist.setModal(true);
 devlist.exec();
}







void BuksanSpy::on_eventlog_Action_triggered()
{
    //Показать форму журнала событий
    eventlog log;
    log.setModal(true);
    log.exec();
}

#ifndef BUKSANSPY_H
#define BUKSANSPY_H
#include <QMainWindow>
#include <QtSql>
#include "accessmanager.h"
#include "users.h"
#include "mandatorygroups.h"
#include "checkconnection.h"
#include <QtWidgets>
#include <cameravideocapture.h>
QT_BEGIN_NAMESPACE
namespace Ui { class BuksanSpy; }
QT_END_NAMESPACE
class CameraVideoCapture;
class BuksanSpy : public QMainWindow
{
    Q_OBJECT

public:
    BuksanSpy(QWidget *parent = nullptr);
    ~BuksanSpy();
    QString username;
    QTransform trans;
    void SetTitle();
    int camc;


private slots:


    void on_Quit_Action_triggered();

    void on_pushButton_2_clicked();






    void on_pushButton_4_clicked();

    void on_users_Action_triggered();

    void on_MandatoryGroups_Action_triggered();
    void on_pushButton_3_clicked();

    void on_InitCams_action_triggered();

    void on_AddDev_Action_triggered();

    void on_ShowDevList_Action_triggered();




    void on_eventlog_Action_triggered();
    void UpdateModels();
    void Subscribe();

    void on_action_Qt_triggered();

private:
    Ui::BuksanSpy *ui;
    CameraVideoCapture *m_cam;
    void StartCap();
    QLabel *test;
    AccessManager *AccessManager_var;
    bool CheckRights(int right);
    MandatoryGroups *rights;
    Users *users_var;
    QTransform *CamRotate;
    QLabel *CameraView_Label;
    CameraVideoCapture *CameraVideoCapture_var;


    

};
#endif // BUKSANSPY_H

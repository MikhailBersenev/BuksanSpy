#ifndef CBUKSANSPY_H
#define CBUKSANSPY_H
#include <QMainWindow>
#include <QtSql>
#include "CAccessManager.h"
#include "CUsers.h"
#include "CMandatoryGroups.h"
#include "CCheckConnection.h"
#include <QtWidgets>
#include "CBuksanViewFinder.h"
#include <CCameraVideoCapture.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CBuksanSpy; }
QT_END_NAMESPACE

class CCameraVideoCapture;
class CBuksanSpy : public QMainWindow
{
    Q_OBJECT

public:
    CBuksanSpy(QWidget *parent = nullptr);
    ~CBuksanSpy();
    QString m_strUsername;
    QTransform m_trans;
    void fSetTitle();
    int m_nCamc;

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
    void fUpdateModels();
    void fSubscribe();
    void on_action_Qt_triggered();

private:
    Ui::CBuksanSpy *m_pUi;
    CCameraVideoCapture *m_pCam;
    void fStartCap();
    QLabel *m_pTest;
    CAccessManager *m_pAccessManager;
    bool fCheckRights(int nRight);
    CMandatoryGroups *m_pRights;
    CUsers *m_pUsers;
    QTransform *m_pCamRotate;
    QLabel *m_pCameraViewLabel;
    CCameraVideoCapture *m_pCameraVideoCapture;
    CBuksanViewFinder *m_pFinder;
};
#endif // CBUKSANSPY_H

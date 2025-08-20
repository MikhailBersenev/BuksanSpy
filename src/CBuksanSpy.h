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

/**
 * @brief Main application window class for BuksanSpy surveillance system
 * 
 * This class represents the main application window that provides access to all
 * major system functions including camera management, user administration,
 * mandatory access control, and system monitoring.
 * 
 * The class inherits from QMainWindow and provides a comprehensive interface
 * for managing surveillance cameras, user permissions, and system configuration.
 */
class CBuksanSpy : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the main application window
     * @param parent Parent widget (default: nullptr)
     * 
     * Initializes the main window, sets up the user interface,
     * and prepares the application for use.
     */
    CBuksanSpy(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor for the main application window
     * 
     * Cleans up resources and ensures proper application shutdown.
     */
    ~CBuksanSpy();
    
    /** @brief Current authenticated username */
    QString m_strUsername;
    
    /** @brief Transformation matrix for camera view adjustments */
    QTransform m_trans;
    
    /**
     * @brief Sets the window title with user and system information
     * 
     * Updates the main window title to display current user,
     * mandatory access level, and system identification.
     */
    void fSetTitle();
    
    /** @brief Camera counter for tracking active cameras */
    int m_nCamc;

private slots:
    /**
     * @brief Handles quit action trigger
     * 
     * Terminates the application when the quit action is activated.
     */
    void on_Quit_Action_triggered();
    
    /**
     * @brief Handles camera view finder button click
     * 
     * Opens the camera view finder window for video stream display.
     */
    void on_pushButton_2_clicked();
    
    /**
     * @brief Handles camera initialization button click
     * 
     * Initializes and starts all configured surveillance cameras.
     */
    void on_pushButton_4_clicked();
    
    /**
     * @brief Handles users management action trigger
     * 
     * Opens the user management interface for system administration.
     */
    void on_users_Action_triggered();
    
    /**
     * @brief Handles mandatory groups action trigger
     * 
     * Opens the mandatory access control groups management interface.
     */
    void on_MandatoryGroups_Action_triggered();
    
    /**
     * @brief Handles device management button click
     * 
     * Opens the device management interface for camera configuration.
     */
    void on_pushButton_3_clicked();
    
    /**
     * @brief Handles camera initialization action trigger
     * 
     * Initializes the camera system and prepares video streams.
     */
    void on_InitCams_action_triggered();
    
    /**
     * @brief Handles add device action trigger
     * 
     * Opens the interface for adding new surveillance devices.
     */
    void on_AddDev_Action_triggered();
    
    /**
     * @brief Handles show device list action trigger
     * 
     * Displays the list of all configured surveillance devices.
     */
    void on_ShowDevList_Action_triggered();
    
    /**
     * @brief Handles event log action trigger
     * 
     * Opens the system event log for monitoring and auditing.
     */
    void on_eventlog_Action_triggered();
    
    /**
     * @brief Updates all data models in the application
     * 
     * Refreshes the data displayed in various views and tables.
     */
    void fUpdateModels();
    
    /**
     * @brief Subscribes to system notifications and updates
     * 
     * Establishes connections to receive real-time system updates.
     */
    void fSubscribe();
    
    /**
     * @brief Handles Qt information action trigger
     * 
     * Displays information about the Qt framework version and licensing.
     */
    void on_action_Qt_triggered();

private:
    /** @brief User interface object for the main window */
    Ui::CBuksanSpy *m_pUi;
    
    /** @brief Camera video capture object for video processing */
    CCameraVideoCapture *m_pCam;
    
    /**
     * @brief Starts video capture from surveillance cameras
     * 
     * Initializes and begins recording from all active cameras.
     */
    void fStartCap();
    
    /** @brief Test label for development and debugging purposes */
    QLabel *m_pTest;
    
    /** @brief Access manager for handling user permissions and rights */
    CAccessManager *m_pAccessManager;
    
    /**
     * @brief Checks if the current user has the specified right
     * @param nRight The right identifier to check
     * @return true if the user has the right, false otherwise
     * 
     * Verifies user permissions before allowing access to restricted functions.
     */
    bool fCheckRights(int nRight);
    
    /** @brief Mandatory access control groups manager */
    CMandatoryGroups *m_pRights;
    
    /** @brief User management interface */
    CUsers *m_pUsers;
    
    /** @brief Transform matrix for camera view adjustments */
    QTransform *m_pCamRotate;
    
    /** @brief Label widget for displaying camera video feed */
    QLabel *m_pCameraViewLabel;
    
    /** @brief Camera video capture object for individual camera streams */
    CCameraVideoCapture *m_pCameraVideoCapture;
    
    /** @brief Camera view finder window for video display */
    CBuksanViewFinder *m_pFinder;
};
#endif // CBUKSANSPY_H

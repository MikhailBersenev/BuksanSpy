#ifndef CNETWORKINFO_H
#define CNETWORKINFO_H
#include <QObject>
#include <QTimer>

/**
 * @brief Network information and configuration manager
 * 
 * This class provides network-related functionality for the BuksanSpy system,
 * including IP address detection, network interface monitoring, and
 * network configuration management. It helps identify the system's
 * network identity for logging and communication purposes.
 * 
 * The class automatically detects the primary network interface and
 * provides real-time network information to other system components.
 */
class CNetworkInfo : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the network information manager
     * @param parent Parent object (default: nullptr)
     * 
     * Initializes the network monitoring system and prepares
     * network interface detection.
     */
    explicit CNetworkInfo(QObject *parent = nullptr);
    
    /**
     * @brief Retrieves the primary IP address of the system
     * @return The primary IP address as a string
     * 
     * Automatically detects and returns the main network interface
     * IP address, excluding localhost and loopback addresses.
     * This is typically used for system identification and logging.
     */
    QString fGetIPAddress();

signals:

};

#endif // CNETWORKINFO_H

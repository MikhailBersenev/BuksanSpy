# BuksanSpy Client

A comprehensive Qt-based surveillance system with integrated camera management, user authentication, mandatory access control, and event logging capabilities.

## Features

### 🎥 Camera Management
- Real-time video capture from multiple surveillance cameras
- Camera initialization and configuration
- Live video stream viewing through viewfinder interface
- Integration with OpenCV for video processing

### 🔐 Security & Authentication
- User authentication and authorization system
- Mandatory Access Control (MAC) implementation
- Role-based access control (RBAC)
- User account management (create, edit, delete, ban/unban accounts)
- Password management and security groups
- Session management with automatic reconnection

### 📊 Event System
- Comprehensive event logging and monitoring
- Support for multiple event types:
  - **Security Events**: User authentication, password changes, account modifications
  - **Server Events**: Connection status, network monitoring
  - **System Events**: General system notifications
- SQL-based event engine for persistent event storage

### 📱 User Interface
- Modern Qt-based graphical user interface
- Device management interface
- Mandatory groups and marks editor
- Event log viewer
- User management interface

### 🗄️ Database Integration
- PostgreSQL database support
- Encrypted database connections
- Connection management and monitoring
- Automatic session restoration

### 🔧 System Monitoring
- Network connection status checking
- Internet connectivity monitoring
- System alerts and notifications
- Connection recovery handling

## Technology Stack

- **Framework**: Qt 6 (C++17)
- **Modules Used**:
  - Qt Core, GUI, Widgets
  - Qt SQL (database connectivity)
  - Qt Multimedia (video/audio support)
  - Qt Network (network operations)
- **Libraries**:
  - OpenCV 4 (computer vision and video processing)
- **Database**: PostgreSQL
- **Build System**: qmake

## Requirements

### Build Dependencies
- Qt 6.x or later
- Qt5 compatibility layer disabled (`QT_DISABLE_DEPRECATED_BEFORE=0x060000`)
- OpenCV 4.x
- PostgreSQL development libraries
- C++17 compatible compiler

### Runtime Dependencies
- Qt 6 runtime libraries
- OpenCV runtime libraries
- PostgreSQL client libraries
- X11 (on Linux) or Windows GUI libraries

## Building

1. **Install dependencies**:
   ```bash
   # On Arch Linux / CachyOS (example)
   sudo pacman -S qt6-base qt6-multimedia opencv postgresql-libs
   ```

2. **Configure and build**:
   ```bash
   qmake BuksanSpy.pro
   make
   ```

3. **Run the application**:
   ```bash
   ./BuksanSpy
   ```

## Configuration

### Database Setup
The application requires a PostgreSQL database. Configure connection settings through the authorization dialog:
- Host name
- Database name
- Port
- Username
- Password

### Session Management
The application supports automatic session restoration:
- Sessions are stored locally for up to 3 days
- Automatic reconnection to the last valid session
- Secure credential storage

```

## Authors

- **Mikhail Bersenev** - Initial development

## Acknowledgments

- Built with Qt Framework
- Video processing powered by OpenCV
- Database support via PostgreSQL

#include "CAboutWindow.h"

#include <QApplication>
#include <QDateTime>
#include <QGuiApplication>
#include <QLabel>
#include <QLocale>
#include <QPushButton>
#include <QStyle>
#include <QSysInfo>
#include <QVBoxLayout>

#include "utils/CStringUtils.h"

CAboutWindow::CAboutWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("About %1").arg(CStringUtils::GetAppName()));
    setWindowFlag(Qt::Window, true);
    setMinimumWidth(420);

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(16, 16, 16, 16);
    mainLayout->setSpacing(10);

    auto *iconLabel = new QLabel(this);
    QIcon appIcon = windowIcon().isNull() ? qApp->windowIcon() : windowIcon();
    if (appIcon.isNull()) {
        appIcon = style()->standardIcon(QStyle::SP_ComputerIcon);
    }
    iconLabel->setPixmap(appIcon.pixmap(64, 64));
    iconLabel->setAlignment(Qt::AlignHCenter);

    auto *nameLabel = new QLabel(CStringUtils::GetAppName(), this);
    QFont nameFont = nameLabel->font();
    nameFont.setPointSize(nameFont.pointSize() + 3);
    nameFont.setBold(true);
    nameLabel->setFont(nameFont);
    nameLabel->setAlignment(Qt::AlignHCenter);

    auto *versionLabel = new QLabel(tr("Version: %1").arg(CStringUtils::GetAppVersion()), this);
    versionLabel->setAlignment(Qt::AlignHCenter);

    auto *copyrightLabel = new QLabel(CStringUtils::GetAppCopyright(), this);
    copyrightLabel->setWordWrap(true);
    copyrightLabel->setAlignment(Qt::AlignHCenter);

    const QString osInfo = tr("OS: %1 (%2)")
                               .arg(QSysInfo::prettyProductName(), QSysInfo::currentCpuArchitecture());
    auto *osLabel = new QLabel(osInfo, this);

    const QString qtInfo = tr("Qt: %1").arg(qVersion());
    auto *qtLabel = new QLabel(qtInfo, this);

    const QString dateTimeInfo = tr("Current date/time: %1")
                                     .arg(QLocale().toString(QDateTime::currentDateTime(), QLocale::LongFormat));
    auto *dateTimeLabel = new QLabel(dateTimeInfo, this);

    auto *closeButton = new QPushButton(tr("Close"), this);
    closeButton->setDefault(true);
    closeButton->setAutoDefault(true);

    connect(closeButton, &QPushButton::clicked, this, &QWidget::close);

    mainLayout->addWidget(iconLabel);
    mainLayout->addWidget(nameLabel);
    mainLayout->addWidget(versionLabel);
    mainLayout->addWidget(copyrightLabel);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(osLabel);
    mainLayout->addWidget(qtLabel);
    mainLayout->addWidget(dateTimeLabel);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(closeButton, 0, Qt::AlignRight);
}

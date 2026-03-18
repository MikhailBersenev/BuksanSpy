#include "AppLogging.h"
#include "Loggerd.h"
#include "MessageHandler.h"
#include "TxtMessageHandler.h"

#include <QDir>
#include <QStandardPaths>
#include <memory>
#include <string>
#include <QDateTime>

namespace {
MessageHandler s_consoleHandler;
std::unique_ptr<TxtMessageHandler> s_fileHandler;
}  // namespace

void fInitAppLogging()
{
    Loggerd* const log = Loggerd::getInstance();
    log->addMessageHandler(&s_consoleHandler);

    const QString sDir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/BuksanSpyLogs";
    const QString sDateTime = QDateTime::currentDateTime().toString();
    QDir().mkpath(sDir);
    const QString path = sDir + QStringLiteral("/BuksanSpy-log-%1.txt").arg(sDateTime);
    s_fileHandler = std::make_unique<TxtMessageHandler>(path.toStdString());
    log->addMessageHandler(s_fileHandler.get());

    LOG_INFO_MSG(std::string("BuksanSpy logging started, file: ") + path.toStdString());
}

#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <QDialog>

namespace Ui {
class eventlog;
}

class eventlog : public QDialog
{
    Q_OBJECT

public:
    explicit eventlog(QWidget *parent = nullptr);
    ~eventlog();

private:
    Ui::eventlog *ui;
};

#endif // EVENTLOG_H

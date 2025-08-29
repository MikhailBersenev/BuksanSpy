#ifndef CDEVICES_H
#define CDEVICES_H

#include <QDialog>
#include <QtSql>
#include <QtWidgets>
#include "camera/CCameraVideoCapture.h"
#include <QLabel>
#include <QBoxLayout>

namespace Ui {
class CDevices;
}

class CDevices : public QDialog
{
    Q_OBJECT

public:
    explicit CDevices(QWidget *parent = nullptr);
    ~CDevices();

private slots:
    void on_AddDevice_Button_clicked();
    void on_DeleteDevice_Button_clicked();

private:
    Ui::CDevices *m_pUi;
    QSqlQuery *m_pDevQuery;
    QLabel *m_pDevPicLabel;
    QLabel *m_pDevTypeLabel;
    QLabel *m_pDevTitleLabel;
    QBoxLayout *m_pDevDescLayout;
    int m_nIc;
};

#endif // CDEVICES_H

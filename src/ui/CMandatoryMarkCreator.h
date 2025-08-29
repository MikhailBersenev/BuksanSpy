#ifndef CMANDATORYMARKCREATOR_H
#define CMANDATORYMARKCREATOR_H

#include <QDialog>

namespace Ui {
class CMandatoryMarkCreator;
}

class CMandatoryMarkCreator : public QDialog
{
    Q_OBJECT

public:
    explicit CMandatoryMarkCreator(QWidget *parent = nullptr);
    ~CMandatoryMarkCreator();

private slots:
    void on_buttonBox_accepted();

    void on_accesslevel_Slider_sliderMoved(int position);

private:
    Ui::CMandatoryMarkCreator *m_pUi;
};

#endif // CMANDATORYMARKCREATOR_H

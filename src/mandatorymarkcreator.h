#ifndef MANDATORYMARKCREATOR_H
#define MANDATORYMARKCREATOR_H

#include <QDialog>

namespace Ui {
class MandatoryMarkCreator;
}

class MandatoryMarkCreator : public QDialog
{
    Q_OBJECT

public:
    explicit MandatoryMarkCreator(QWidget *parent = nullptr);
    ~MandatoryMarkCreator();

private slots:
    void on_buttonBox_accepted();

    void on_accesslevel_Slider_sliderMoved(int position);

private:
    Ui::MandatoryMarkCreator *ui;
};

#endif // MANDATORYMARKCREATOR_H

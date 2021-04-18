/********************************************************************************
** Form generated from reading UI file 'adddevice.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICE_H
#define UI_ADDDEVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDevice
{
public:
    QFormLayout *formLayout;
    QLabel *DeviceType_Label;
    QLabel *SelectDevice_Label;
    QVBoxLayout *SelectDevice_Layout;
    QLabel *Resolution_Label;
    QDialogButtonBox *buttonBox;
    QComboBox *DevType_ComboBox;
    QComboBox *Resolution_ComboBox;
    QComboBox *Transform_ComboBox;
    QLabel *Transform_Label;
    QLineEdit *Caption_Edit;
    QLabel *Caption_Label;

    void setupUi(QDialog *AddDevice)
    {
        if (AddDevice->objectName().isEmpty())
            AddDevice->setObjectName(QString::fromUtf8("AddDevice"));
        AddDevice->resize(350, 180);
        formLayout = new QFormLayout(AddDevice);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        DeviceType_Label = new QLabel(AddDevice);
        DeviceType_Label->setObjectName(QString::fromUtf8("DeviceType_Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, DeviceType_Label);

        SelectDevice_Label = new QLabel(AddDevice);
        SelectDevice_Label->setObjectName(QString::fromUtf8("SelectDevice_Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, SelectDevice_Label);

        SelectDevice_Layout = new QVBoxLayout();
        SelectDevice_Layout->setObjectName(QString::fromUtf8("SelectDevice_Layout"));

        formLayout->setLayout(1, QFormLayout::FieldRole, SelectDevice_Layout);

        Resolution_Label = new QLabel(AddDevice);
        Resolution_Label->setObjectName(QString::fromUtf8("Resolution_Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Resolution_Label);

        buttonBox = new QDialogButtonBox(AddDevice);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::FieldRole, buttonBox);

        DevType_ComboBox = new QComboBox(AddDevice);
        DevType_ComboBox->setObjectName(QString::fromUtf8("DevType_ComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, DevType_ComboBox);

        Resolution_ComboBox = new QComboBox(AddDevice);
        Resolution_ComboBox->setObjectName(QString::fromUtf8("Resolution_ComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Resolution_ComboBox);

        Transform_ComboBox = new QComboBox(AddDevice);
        Transform_ComboBox->setObjectName(QString::fromUtf8("Transform_ComboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, Transform_ComboBox);

        Transform_Label = new QLabel(AddDevice);
        Transform_Label->setObjectName(QString::fromUtf8("Transform_Label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Transform_Label);

        Caption_Edit = new QLineEdit(AddDevice);
        Caption_Edit->setObjectName(QString::fromUtf8("Caption_Edit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Caption_Edit);

        Caption_Label = new QLabel(AddDevice);
        Caption_Label->setObjectName(QString::fromUtf8("Caption_Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Caption_Label);


        retranslateUi(AddDevice);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDevice, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDevice, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDevice);
    } // setupUi

    void retranslateUi(QDialog *AddDevice)
    {
        AddDevice->setWindowTitle(QApplication::translate("AddDevice", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        DeviceType_Label->setText(QApplication::translate("AddDevice", "\320\242\320\270\320\277 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260:", 0, QApplication::UnicodeUTF8));
        SelectDevice_Label->setText(QApplication::translate("AddDevice", "TextLabel", 0, QApplication::UnicodeUTF8));
        Resolution_Label->setText(QApplication::translate("AddDevice", "\320\240\320\260\320\267\321\200\320\265\321\210\320\265\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        DevType_ComboBox->clear();
        DevType_ComboBox->insertItems(0, QStringList()
         << QApplication::translate("AddDevice", "USB Web Camera", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddDevice", "IP Camera", 0, QApplication::UnicodeUTF8)
        );
        Transform_ComboBox->clear();
        Transform_ComboBox->insertItems(0, QStringList()
         << QApplication::translate("AddDevice", "\320\235\320\265 \321\200\320\260\320\262\320\276\321\200\320\260\321\207\320\270\320\262\320\260\321\202\321\214 360", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddDevice", "\320\240\320\260\320\267\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\275\320\260 180", 0, QApplication::UnicodeUTF8)
        );
        Transform_Label->setText(QApplication::translate("AddDevice", "\320\242\321\200\320\260\320\275\321\201\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214:", 0, QApplication::UnicodeUTF8));
        Caption_Label->setText(QApplication::translate("AddDevice", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddDevice: public Ui_AddDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICE_H

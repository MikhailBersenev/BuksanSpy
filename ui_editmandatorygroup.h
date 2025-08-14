/********************************************************************************
** Form generated from reading UI file 'editmandatorygroup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMANDATORYGROUP_H
#define UI_EDITMANDATORYGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_EditMandatoryGroup
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *NameLayout;
    QLabel *GroupName_Label;
    QLineEdit *GroupName_Edit;
    QLabel *MandatoryMark_Label;
    QComboBox *MandatoryMark_comboBox;
    QGroupBox *Rights_groupBox;
    QGridLayout *gridLayout;
    QCheckBox *alertsView_checkBox;
    QCheckBox *alertsDelete_checkBox;
    QCheckBox *generalSettingsView_checkBox;
    QCheckBox *UserControl_checkBox;
    QCheckBox *DeleteDevice_checkBox;
    QCheckBox *generalSettingsChange_checkBox;
    QCheckBox *editDevice_checkBox;
    QCheckBox *VideosDecrypt_checkBox;
    QCheckBox *VideosView_checkBox;
    QCheckBox *AddDevice_checkBox;
    QCheckBox *videosDelete_checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditMandatoryGroup)
    {
        if (EditMandatoryGroup->objectName().isEmpty())
            EditMandatoryGroup->setObjectName("EditMandatoryGroup");
        EditMandatoryGroup->resize(335, 453);
        gridLayout_2 = new QGridLayout(EditMandatoryGroup);
        gridLayout_2->setObjectName("gridLayout_2");
        NameLayout = new QFormLayout();
        NameLayout->setObjectName("NameLayout");
        GroupName_Label = new QLabel(EditMandatoryGroup);
        GroupName_Label->setObjectName("GroupName_Label");

        NameLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, GroupName_Label);

        GroupName_Edit = new QLineEdit(EditMandatoryGroup);
        GroupName_Edit->setObjectName("GroupName_Edit");

        NameLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, GroupName_Edit);

        MandatoryMark_Label = new QLabel(EditMandatoryGroup);
        MandatoryMark_Label->setObjectName("MandatoryMark_Label");

        NameLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, MandatoryMark_Label);

        MandatoryMark_comboBox = new QComboBox(EditMandatoryGroup);
        MandatoryMark_comboBox->setObjectName("MandatoryMark_comboBox");

        NameLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, MandatoryMark_comboBox);


        gridLayout_2->addLayout(NameLayout, 0, 0, 1, 1);

        Rights_groupBox = new QGroupBox(EditMandatoryGroup);
        Rights_groupBox->setObjectName("Rights_groupBox");
        gridLayout = new QGridLayout(Rights_groupBox);
        gridLayout->setObjectName("gridLayout");
        alertsView_checkBox = new QCheckBox(Rights_groupBox);
        alertsView_checkBox->setObjectName("alertsView_checkBox");
        alertsView_checkBox->setChecked(false);

        gridLayout->addWidget(alertsView_checkBox, 4, 0, 1, 1);

        alertsDelete_checkBox = new QCheckBox(Rights_groupBox);
        alertsDelete_checkBox->setObjectName("alertsDelete_checkBox");
        alertsDelete_checkBox->setChecked(false);

        gridLayout->addWidget(alertsDelete_checkBox, 5, 0, 1, 1);

        generalSettingsView_checkBox = new QCheckBox(Rights_groupBox);
        generalSettingsView_checkBox->setObjectName("generalSettingsView_checkBox");
        generalSettingsView_checkBox->setChecked(false);

        gridLayout->addWidget(generalSettingsView_checkBox, 6, 0, 1, 1);

        UserControl_checkBox = new QCheckBox(Rights_groupBox);
        UserControl_checkBox->setObjectName("UserControl_checkBox");
        UserControl_checkBox->setChecked(false);

        gridLayout->addWidget(UserControl_checkBox, 0, 0, 1, 1);

        DeleteDevice_checkBox = new QCheckBox(Rights_groupBox);
        DeleteDevice_checkBox->setObjectName("DeleteDevice_checkBox");
        DeleteDevice_checkBox->setChecked(false);

        gridLayout->addWidget(DeleteDevice_checkBox, 3, 0, 1, 1);

        generalSettingsChange_checkBox = new QCheckBox(Rights_groupBox);
        generalSettingsChange_checkBox->setObjectName("generalSettingsChange_checkBox");
        generalSettingsChange_checkBox->setChecked(false);

        gridLayout->addWidget(generalSettingsChange_checkBox, 7, 0, 1, 1);

        editDevice_checkBox = new QCheckBox(Rights_groupBox);
        editDevice_checkBox->setObjectName("editDevice_checkBox");
        editDevice_checkBox->setChecked(false);

        gridLayout->addWidget(editDevice_checkBox, 2, 0, 1, 1);

        VideosDecrypt_checkBox = new QCheckBox(Rights_groupBox);
        VideosDecrypt_checkBox->setObjectName("VideosDecrypt_checkBox");
        VideosDecrypt_checkBox->setChecked(false);

        gridLayout->addWidget(VideosDecrypt_checkBox, 9, 0, 1, 1);

        VideosView_checkBox = new QCheckBox(Rights_groupBox);
        VideosView_checkBox->setObjectName("VideosView_checkBox");
        VideosView_checkBox->setChecked(false);

        gridLayout->addWidget(VideosView_checkBox, 8, 0, 1, 1);

        AddDevice_checkBox = new QCheckBox(Rights_groupBox);
        AddDevice_checkBox->setObjectName("AddDevice_checkBox");
        AddDevice_checkBox->setChecked(false);

        gridLayout->addWidget(AddDevice_checkBox, 1, 0, 1, 1);

        videosDelete_checkBox = new QCheckBox(Rights_groupBox);
        videosDelete_checkBox->setObjectName("videosDelete_checkBox");
        videosDelete_checkBox->setChecked(false);

        gridLayout->addWidget(videosDelete_checkBox, 10, 0, 1, 1);


        gridLayout_2->addWidget(Rights_groupBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(EditMandatoryGroup);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(EditMandatoryGroup);

        QMetaObject::connectSlotsByName(EditMandatoryGroup);
    } // setupUi

    void retranslateUi(QDialog *EditMandatoryGroup)
    {
        EditMandatoryGroup->setWindowTitle(QCoreApplication::translate("EditMandatoryGroup", "Dialog", nullptr));
        GroupName_Label->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213:", nullptr));
        MandatoryMark_Label->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\320\260\321\217 \320\274\320\265\321\202\320\272\320\260:", nullptr));
        Rights_groupBox->setTitle(QCoreApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\260\320\262\320\260 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        alertsView_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", nullptr));
        alertsDelete_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", nullptr));
        generalSettingsView_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\276\320\261\321\211\320\270\321\205 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        UserControl_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\320\274\320\270 \320\270 \320\263\321\200\321\203\320\277\320\277\320\260\320\274\320\270", nullptr));
        DeleteDevice_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200", nullptr));
        generalSettingsChange_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\211\320\270\321\205 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        editDevice_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200", nullptr));
        VideosDecrypt_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\265\320\271", nullptr));
        VideosView_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\265\320\271", nullptr));
        AddDevice_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200", nullptr));
        videosDelete_checkBox->setText(QCoreApplication::translate("EditMandatoryGroup", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\265\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditMandatoryGroup: public Ui_EditMandatoryGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMANDATORYGROUP_H

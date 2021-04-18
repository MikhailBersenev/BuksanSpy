/********************************************************************************
** Form generated from reading UI file 'editmandatorygroup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMANDATORYGROUP_H
#define UI_EDITMANDATORYGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_EditMandatoryGroup
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *NameLayout;
    QLabel *GroupName_Label;
    QLineEdit *GroupName_Edit;
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
            EditMandatoryGroup->setObjectName(QString::fromUtf8("EditMandatoryGroup"));
        EditMandatoryGroup->resize(335, 439);
        gridLayout_2 = new QGridLayout(EditMandatoryGroup);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        NameLayout = new QFormLayout();
        NameLayout->setObjectName(QString::fromUtf8("NameLayout"));
        GroupName_Label = new QLabel(EditMandatoryGroup);
        GroupName_Label->setObjectName(QString::fromUtf8("GroupName_Label"));

        NameLayout->setWidget(0, QFormLayout::LabelRole, GroupName_Label);

        GroupName_Edit = new QLineEdit(EditMandatoryGroup);
        GroupName_Edit->setObjectName(QString::fromUtf8("GroupName_Edit"));

        NameLayout->setWidget(0, QFormLayout::FieldRole, GroupName_Edit);


        gridLayout_2->addLayout(NameLayout, 0, 0, 1, 1);

        Rights_groupBox = new QGroupBox(EditMandatoryGroup);
        Rights_groupBox->setObjectName(QString::fromUtf8("Rights_groupBox"));
        gridLayout = new QGridLayout(Rights_groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        alertsView_checkBox = new QCheckBox(Rights_groupBox);
        alertsView_checkBox->setObjectName(QString::fromUtf8("alertsView_checkBox"));
        alertsView_checkBox->setChecked(false);

        gridLayout->addWidget(alertsView_checkBox, 4, 0, 1, 1);

        alertsDelete_checkBox = new QCheckBox(Rights_groupBox);
        alertsDelete_checkBox->setObjectName(QString::fromUtf8("alertsDelete_checkBox"));
        alertsDelete_checkBox->setChecked(false);

        gridLayout->addWidget(alertsDelete_checkBox, 5, 0, 1, 1);

        generalSettingsView_checkBox = new QCheckBox(Rights_groupBox);
        generalSettingsView_checkBox->setObjectName(QString::fromUtf8("generalSettingsView_checkBox"));
        generalSettingsView_checkBox->setChecked(false);

        gridLayout->addWidget(generalSettingsView_checkBox, 6, 0, 1, 1);

        UserControl_checkBox = new QCheckBox(Rights_groupBox);
        UserControl_checkBox->setObjectName(QString::fromUtf8("UserControl_checkBox"));
        UserControl_checkBox->setChecked(false);

        gridLayout->addWidget(UserControl_checkBox, 0, 0, 1, 1);

        DeleteDevice_checkBox = new QCheckBox(Rights_groupBox);
        DeleteDevice_checkBox->setObjectName(QString::fromUtf8("DeleteDevice_checkBox"));
        DeleteDevice_checkBox->setChecked(false);

        gridLayout->addWidget(DeleteDevice_checkBox, 3, 0, 1, 1);

        generalSettingsChange_checkBox = new QCheckBox(Rights_groupBox);
        generalSettingsChange_checkBox->setObjectName(QString::fromUtf8("generalSettingsChange_checkBox"));
        generalSettingsChange_checkBox->setChecked(false);

        gridLayout->addWidget(generalSettingsChange_checkBox, 7, 0, 1, 1);

        editDevice_checkBox = new QCheckBox(Rights_groupBox);
        editDevice_checkBox->setObjectName(QString::fromUtf8("editDevice_checkBox"));
        editDevice_checkBox->setChecked(false);

        gridLayout->addWidget(editDevice_checkBox, 2, 0, 1, 1);

        VideosDecrypt_checkBox = new QCheckBox(Rights_groupBox);
        VideosDecrypt_checkBox->setObjectName(QString::fromUtf8("VideosDecrypt_checkBox"));
        VideosDecrypt_checkBox->setChecked(false);

        gridLayout->addWidget(VideosDecrypt_checkBox, 9, 0, 1, 1);

        VideosView_checkBox = new QCheckBox(Rights_groupBox);
        VideosView_checkBox->setObjectName(QString::fromUtf8("VideosView_checkBox"));
        VideosView_checkBox->setChecked(false);

        gridLayout->addWidget(VideosView_checkBox, 8, 0, 1, 1);

        AddDevice_checkBox = new QCheckBox(Rights_groupBox);
        AddDevice_checkBox->setObjectName(QString::fromUtf8("AddDevice_checkBox"));
        AddDevice_checkBox->setChecked(false);

        gridLayout->addWidget(AddDevice_checkBox, 1, 0, 1, 1);

        videosDelete_checkBox = new QCheckBox(Rights_groupBox);
        videosDelete_checkBox->setObjectName(QString::fromUtf8("videosDelete_checkBox"));
        videosDelete_checkBox->setChecked(false);

        gridLayout->addWidget(videosDelete_checkBox, 10, 0, 1, 1);


        gridLayout_2->addWidget(Rights_groupBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(EditMandatoryGroup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(EditMandatoryGroup);

        QMetaObject::connectSlotsByName(EditMandatoryGroup);
    } // setupUi

    void retranslateUi(QDialog *EditMandatoryGroup)
    {
        EditMandatoryGroup->setWindowTitle(QApplication::translate("EditMandatoryGroup", "Dialog", 0, QApplication::UnicodeUTF8));
        GroupName_Label->setText(QApplication::translate("EditMandatoryGroup", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213:", 0, QApplication::UnicodeUTF8));
        Rights_groupBox->setTitle(QApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\260\320\262\320\260 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", 0, QApplication::UnicodeUTF8));
        alertsView_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", 0, QApplication::UnicodeUTF8));
        alertsDelete_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", 0, QApplication::UnicodeUTF8));
        generalSettingsView_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\276\320\261\321\211\320\270\321\205 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
        UserControl_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\320\274\320\270 \320\270 \320\263\321\200\321\203\320\277\320\277\320\260\320\274\320\270", 0, QApplication::UnicodeUTF8));
        DeleteDevice_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        generalSettingsChange_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\211\320\270\321\205 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
        editDevice_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        VideosDecrypt_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\265\320\271", 0, QApplication::UnicodeUTF8));
        VideosView_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\265\320\271", 0, QApplication::UnicodeUTF8));
        AddDevice_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        videosDelete_checkBox->setText(QApplication::translate("EditMandatoryGroup", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\265\320\271", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditMandatoryGroup: public Ui_EditMandatoryGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMANDATORYGROUP_H

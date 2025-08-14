/********************************************************************************
** Form generated from reading UI file 'mandatorygroups.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANDATORYGROUPS_H
#define UI_MANDATORYGROUPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MandatoryGroups
{
public:
    QGridLayout *gridLayout;
    QGroupBox *MandatoryGroups_groupBox;
    QVBoxLayout *verticalLayout;
    QListView *MandatoryGroupslistView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *MandatoryMark_label_2;
    QLabel *MandatoryMark_label;
    QGroupBox *RoleAtributes_groupBox;
    QHBoxLayout *horizontalLayout;
    QListWidget *RoleAtributes_listWidget;
    QVBoxLayout *Buttons_Layout;
    QPushButton *AddMandatoryGroup_Button;
    QPushButton *EditMandatoryGroup_pushButton;
    QPushButton *DeleteMandatoryGroup_Button;

    void setupUi(QDialog *MandatoryGroups)
    {
        if (MandatoryGroups->objectName().isEmpty())
            MandatoryGroups->setObjectName("MandatoryGroups");
        MandatoryGroups->resize(624, 374);
        gridLayout = new QGridLayout(MandatoryGroups);
        gridLayout->setObjectName("gridLayout");
        MandatoryGroups_groupBox = new QGroupBox(MandatoryGroups);
        MandatoryGroups_groupBox->setObjectName("MandatoryGroups_groupBox");
        verticalLayout = new QVBoxLayout(MandatoryGroups_groupBox);
        verticalLayout->setObjectName("verticalLayout");
        MandatoryGroupslistView = new QListView(MandatoryGroups_groupBox);
        MandatoryGroupslistView->setObjectName("MandatoryGroupslistView");

        verticalLayout->addWidget(MandatoryGroupslistView);


        gridLayout->addWidget(MandatoryGroups_groupBox, 0, 0, 2, 1);

        groupBox = new QGroupBox(MandatoryGroups);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        MandatoryMark_label_2 = new QLabel(groupBox);
        MandatoryMark_label_2->setObjectName("MandatoryMark_label_2");

        verticalLayout_2->addWidget(MandatoryMark_label_2);

        MandatoryMark_label = new QLabel(groupBox);
        MandatoryMark_label->setObjectName("MandatoryMark_label");

        verticalLayout_2->addWidget(MandatoryMark_label);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        RoleAtributes_groupBox = new QGroupBox(MandatoryGroups);
        RoleAtributes_groupBox->setObjectName("RoleAtributes_groupBox");
        horizontalLayout = new QHBoxLayout(RoleAtributes_groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        RoleAtributes_listWidget = new QListWidget(RoleAtributes_groupBox);
        RoleAtributes_listWidget->setObjectName("RoleAtributes_listWidget");

        horizontalLayout->addWidget(RoleAtributes_listWidget);


        gridLayout->addWidget(RoleAtributes_groupBox, 1, 1, 2, 1);

        Buttons_Layout = new QVBoxLayout();
        Buttons_Layout->setObjectName("Buttons_Layout");
        AddMandatoryGroup_Button = new QPushButton(MandatoryGroups);
        AddMandatoryGroup_Button->setObjectName("AddMandatoryGroup_Button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddMandatoryGroup_Button->sizePolicy().hasHeightForWidth());
        AddMandatoryGroup_Button->setSizePolicy(sizePolicy);

        Buttons_Layout->addWidget(AddMandatoryGroup_Button);

        EditMandatoryGroup_pushButton = new QPushButton(MandatoryGroups);
        EditMandatoryGroup_pushButton->setObjectName("EditMandatoryGroup_pushButton");

        Buttons_Layout->addWidget(EditMandatoryGroup_pushButton);

        DeleteMandatoryGroup_Button = new QPushButton(MandatoryGroups);
        DeleteMandatoryGroup_Button->setObjectName("DeleteMandatoryGroup_Button");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DeleteMandatoryGroup_Button->sizePolicy().hasHeightForWidth());
        DeleteMandatoryGroup_Button->setSizePolicy(sizePolicy1);

        Buttons_Layout->addWidget(DeleteMandatoryGroup_Button);


        gridLayout->addLayout(Buttons_Layout, 2, 0, 1, 1);


        retranslateUi(MandatoryGroups);

        QMetaObject::connectSlotsByName(MandatoryGroups);
    } // setupUi

    void retranslateUi(QDialog *MandatoryGroups)
    {
        MandatoryGroups->setWindowTitle(QCoreApplication::translate("MandatoryGroups", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\321\213\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        MandatoryGroups_groupBox->setTitle(QCoreApplication::translate("MandatoryGroups", "\320\223\321\200\321\203\320\277\320\277\321\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MandatoryGroups", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\263\321\200\321\203\320\277\320\277\320\265", nullptr));
        MandatoryMark_label_2->setText(QCoreApplication::translate("MandatoryGroups", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\320\260\321\217 \320\274\320\265\321\202\320\272\320\260:", nullptr));
        MandatoryMark_label->setText(QString());
        RoleAtributes_groupBox->setTitle(QCoreApplication::translate("MandatoryGroups", "\320\240\320\276\320\273\320\265\320\262\321\213\320\265 \320\260\321\202\321\200\320\270\320\261\321\203\321\202\321\213", nullptr));
        AddMandatoryGroup_Button->setText(QCoreApplication::translate("MandatoryGroups", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        EditMandatoryGroup_pushButton->setText(QCoreApplication::translate("MandatoryGroups", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        DeleteMandatoryGroup_Button->setText(QCoreApplication::translate("MandatoryGroups", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MandatoryGroups: public Ui_MandatoryGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDATORYGROUPS_H

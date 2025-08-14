/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QAction *ChangePassword_action;
    QGridLayout *gridLayout_3;
    QGroupBox *users_groupBox;
    QGridLayout *gridLayout;
    QListView *users_listView;
    QVBoxLayout *ButtonsLayout;
    QPushButton *AddUser_Button;
    QPushButton *DeleteUser_Button;
    QGroupBox *userinfo_groupBox;
    QGridLayout *gridLayout_2;
    QLabel *mandatorygroup_label;
    QSpacerItem *horizontalSpacer;
    QLabel *macm_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *RegistrationDate_label;
    QLabel *registrationdate_label_2;
    QLabel *macm_label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *mandatorygroup_label_2;
    QGroupBox *additional_groupBox;
    QVBoxLayout *verticalLayout;
    QToolButton *MandatoryMarksEditor_toolButton;
    QToolButton *MandatoryGroupsEditor_toolButton;
    QGroupBox *RoleAtributes_groupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *RoleAtributes_listWidget;

    void setupUi(QDialog *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName("Users");
        Users->resize(932, 472);
        ChangePassword_action = new QAction(Users);
        ChangePassword_action->setObjectName("ChangePassword_action");
        gridLayout_3 = new QGridLayout(Users);
        gridLayout_3->setObjectName("gridLayout_3");
        users_groupBox = new QGroupBox(Users);
        users_groupBox->setObjectName("users_groupBox");
        gridLayout = new QGridLayout(users_groupBox);
        gridLayout->setObjectName("gridLayout");
        users_listView = new QListView(users_groupBox);
        users_listView->setObjectName("users_listView");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arimo")});
        font.setPointSize(16);
        font.setBold(true);
        users_listView->setFont(font);
        users_listView->setContextMenuPolicy(Qt::ActionsContextMenu);

        gridLayout->addWidget(users_listView, 0, 0, 1, 1);

        ButtonsLayout = new QVBoxLayout();
        ButtonsLayout->setObjectName("ButtonsLayout");
        AddUser_Button = new QPushButton(users_groupBox);
        AddUser_Button->setObjectName("AddUser_Button");

        ButtonsLayout->addWidget(AddUser_Button);

        DeleteUser_Button = new QPushButton(users_groupBox);
        DeleteUser_Button->setObjectName("DeleteUser_Button");

        ButtonsLayout->addWidget(DeleteUser_Button);


        gridLayout->addLayout(ButtonsLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(users_groupBox, 0, 0, 2, 1);

        userinfo_groupBox = new QGroupBox(Users);
        userinfo_groupBox->setObjectName("userinfo_groupBox");
        gridLayout_2 = new QGridLayout(userinfo_groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        mandatorygroup_label = new QLabel(userinfo_groupBox);
        mandatorygroup_label->setObjectName("mandatorygroup_label");

        gridLayout_2->addWidget(mandatorygroup_label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(115, 18, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        macm_label = new QLabel(userinfo_groupBox);
        macm_label->setObjectName("macm_label");

        gridLayout_2->addWidget(macm_label, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(114, 18, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        RegistrationDate_label = new QLabel(userinfo_groupBox);
        RegistrationDate_label->setObjectName("RegistrationDate_label");

        gridLayout_2->addWidget(RegistrationDate_label, 0, 4, 1, 1);

        registrationdate_label_2 = new QLabel(userinfo_groupBox);
        registrationdate_label_2->setObjectName("registrationdate_label_2");

        gridLayout_2->addWidget(registrationdate_label_2, 1, 4, 1, 1);

        macm_label_2 = new QLabel(userinfo_groupBox);
        macm_label_2->setObjectName("macm_label_2");

        gridLayout_2->addWidget(macm_label_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(65, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(85, 18, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        mandatorygroup_label_2 = new QLabel(userinfo_groupBox);
        mandatorygroup_label_2->setObjectName("mandatorygroup_label_2");

        gridLayout_2->addWidget(mandatorygroup_label_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(userinfo_groupBox, 0, 1, 1, 2);

        additional_groupBox = new QGroupBox(Users);
        additional_groupBox->setObjectName("additional_groupBox");
        verticalLayout = new QVBoxLayout(additional_groupBox);
        verticalLayout->setObjectName("verticalLayout");
        MandatoryMarksEditor_toolButton = new QToolButton(additional_groupBox);
        MandatoryMarksEditor_toolButton->setObjectName("MandatoryMarksEditor_toolButton");
        MandatoryMarksEditor_toolButton->setAutoFillBackground(false);
        MandatoryMarksEditor_toolButton->setInputMethodHints(Qt::ImhNone);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/key.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MandatoryMarksEditor_toolButton->setIcon(icon);
        MandatoryMarksEditor_toolButton->setIconSize(QSize(128, 128));
        MandatoryMarksEditor_toolButton->setCheckable(false);
        MandatoryMarksEditor_toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(MandatoryMarksEditor_toolButton);

        MandatoryGroupsEditor_toolButton = new QToolButton(additional_groupBox);
        MandatoryGroupsEditor_toolButton->setObjectName("MandatoryGroupsEditor_toolButton");
        MandatoryGroupsEditor_toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(MandatoryGroupsEditor_toolButton);


        gridLayout_3->addWidget(additional_groupBox, 1, 2, 1, 1);

        RoleAtributes_groupBox = new QGroupBox(Users);
        RoleAtributes_groupBox->setObjectName("RoleAtributes_groupBox");
        verticalLayout_2 = new QVBoxLayout(RoleAtributes_groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        RoleAtributes_listWidget = new QListWidget(RoleAtributes_groupBox);
        RoleAtributes_listWidget->setObjectName("RoleAtributes_listWidget");

        verticalLayout_2->addWidget(RoleAtributes_listWidget);


        gridLayout_3->addWidget(RoleAtributes_groupBox, 1, 1, 1, 1);


        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QDialog *Users)
    {
        Users->setWindowTitle(QCoreApplication::translate("Users", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270 \320\270 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        ChangePassword_action->setText(QCoreApplication::translate("Users", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
#if QT_CONFIG(tooltip)
        ChangePassword_action->setToolTip(QCoreApplication::translate("Users", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        users_groupBox->setTitle(QCoreApplication::translate("Users", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        AddUser_Button->setText(QCoreApplication::translate("Users", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", nullptr));
        DeleteUser_Button->setText(QCoreApplication::translate("Users", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        userinfo_groupBox->setTitle(QCoreApplication::translate("Users", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265", nullptr));
        mandatorygroup_label->setText(QCoreApplication::translate("Users", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\320\260\321\217 \320\263\321\200\321\203\320\277\320\277\320\260:", nullptr));
        macm_label->setText(QCoreApplication::translate("Users", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\320\277\321\203\321\201\320\272\320\260:", nullptr));
        RegistrationDate_label->setText(QCoreApplication::translate("Users", "\320\224\320\260\321\202\320\260 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270:", nullptr));
        registrationdate_label_2->setText(QString());
        macm_label_2->setText(QString());
        mandatorygroup_label_2->setText(QString());
        additional_groupBox->setTitle(QCoreApplication::translate("Users", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276", nullptr));
        MandatoryMarksEditor_toolButton->setText(QCoreApplication::translate("Users", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\321\213\320\265 \320\274\320\265\321\202\320\272\320\270", nullptr));
        MandatoryGroupsEditor_toolButton->setText(QCoreApplication::translate("Users", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\321\213\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        RoleAtributes_groupBox->setTitle(QCoreApplication::translate("Users", "\320\240\320\276\320\273\320\265\320\262\321\213\320\265 \320\260\321\202\321\200\320\270\320\261\321\203\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H

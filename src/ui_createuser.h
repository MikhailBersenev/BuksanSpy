/********************************************************************************
** Form generated from reading UI file 'createuser.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateUser
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *Login_Label;
    QLabel *Password_Label;
    QLabel *RepeatPassword_Label;
    QLineEdit *Login_Edit;
    QLabel *Rights_Label;
    QComboBox *Rights_ComboBox;
    QLineEdit *Password_Edit;
    QLineEdit *RepeatPassword_Edit;
    QCheckBox *ShowPassword_CheckBox;
    QPushButton *Confirm_Button;

    void setupUi(QDialog *CreateUser)
    {
        if (CreateUser->objectName().isEmpty())
            CreateUser->setObjectName("CreateUser");
        CreateUser->setWindowModality(Qt::WindowModal);
        CreateUser->resize(454, 169);
        CreateUser->setMaximumSize(QSize(454, 169));
        gridLayout = new QGridLayout(CreateUser);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        Login_Label = new QLabel(CreateUser);
        Login_Label->setObjectName("Login_Label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, Login_Label);

        Password_Label = new QLabel(CreateUser);
        Password_Label->setObjectName("Password_Label");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, Password_Label);

        RepeatPassword_Label = new QLabel(CreateUser);
        RepeatPassword_Label->setObjectName("RepeatPassword_Label");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, RepeatPassword_Label);

        Login_Edit = new QLineEdit(CreateUser);
        Login_Edit->setObjectName("Login_Edit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, Login_Edit);

        Rights_Label = new QLabel(CreateUser);
        Rights_Label->setObjectName("Rights_Label");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, Rights_Label);

        Rights_ComboBox = new QComboBox(CreateUser);
        Rights_ComboBox->setObjectName("Rights_ComboBox");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, Rights_ComboBox);

        Password_Edit = new QLineEdit(CreateUser);
        Password_Edit->setObjectName("Password_Edit");
        Password_Edit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, Password_Edit);

        RepeatPassword_Edit = new QLineEdit(CreateUser);
        RepeatPassword_Edit->setObjectName("RepeatPassword_Edit");
        RepeatPassword_Edit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, RepeatPassword_Edit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        ShowPassword_CheckBox = new QCheckBox(CreateUser);
        ShowPassword_CheckBox->setObjectName("ShowPassword_CheckBox");

        gridLayout->addWidget(ShowPassword_CheckBox, 1, 0, 1, 1);

        Confirm_Button = new QPushButton(CreateUser);
        Confirm_Button->setObjectName("Confirm_Button");

        gridLayout->addWidget(Confirm_Button, 1, 1, 1, 1);


        retranslateUi(CreateUser);

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QDialog *CreateUser)
    {
        CreateUser->setWindowTitle(QCoreApplication::translate("CreateUser", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        Login_Label->setText(QCoreApplication::translate("CreateUser", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        Password_Label->setText(QCoreApplication::translate("CreateUser", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        RepeatPassword_Label->setText(QCoreApplication::translate("CreateUser", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        Rights_Label->setText(QCoreApplication::translate("CreateUser", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\320\260\321\217 \320\263\321\200\321\203\320\277\320\277\320\260:", nullptr));
        ShowPassword_CheckBox->setText(QCoreApplication::translate("CreateUser", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        Confirm_Button->setText(QCoreApplication::translate("CreateUser", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H

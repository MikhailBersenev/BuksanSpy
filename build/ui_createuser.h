/********************************************************************************
** Form generated from reading UI file 'createuser.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

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
            CreateUser->setObjectName(QString::fromUtf8("CreateUser"));
        CreateUser->setWindowModality(Qt::WindowModal);
        CreateUser->resize(454, 169);
        CreateUser->setMaximumSize(QSize(454, 169));
        gridLayout = new QGridLayout(CreateUser);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Login_Label = new QLabel(CreateUser);
        Login_Label->setObjectName(QString::fromUtf8("Login_Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Login_Label);

        Password_Label = new QLabel(CreateUser);
        Password_Label->setObjectName(QString::fromUtf8("Password_Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Password_Label);

        RepeatPassword_Label = new QLabel(CreateUser);
        RepeatPassword_Label->setObjectName(QString::fromUtf8("RepeatPassword_Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, RepeatPassword_Label);

        Login_Edit = new QLineEdit(CreateUser);
        Login_Edit->setObjectName(QString::fromUtf8("Login_Edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Login_Edit);

        Rights_Label = new QLabel(CreateUser);
        Rights_Label->setObjectName(QString::fromUtf8("Rights_Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Rights_Label);

        Rights_ComboBox = new QComboBox(CreateUser);
        Rights_ComboBox->setObjectName(QString::fromUtf8("Rights_ComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Rights_ComboBox);

        Password_Edit = new QLineEdit(CreateUser);
        Password_Edit->setObjectName(QString::fromUtf8("Password_Edit"));
        Password_Edit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, Password_Edit);

        RepeatPassword_Edit = new QLineEdit(CreateUser);
        RepeatPassword_Edit->setObjectName(QString::fromUtf8("RepeatPassword_Edit"));
        RepeatPassword_Edit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, RepeatPassword_Edit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        ShowPassword_CheckBox = new QCheckBox(CreateUser);
        ShowPassword_CheckBox->setObjectName(QString::fromUtf8("ShowPassword_CheckBox"));

        gridLayout->addWidget(ShowPassword_CheckBox, 1, 0, 1, 1);

        Confirm_Button = new QPushButton(CreateUser);
        Confirm_Button->setObjectName(QString::fromUtf8("Confirm_Button"));

        gridLayout->addWidget(Confirm_Button, 1, 1, 1, 1);


        retranslateUi(CreateUser);

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QDialog *CreateUser)
    {
        CreateUser->setWindowTitle(QApplication::translate("CreateUser", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0, QApplication::UnicodeUTF8));
        Login_Label->setText(QApplication::translate("CreateUser", "\320\233\320\276\320\263\320\270\320\275:", 0, QApplication::UnicodeUTF8));
        Password_Label->setText(QApplication::translate("CreateUser", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        RepeatPassword_Label->setText(QApplication::translate("CreateUser", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        Rights_Label->setText(QApplication::translate("CreateUser", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\320\260\321\217 \320\263\321\200\321\203\320\277\320\277\320\260:", 0, QApplication::UnicodeUTF8));
        ShowPassword_CheckBox->setText(QApplication::translate("CreateUser", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        Confirm_Button->setText(QApplication::translate("CreateUser", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H

/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QGridLayout *gridLayout;
    QGridLayout *LoginAll_Layout;
    QFormLayout *Login_Layout;
    QLabel *host_Label;
    QLineEdit *Host_Edit;
    QLabel *label;
    QLineEdit *DataBase_Edit;
    QLabel *Port_Label;
    QLineEdit *Port_Edit;
    QLabel *Login_Label;
    QLineEdit *Login_Edit;
    QLabel *Password_Label;
    QLineEdit *Password_Edit;
    QPushButton *TryLogin_Button;
    QCheckBox *SaveLoginStrings_checkBox;
    QCheckBox *ShowPassword_checkBox;

    void setupUi(QDialog *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName("Authorization");
        Authorization->resize(539, 268);
        Authorization->setMaximumSize(QSize(539, 268));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Authorization->setWindowIcon(icon);
        gridLayout = new QGridLayout(Authorization);
        gridLayout->setObjectName("gridLayout");
        LoginAll_Layout = new QGridLayout();
        LoginAll_Layout->setObjectName("LoginAll_Layout");
        Login_Layout = new QFormLayout();
        Login_Layout->setObjectName("Login_Layout");
        host_Label = new QLabel(Authorization);
        host_Label->setObjectName("host_Label");

        Login_Layout->setWidget(0, QFormLayout::ItemRole::LabelRole, host_Label);

        Host_Edit = new QLineEdit(Authorization);
        Host_Edit->setObjectName("Host_Edit");

        Login_Layout->setWidget(0, QFormLayout::ItemRole::FieldRole, Host_Edit);

        label = new QLabel(Authorization);
        label->setObjectName("label");

        Login_Layout->setWidget(1, QFormLayout::ItemRole::LabelRole, label);

        DataBase_Edit = new QLineEdit(Authorization);
        DataBase_Edit->setObjectName("DataBase_Edit");

        Login_Layout->setWidget(1, QFormLayout::ItemRole::FieldRole, DataBase_Edit);

        Port_Label = new QLabel(Authorization);
        Port_Label->setObjectName("Port_Label");

        Login_Layout->setWidget(2, QFormLayout::ItemRole::LabelRole, Port_Label);

        Port_Edit = new QLineEdit(Authorization);
        Port_Edit->setObjectName("Port_Edit");

        Login_Layout->setWidget(2, QFormLayout::ItemRole::FieldRole, Port_Edit);

        Login_Label = new QLabel(Authorization);
        Login_Label->setObjectName("Login_Label");

        Login_Layout->setWidget(3, QFormLayout::ItemRole::LabelRole, Login_Label);

        Login_Edit = new QLineEdit(Authorization);
        Login_Edit->setObjectName("Login_Edit");

        Login_Layout->setWidget(3, QFormLayout::ItemRole::FieldRole, Login_Edit);

        Password_Label = new QLabel(Authorization);
        Password_Label->setObjectName("Password_Label");

        Login_Layout->setWidget(4, QFormLayout::ItemRole::LabelRole, Password_Label);

        Password_Edit = new QLineEdit(Authorization);
        Password_Edit->setObjectName("Password_Edit");
        Password_Edit->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        Password_Edit->setEchoMode(QLineEdit::Password);

        Login_Layout->setWidget(4, QFormLayout::ItemRole::FieldRole, Password_Edit);

        TryLogin_Button = new QPushButton(Authorization);
        TryLogin_Button->setObjectName("TryLogin_Button");

        Login_Layout->setWidget(5, QFormLayout::ItemRole::FieldRole, TryLogin_Button);

        SaveLoginStrings_checkBox = new QCheckBox(Authorization);
        SaveLoginStrings_checkBox->setObjectName("SaveLoginStrings_checkBox");

        Login_Layout->setWidget(7, QFormLayout::ItemRole::FieldRole, SaveLoginStrings_checkBox);

        ShowPassword_checkBox = new QCheckBox(Authorization);
        ShowPassword_checkBox->setObjectName("ShowPassword_checkBox");

        Login_Layout->setWidget(6, QFormLayout::ItemRole::FieldRole, ShowPassword_checkBox);


        LoginAll_Layout->addLayout(Login_Layout, 1, 0, 1, 1);


        gridLayout->addLayout(LoginAll_Layout, 0, 0, 1, 2);


        retranslateUi(Authorization);

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QDialog *Authorization)
    {
        Authorization->setWindowTitle(QCoreApplication::translate("Authorization", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        host_Label->setText(QCoreApplication::translate("Authorization", "IP \320\260\320\264\321\200\320\265\321\201:", nullptr));
        label->setText(QCoreApplication::translate("Authorization", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        Port_Label->setText(QCoreApplication::translate("Authorization", "\320\237\320\276\321\200\321\202:", nullptr));
        Port_Edit->setText(QCoreApplication::translate("Authorization", "5432", nullptr));
        Login_Label->setText(QCoreApplication::translate("Authorization", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        Password_Label->setText(QCoreApplication::translate("Authorization", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        TryLogin_Button->setText(QCoreApplication::translate("Authorization", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        SaveLoginStrings_checkBox->setText(QCoreApplication::translate("Authorization", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\321\214 \321\201\320\265\321\201\321\201\320\270\321\216", nullptr));
        ShowPassword_checkBox->setText(QCoreApplication::translate("Authorization", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H

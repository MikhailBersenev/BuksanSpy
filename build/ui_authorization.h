/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QGridLayout *gridLayout;
    QGridLayout *LoginAll_Layout;
    QToolButton *GoToRestorePassword_Button;
    QFormLayout *Login_Layout;
    QLineEdit *Login_Edit;
    QPushButton *TryLogin_Button;
    QLabel *Password_Label;
    QLabel *Login_Label;
    QLineEdit *Password_Edit;
    QLabel *ForgetPassword_Label;
    QPushButton *GotToRegistration_Button;
    QPushButton *GoToSetupConnection_Button;
    QPushButton *quit_Button;

    void setupUi(QDialog *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName(QString::fromUtf8("Authorization"));
        Authorization->resize(484, 207);
        Authorization->setMaximumSize(QSize(484, 207));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Authorization->setWindowIcon(icon);
        gridLayout = new QGridLayout(Authorization);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LoginAll_Layout = new QGridLayout();
        LoginAll_Layout->setObjectName(QString::fromUtf8("LoginAll_Layout"));
        GoToRestorePassword_Button = new QToolButton(Authorization);
        GoToRestorePassword_Button->setObjectName(QString::fromUtf8("GoToRestorePassword_Button"));

        LoginAll_Layout->addWidget(GoToRestorePassword_Button, 1, 1, 1, 1);

        Login_Layout = new QFormLayout();
        Login_Layout->setObjectName(QString::fromUtf8("Login_Layout"));
        Login_Edit = new QLineEdit(Authorization);
        Login_Edit->setObjectName(QString::fromUtf8("Login_Edit"));

        Login_Layout->setWidget(1, QFormLayout::FieldRole, Login_Edit);

        TryLogin_Button = new QPushButton(Authorization);
        TryLogin_Button->setObjectName(QString::fromUtf8("TryLogin_Button"));

        Login_Layout->setWidget(3, QFormLayout::FieldRole, TryLogin_Button);

        Password_Label = new QLabel(Authorization);
        Password_Label->setObjectName(QString::fromUtf8("Password_Label"));

        Login_Layout->setWidget(2, QFormLayout::LabelRole, Password_Label);

        Login_Label = new QLabel(Authorization);
        Login_Label->setObjectName(QString::fromUtf8("Login_Label"));

        Login_Layout->setWidget(1, QFormLayout::LabelRole, Login_Label);

        Password_Edit = new QLineEdit(Authorization);
        Password_Edit->setObjectName(QString::fromUtf8("Password_Edit"));
        Password_Edit->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        Password_Edit->setEchoMode(QLineEdit::Password);

        Login_Layout->setWidget(2, QFormLayout::FieldRole, Password_Edit);


        LoginAll_Layout->addLayout(Login_Layout, 0, 0, 1, 2);

        ForgetPassword_Label = new QLabel(Authorization);
        ForgetPassword_Label->setObjectName(QString::fromUtf8("ForgetPassword_Label"));

        LoginAll_Layout->addWidget(ForgetPassword_Label, 1, 0, 1, 1);


        gridLayout->addLayout(LoginAll_Layout, 0, 0, 1, 2);

        GotToRegistration_Button = new QPushButton(Authorization);
        GotToRegistration_Button->setObjectName(QString::fromUtf8("GotToRegistration_Button"));

        gridLayout->addWidget(GotToRegistration_Button, 1, 0, 1, 2);

        GoToSetupConnection_Button = new QPushButton(Authorization);
        GoToSetupConnection_Button->setObjectName(QString::fromUtf8("GoToSetupConnection_Button"));

        gridLayout->addWidget(GoToSetupConnection_Button, 2, 0, 1, 1);

        quit_Button = new QPushButton(Authorization);
        quit_Button->setObjectName(QString::fromUtf8("quit_Button"));

        gridLayout->addWidget(quit_Button, 2, 1, 1, 1);


        retranslateUi(Authorization);

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QDialog *Authorization)
    {
        Authorization->setWindowTitle(QApplication::translate("Authorization", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", 0, QApplication::UnicodeUTF8));
        GoToRestorePassword_Button->setText(QApplication::translate("Authorization", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        TryLogin_Button->setText(QApplication::translate("Authorization", "\320\222\320\276\320\271\321\202\320\270", 0, QApplication::UnicodeUTF8));
        Password_Label->setText(QApplication::translate("Authorization", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        Login_Label->setText(QApplication::translate("Authorization", "\320\233\320\276\320\263\320\270\320\275:", 0, QApplication::UnicodeUTF8));
        ForgetPassword_Label->setText(QApplication::translate("Authorization", "\320\227\320\260\320\261\321\213\320\273\320\270 \320\277\320\260\321\200\320\276\320\273\321\214?", 0, QApplication::UnicodeUTF8));
        GotToRegistration_Button->setText(QApplication::translate("Authorization", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        GoToSetupConnection_Button->setText(QApplication::translate("Authorization", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        quit_Button->setText(QApplication::translate("Authorization", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H

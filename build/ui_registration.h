/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QGridLayout *gridLayout;
    QFormLayout *EditsLayout;
    QLabel *Login_Label;
    QLineEdit *Login_Edit;
    QLabel *Password_Label;
    QLineEdit *Password_Edit;
    QLabel *RepeatPassword_Label;
    QLineEdit *RepeatPassword_Edit;
    QLabel *Email_Label;
    QLineEdit *Email_Edit;
    QLabel *RegistrationTitle_Label;
    QPushButton *TryToRegister_Button;
    QLabel *RegistrationDescription_Label;
    QSpacerItem *horizontalSpacer;
    QCheckBox *ShowPassword_CheckBox;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(484, 286);
        Registration->setMaximumSize(QSize(484, 286));
        gridLayout = new QGridLayout(Registration);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        EditsLayout = new QFormLayout();
        EditsLayout->setObjectName(QString::fromUtf8("EditsLayout"));
        Login_Label = new QLabel(Registration);
        Login_Label->setObjectName(QString::fromUtf8("Login_Label"));

        EditsLayout->setWidget(0, QFormLayout::LabelRole, Login_Label);

        Login_Edit = new QLineEdit(Registration);
        Login_Edit->setObjectName(QString::fromUtf8("Login_Edit"));

        EditsLayout->setWidget(0, QFormLayout::FieldRole, Login_Edit);

        Password_Label = new QLabel(Registration);
        Password_Label->setObjectName(QString::fromUtf8("Password_Label"));

        EditsLayout->setWidget(2, QFormLayout::LabelRole, Password_Label);

        Password_Edit = new QLineEdit(Registration);
        Password_Edit->setObjectName(QString::fromUtf8("Password_Edit"));
        Password_Edit->setEchoMode(QLineEdit::Password);

        EditsLayout->setWidget(2, QFormLayout::FieldRole, Password_Edit);

        RepeatPassword_Label = new QLabel(Registration);
        RepeatPassword_Label->setObjectName(QString::fromUtf8("RepeatPassword_Label"));

        EditsLayout->setWidget(3, QFormLayout::LabelRole, RepeatPassword_Label);

        RepeatPassword_Edit = new QLineEdit(Registration);
        RepeatPassword_Edit->setObjectName(QString::fromUtf8("RepeatPassword_Edit"));
        RepeatPassword_Edit->setEchoMode(QLineEdit::Password);

        EditsLayout->setWidget(3, QFormLayout::FieldRole, RepeatPassword_Edit);

        Email_Label = new QLabel(Registration);
        Email_Label->setObjectName(QString::fromUtf8("Email_Label"));

        EditsLayout->setWidget(1, QFormLayout::LabelRole, Email_Label);

        Email_Edit = new QLineEdit(Registration);
        Email_Edit->setObjectName(QString::fromUtf8("Email_Edit"));

        EditsLayout->setWidget(1, QFormLayout::FieldRole, Email_Edit);


        gridLayout->addLayout(EditsLayout, 2, 0, 1, 2);

        RegistrationTitle_Label = new QLabel(Registration);
        RegistrationTitle_Label->setObjectName(QString::fromUtf8("RegistrationTitle_Label"));
        QFont font;
        font.setPointSize(20);
        RegistrationTitle_Label->setFont(font);

        gridLayout->addWidget(RegistrationTitle_Label, 0, 0, 1, 1);

        TryToRegister_Button = new QPushButton(Registration);
        TryToRegister_Button->setObjectName(QString::fromUtf8("TryToRegister_Button"));

        gridLayout->addWidget(TryToRegister_Button, 5, 0, 1, 2);

        RegistrationDescription_Label = new QLabel(Registration);
        RegistrationDescription_Label->setObjectName(QString::fromUtf8("RegistrationDescription_Label"));

        gridLayout->addWidget(RegistrationDescription_Label, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        ShowPassword_CheckBox = new QCheckBox(Registration);
        ShowPassword_CheckBox->setObjectName(QString::fromUtf8("ShowPassword_CheckBox"));

        gridLayout->addWidget(ShowPassword_CheckBox, 3, 1, 1, 1);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        Login_Label->setText(QApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275:", 0, QApplication::UnicodeUTF8));
        Password_Label->setText(QApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        RepeatPassword_Label->setText(QApplication::translate("Registration", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        Email_Label->setText(QApplication::translate("Registration", "E-mail:", 0, QApplication::UnicodeUTF8));
        RegistrationTitle_Label->setText(QApplication::translate("Registration", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        TryToRegister_Button->setText(QApplication::translate("Registration", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        RegistrationDescription_Label->setText(QApplication::translate("Registration", "<Center><h3>\320\224\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 <br> \320\267\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\277\320\276\320\273\321\217 \n"
" \320\275\320\270\320\266\320\265</h3></Center>", 0, QApplication::UnicodeUTF8));
        ShowPassword_CheckBox->setText(QApplication::translate("Registration", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H

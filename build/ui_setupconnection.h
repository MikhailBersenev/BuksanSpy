/********************************************************************************
** Form generated from reading UI file 'setupconnection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPCONNECTION_H
#define UI_SETUPCONNECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetupConnection
{
public:
    QFormLayout *formLayout;
    QLabel *HostName_Label;
    QLineEdit *HostName_Edit;
    QLabel *DBName_Label;
    QLineEdit *DBName_Edit;
    QLabel *UserName_Label;
    QLineEdit *UserName_Edit;
    QLabel *Password_Label;
    QLineEdit *Password_Edit;
    QPushButton *TryConnect_Button;
    QLabel *port_Label;
    QLineEdit *Port_Edit;

    void setupUi(QDialog *SetupConnection)
    {
        if (SetupConnection->objectName().isEmpty())
            SetupConnection->setObjectName(QString::fromUtf8("SetupConnection"));
        SetupConnection->setWindowModality(Qt::ApplicationModal);
        SetupConnection->resize(323, 190);
        formLayout = new QFormLayout(SetupConnection);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        HostName_Label = new QLabel(SetupConnection);
        HostName_Label->setObjectName(QString::fromUtf8("HostName_Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, HostName_Label);

        HostName_Edit = new QLineEdit(SetupConnection);
        HostName_Edit->setObjectName(QString::fromUtf8("HostName_Edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, HostName_Edit);

        DBName_Label = new QLabel(SetupConnection);
        DBName_Label->setObjectName(QString::fromUtf8("DBName_Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, DBName_Label);

        DBName_Edit = new QLineEdit(SetupConnection);
        DBName_Edit->setObjectName(QString::fromUtf8("DBName_Edit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, DBName_Edit);

        UserName_Label = new QLabel(SetupConnection);
        UserName_Label->setObjectName(QString::fromUtf8("UserName_Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, UserName_Label);

        UserName_Edit = new QLineEdit(SetupConnection);
        UserName_Edit->setObjectName(QString::fromUtf8("UserName_Edit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, UserName_Edit);

        Password_Label = new QLabel(SetupConnection);
        Password_Label->setObjectName(QString::fromUtf8("Password_Label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Password_Label);

        Password_Edit = new QLineEdit(SetupConnection);
        Password_Edit->setObjectName(QString::fromUtf8("Password_Edit"));
        Password_Edit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, Password_Edit);

        TryConnect_Button = new QPushButton(SetupConnection);
        TryConnect_Button->setObjectName(QString::fromUtf8("TryConnect_Button"));

        formLayout->setWidget(5, QFormLayout::FieldRole, TryConnect_Button);

        port_Label = new QLabel(SetupConnection);
        port_Label->setObjectName(QString::fromUtf8("port_Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, port_Label);

        Port_Edit = new QLineEdit(SetupConnection);
        Port_Edit->setObjectName(QString::fromUtf8("Port_Edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Port_Edit);


        retranslateUi(SetupConnection);

        QMetaObject::connectSlotsByName(SetupConnection);
    } // setupUi

    void retranslateUi(QDialog *SetupConnection)
    {
        SetupConnection->setWindowTitle(QApplication::translate("SetupConnection", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        HostName_Label->setText(QApplication::translate("SetupConnection", "\320\245\320\276\321\201\321\202:", 0, QApplication::UnicodeUTF8));
        DBName_Label->setText(QApplication::translate("SetupConnection", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205:", 0, QApplication::UnicodeUTF8));
        UserName_Label->setText(QApplication::translate("SetupConnection", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", 0, QApplication::UnicodeUTF8));
        Password_Label->setText(QApplication::translate("SetupConnection", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        Password_Edit->setInputMask(QString());
        TryConnect_Button->setText(QApplication::translate("SetupConnection", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        port_Label->setText(QApplication::translate("SetupConnection", "\320\237\320\276\321\200\321\202:", 0, QApplication::UnicodeUTF8));
        Port_Edit->setText(QApplication::translate("SetupConnection", "5432", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetupConnection: public Ui_SetupConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPCONNECTION_H

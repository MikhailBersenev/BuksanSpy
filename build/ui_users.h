/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Users
{
public:
    QGridLayout *gridLayout;
    QGridLayout *usersTable_Layout;
    QTableView *users_Table;
    QVBoxLayout *ButtonsLayout;
    QPushButton *AddUser_Button;
    QPushButton *DeleteUser_Button;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Users)
    {
        if (Users->objectName().isEmpty())
            Users->setObjectName(QString::fromUtf8("Users"));
        Users->resize(564, 305);
        gridLayout = new QGridLayout(Users);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        usersTable_Layout = new QGridLayout();
        usersTable_Layout->setObjectName(QString::fromUtf8("usersTable_Layout"));
        users_Table = new QTableView(Users);
        users_Table->setObjectName(QString::fromUtf8("users_Table"));
        users_Table->setGridStyle(Qt::SolidLine);
        users_Table->setSortingEnabled(true);
        users_Table->horizontalHeader()->setCascadingSectionResizes(true);
        users_Table->horizontalHeader()->setDefaultSectionSize(200);
        users_Table->horizontalHeader()->setMinimumSectionSize(0);
        users_Table->horizontalHeader()->setStretchLastSection(true);
        users_Table->verticalHeader()->setCascadingSectionResizes(true);

        usersTable_Layout->addWidget(users_Table, 0, 0, 1, 1);


        gridLayout->addLayout(usersTable_Layout, 0, 0, 2, 1);

        ButtonsLayout = new QVBoxLayout();
        ButtonsLayout->setObjectName(QString::fromUtf8("ButtonsLayout"));
        AddUser_Button = new QPushButton(Users);
        AddUser_Button->setObjectName(QString::fromUtf8("AddUser_Button"));

        ButtonsLayout->addWidget(AddUser_Button);

        DeleteUser_Button = new QPushButton(Users);
        DeleteUser_Button->setObjectName(QString::fromUtf8("DeleteUser_Button"));

        ButtonsLayout->addWidget(DeleteUser_Button);


        gridLayout->addLayout(ButtonsLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 234, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(Users);

        QMetaObject::connectSlotsByName(Users);
    } // setupUi

    void retranslateUi(QDialog *Users)
    {
        Users->setWindowTitle(QApplication::translate("Users", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270 \320\270 \320\263\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        AddUser_Button->setText(QApplication::translate("Users", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", 0, QApplication::UnicodeUTF8));
        DeleteUser_Button->setText(QApplication::translate("Users", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Users: public Ui_Users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H

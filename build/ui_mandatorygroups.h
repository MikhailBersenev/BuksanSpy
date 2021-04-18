/********************************************************************************
** Form generated from reading UI file 'mandatorygroups.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANDATORYGROUPS_H
#define UI_MANDATORYGROUPS_H

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

class Ui_MandatoryGroups
{
public:
    QGridLayout *gridLayout;
    QGridLayout *Table_Layout;
    QTableView *MandatoryGroups_Table;
    QVBoxLayout *Buttons_Layout;
    QPushButton *AddMandatoryGroup_Button;
    QPushButton *DeleteMandatoryGroup_Button;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *MandatoryGroups)
    {
        if (MandatoryGroups->objectName().isEmpty())
            MandatoryGroups->setObjectName(QString::fromUtf8("MandatoryGroups"));
        MandatoryGroups->resize(647, 370);
        gridLayout = new QGridLayout(MandatoryGroups);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Table_Layout = new QGridLayout();
        Table_Layout->setObjectName(QString::fromUtf8("Table_Layout"));
        MandatoryGroups_Table = new QTableView(MandatoryGroups);
        MandatoryGroups_Table->setObjectName(QString::fromUtf8("MandatoryGroups_Table"));
        MandatoryGroups_Table->horizontalHeader()->setDefaultSectionSize(250);
        MandatoryGroups_Table->horizontalHeader()->setStretchLastSection(true);

        Table_Layout->addWidget(MandatoryGroups_Table, 0, 0, 1, 1);


        gridLayout->addLayout(Table_Layout, 0, 0, 2, 1);

        Buttons_Layout = new QVBoxLayout();
        Buttons_Layout->setObjectName(QString::fromUtf8("Buttons_Layout"));
        AddMandatoryGroup_Button = new QPushButton(MandatoryGroups);
        AddMandatoryGroup_Button->setObjectName(QString::fromUtf8("AddMandatoryGroup_Button"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddMandatoryGroup_Button->sizePolicy().hasHeightForWidth());
        AddMandatoryGroup_Button->setSizePolicy(sizePolicy);

        Buttons_Layout->addWidget(AddMandatoryGroup_Button);

        DeleteMandatoryGroup_Button = new QPushButton(MandatoryGroups);
        DeleteMandatoryGroup_Button->setObjectName(QString::fromUtf8("DeleteMandatoryGroup_Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DeleteMandatoryGroup_Button->sizePolicy().hasHeightForWidth());
        DeleteMandatoryGroup_Button->setSizePolicy(sizePolicy1);

        Buttons_Layout->addWidget(DeleteMandatoryGroup_Button);


        gridLayout->addLayout(Buttons_Layout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 285, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(MandatoryGroups);

        QMetaObject::connectSlotsByName(MandatoryGroups);
    } // setupUi

    void retranslateUi(QDialog *MandatoryGroups)
    {
        MandatoryGroups->setWindowTitle(QApplication::translate("MandatoryGroups", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\321\213\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        AddMandatoryGroup_Button->setText(QApplication::translate("MandatoryGroups", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        DeleteMandatoryGroup_Button->setText(QApplication::translate("MandatoryGroups", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MandatoryGroups: public Ui_MandatoryGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDATORYGROUPS_H

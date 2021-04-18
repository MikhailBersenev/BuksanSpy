/********************************************************************************
** Form generated from reading UI file 'devices.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICES_H
#define UI_DEVICES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Devices
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *AddDevice_Button;
    QPushButton *DeleteDevice_Button;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGridLayout *devList_Layout;

    void setupUi(QDialog *Devices)
    {
        if (Devices->objectName().isEmpty())
            Devices->setObjectName(QString::fromUtf8("Devices"));
        Devices->resize(559, 319);
        gridLayout_2 = new QGridLayout(Devices);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        AddDevice_Button = new QPushButton(Devices);
        AddDevice_Button->setObjectName(QString::fromUtf8("AddDevice_Button"));

        gridLayout_2->addWidget(AddDevice_Button, 0, 0, 1, 1);

        DeleteDevice_Button = new QPushButton(Devices);
        DeleteDevice_Button->setObjectName(QString::fromUtf8("DeleteDevice_Button"));

        gridLayout_2->addWidget(DeleteDevice_Button, 0, 1, 1, 1);

        groupBox = new QGroupBox(Devices);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        devList_Layout = new QGridLayout();
        devList_Layout->setObjectName(QString::fromUtf8("devList_Layout"));

        gridLayout->addLayout(devList_Layout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);


        retranslateUi(Devices);

        QMetaObject::connectSlotsByName(Devices);
    } // setupUi

    void retranslateUi(QDialog *Devices)
    {
        Devices->setWindowTitle(QApplication::translate("Devices", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        AddDevice_Button->setText(QApplication::translate("Devices", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        DeleteDevice_Button->setText(QApplication::translate("Devices", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Devices", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Devices: public Ui_Devices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICES_H

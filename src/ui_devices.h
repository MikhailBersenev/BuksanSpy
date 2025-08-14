/********************************************************************************
** Form generated from reading UI file 'devices.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICES_H
#define UI_DEVICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

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
            Devices->setObjectName("Devices");
        Devices->resize(559, 319);
        gridLayout_2 = new QGridLayout(Devices);
        gridLayout_2->setObjectName("gridLayout_2");
        AddDevice_Button = new QPushButton(Devices);
        AddDevice_Button->setObjectName("AddDevice_Button");

        gridLayout_2->addWidget(AddDevice_Button, 0, 0, 1, 1);

        DeleteDevice_Button = new QPushButton(Devices);
        DeleteDevice_Button->setObjectName("DeleteDevice_Button");

        gridLayout_2->addWidget(DeleteDevice_Button, 0, 1, 1, 1);

        groupBox = new QGroupBox(Devices);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        devList_Layout = new QGridLayout();
        devList_Layout->setObjectName("devList_Layout");

        gridLayout->addLayout(devList_Layout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);


        retranslateUi(Devices);

        QMetaObject::connectSlotsByName(Devices);
    } // setupUi

    void retranslateUi(QDialog *Devices)
    {
        Devices->setWindowTitle(QCoreApplication::translate("Devices", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        AddDevice_Button->setText(QCoreApplication::translate("Devices", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
        DeleteDevice_Button->setText(QCoreApplication::translate("Devices", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Devices", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Devices: public Ui_Devices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICES_H

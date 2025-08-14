/********************************************************************************
** Form generated from reading UI file 'mandatorymarkcreator.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANDATORYMARKCREATOR_H
#define UI_MANDATORYMARKCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MandatoryMarkCreator
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *name_label;
    QLabel *accesslevel_label;
    QLineEdit *MarkName_lineEdit;
    QSlider *accesslevel_Slider;
    QLabel *Currentposition_label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MandatoryMarkCreator)
    {
        if (MandatoryMarkCreator->objectName().isEmpty())
            MandatoryMarkCreator->setObjectName("MandatoryMarkCreator");
        MandatoryMarkCreator->resize(440, 150);
        MandatoryMarkCreator->setMaximumSize(QSize(440, 150));
        verticalLayout_2 = new QVBoxLayout(MandatoryMarkCreator);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        name_label = new QLabel(MandatoryMarkCreator);
        name_label->setObjectName("name_label");

        formLayout->setWidget(0, QFormLayout::LabelRole, name_label);

        accesslevel_label = new QLabel(MandatoryMarkCreator);
        accesslevel_label->setObjectName("accesslevel_label");

        formLayout->setWidget(1, QFormLayout::LabelRole, accesslevel_label);

        MarkName_lineEdit = new QLineEdit(MandatoryMarkCreator);
        MarkName_lineEdit->setObjectName("MarkName_lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, MarkName_lineEdit);

        accesslevel_Slider = new QSlider(MandatoryMarkCreator);
        accesslevel_Slider->setObjectName("accesslevel_Slider");
        accesslevel_Slider->setAutoFillBackground(false);
        accesslevel_Slider->setValue(99);
        accesslevel_Slider->setOrientation(Qt::Horizontal);
        accesslevel_Slider->setTickPosition(QSlider::TicksBelow);
        accesslevel_Slider->setTickInterval(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, accesslevel_Slider);

        Currentposition_label = new QLabel(MandatoryMarkCreator);
        Currentposition_label->setObjectName("Currentposition_label");

        formLayout->setWidget(2, QFormLayout::FieldRole, Currentposition_label);


        verticalLayout_2->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(MandatoryMarkCreator);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(MandatoryMarkCreator);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MandatoryMarkCreator, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MandatoryMarkCreator, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MandatoryMarkCreator);
    } // setupUi

    void retranslateUi(QDialog *MandatoryMarkCreator)
    {
        MandatoryMarkCreator->setWindowTitle(QCoreApplication::translate("MandatoryMarkCreator", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\274\320\260\320\275\320\264\320\260\321\202\320\275\320\276\320\271 \320\274\320\265\321\202\320\272\320\270", nullptr));
        name_label->setText(QCoreApplication::translate("MandatoryMarkCreator", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        accesslevel_label->setText(QCoreApplication::translate("MandatoryMarkCreator", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\260:", nullptr));
        Currentposition_label->setText(QCoreApplication::translate("MandatoryMarkCreator", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\203\321\200\320\276\320\262\320\265\320\275\321\214 : 99", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MandatoryMarkCreator: public Ui_MandatoryMarkCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDATORYMARKCREATOR_H

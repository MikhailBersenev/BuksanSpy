/********************************************************************************
** Form generated from reading UI file 'mandatorymarkseditor.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANDATORYMARKSEDITOR_H
#define UI_MANDATORYMARKSEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MandatoryMarksEditor
{
public:
    QVBoxLayout *verticalLayout;
    QListView *MandatoryMarks_listView;
    QPushButton *addMandatoryMark_pushButton;
    QPushButton *DeleteMandatoryMark_pushButton;

    void setupUi(QDialog *MandatoryMarksEditor)
    {
        if (MandatoryMarksEditor->objectName().isEmpty())
            MandatoryMarksEditor->setObjectName("MandatoryMarksEditor");
        MandatoryMarksEditor->resize(373, 333);
        verticalLayout = new QVBoxLayout(MandatoryMarksEditor);
        verticalLayout->setObjectName("verticalLayout");
        MandatoryMarks_listView = new QListView(MandatoryMarksEditor);
        MandatoryMarks_listView->setObjectName("MandatoryMarks_listView");

        verticalLayout->addWidget(MandatoryMarks_listView);

        addMandatoryMark_pushButton = new QPushButton(MandatoryMarksEditor);
        addMandatoryMark_pushButton->setObjectName("addMandatoryMark_pushButton");

        verticalLayout->addWidget(addMandatoryMark_pushButton);

        DeleteMandatoryMark_pushButton = new QPushButton(MandatoryMarksEditor);
        DeleteMandatoryMark_pushButton->setObjectName("DeleteMandatoryMark_pushButton");

        verticalLayout->addWidget(DeleteMandatoryMark_pushButton);


        retranslateUi(MandatoryMarksEditor);

        QMetaObject::connectSlotsByName(MandatoryMarksEditor);
    } // setupUi

    void retranslateUi(QDialog *MandatoryMarksEditor)
    {
        MandatoryMarksEditor->setWindowTitle(QCoreApplication::translate("MandatoryMarksEditor", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\274\320\260\320\275\320\264\320\260\321\202\320\275\321\213\321\205 \320\274\320\265\321\202\320\276\320\272", nullptr));
        addMandatoryMark_pushButton->setText(QCoreApplication::translate("MandatoryMarksEditor", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\320\275\320\264\320\260\321\202\320\275\321\203\321\216 \320\274\320\265\321\202\320\272\321\203", nullptr));
        DeleteMandatoryMark_pushButton->setText(QCoreApplication::translate("MandatoryMarksEditor", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\274\320\260\320\275\320\264\320\260\321\202\320\275\321\203\321\216 \320\274\320\265\321\202\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MandatoryMarksEditor: public Ui_MandatoryMarksEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDATORYMARKSEDITOR_H

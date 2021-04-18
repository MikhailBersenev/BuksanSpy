/********************************************************************************
** Form generated from reading UI file 'eventlog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTLOG_H
#define UI_EVENTLOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_eventlog
{
public:
    QGridLayout *gridLayout;
    QTableView *alerts_table;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *StrToSearch_Edit;
    QComboBox *Field_ComboBox;
    QPushButton *TryFind_Button;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *eventlog)
    {
        if (eventlog->objectName().isEmpty())
            eventlog->setObjectName(QString::fromUtf8("eventlog"));
        eventlog->resize(734, 409);
        gridLayout = new QGridLayout(eventlog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        alerts_table = new QTableView(eventlog);
        alerts_table->setObjectName(QString::fromUtf8("alerts_table"));
        alerts_table->setMinimumSize(QSize(551, 391));
        alerts_table->setAutoFillBackground(true);
        alerts_table->horizontalHeader()->setDefaultSectionSize(120);
        alerts_table->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(alerts_table, 0, 0, 2, 1);

        groupBox = new QGroupBox(eventlog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(159, 135));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        StrToSearch_Edit = new QLineEdit(groupBox);
        StrToSearch_Edit->setObjectName(QString::fromUtf8("StrToSearch_Edit"));

        verticalLayout->addWidget(StrToSearch_Edit);

        Field_ComboBox = new QComboBox(groupBox);
        Field_ComboBox->setObjectName(QString::fromUtf8("Field_ComboBox"));

        verticalLayout->addWidget(Field_ComboBox);

        TryFind_Button = new QPushButton(groupBox);
        TryFind_Button->setObjectName(QString::fromUtf8("TryFind_Button"));

        verticalLayout->addWidget(TryFind_Button);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1, Qt::AlignRight);

        verticalSpacer = new QSpacerItem(20, 247, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(eventlog);

        QMetaObject::connectSlotsByName(eventlog);
    } // setupUi

    void retranslateUi(QDialog *eventlog)
    {
        eventlog->setWindowTitle(QApplication::translate("eventlog", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("eventlog", "\320\237\320\276\320\270\321\201\320\272", 0, QApplication::UnicodeUTF8));
        Field_ComboBox->clear();
        Field_ComboBox->insertItems(0, QStringList()
         << QApplication::translate("eventlog", "\320\237\320\276  IP  \320\260\320\264\321\200\320\265\321\201\321\203", 0, QApplication::UnicodeUTF8)
         << QString()
         << QApplication::translate("eventlog", "\320\237\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("eventlog", "\320\237\320\276 \320\264\320\260\321\202\320\265", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("eventlog", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8)
        );
        TryFind_Button->setText(QApplication::translate("eventlog", "\320\235\320\260\320\271\321\202\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class eventlog: public Ui_eventlog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTLOG_H

/********************************************************************************
** Form generated from reading UI file 'eventlog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTLOG_H
#define UI_EVENTLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_eventlog
{
public:
    QGridLayout *gridLayout;
    QTableView *alerts_table;
    QGroupBox *search_groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *StrToSearch_Edit;
    QPushButton *TryFind_Button;
    QGroupBox *sort_groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *sort_comboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *eventlog)
    {
        if (eventlog->objectName().isEmpty())
            eventlog->setObjectName("eventlog");
        eventlog->resize(734, 409);
        gridLayout = new QGridLayout(eventlog);
        gridLayout->setObjectName("gridLayout");
        alerts_table = new QTableView(eventlog);
        alerts_table->setObjectName("alerts_table");
        alerts_table->setMinimumSize(QSize(551, 391));
        alerts_table->setAutoFillBackground(true);
        alerts_table->setSortingEnabled(true);
        alerts_table->horizontalHeader()->setCascadingSectionResizes(true);
        alerts_table->horizontalHeader()->setDefaultSectionSize(120);
        alerts_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        alerts_table->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(alerts_table, 0, 0, 3, 1);

        search_groupBox = new QGroupBox(eventlog);
        search_groupBox->setObjectName("search_groupBox");
        search_groupBox->setMaximumSize(QSize(159, 135));
        search_groupBox->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(search_groupBox);
        verticalLayout->setObjectName("verticalLayout");
        StrToSearch_Edit = new QLineEdit(search_groupBox);
        StrToSearch_Edit->setObjectName("StrToSearch_Edit");

        verticalLayout->addWidget(StrToSearch_Edit);

        TryFind_Button = new QPushButton(search_groupBox);
        TryFind_Button->setObjectName("TryFind_Button");

        verticalLayout->addWidget(TryFind_Button);


        gridLayout->addWidget(search_groupBox, 0, 1, 1, 1);

        sort_groupBox = new QGroupBox(eventlog);
        sort_groupBox->setObjectName("sort_groupBox");
        verticalLayout_2 = new QVBoxLayout(sort_groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        sort_comboBox = new QComboBox(sort_groupBox);
        sort_comboBox->addItem(QString());
        sort_comboBox->addItem(QString());
        sort_comboBox->setObjectName("sort_comboBox");

        verticalLayout_2->addWidget(sort_comboBox);


        gridLayout->addWidget(sort_groupBox, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 247, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(eventlog);

        QMetaObject::connectSlotsByName(eventlog);
    } // setupUi

    void retranslateUi(QDialog *eventlog)
    {
        eventlog->setWindowTitle(QCoreApplication::translate("eventlog", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", nullptr));
        search_groupBox->setTitle(QCoreApplication::translate("eventlog", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        TryFind_Button->setText(QCoreApplication::translate("eventlog", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        sort_groupBox->setTitle(QCoreApplication::translate("eventlog", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        sort_comboBox->setItemText(0, QCoreApplication::translate("eventlog", "\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \320\275\320\276\320\262\321\213\320\265", nullptr));
        sort_comboBox->setItemText(1, QCoreApplication::translate("eventlog", "\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \321\201\321\202\320\260\321\200\321\213\320\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class eventlog: public Ui_eventlog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTLOG_H

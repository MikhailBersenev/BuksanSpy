/********************************************************************************
** Form generated from reading UI file 'buksanspy.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUKSANSPY_H
#define UI_BUKSANSPY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuksanSpy
{
public:
    QAction *StartAllCams_Action;
    QAction *StartCurrentCam_Action;
    QAction *Quit_Action;
    QAction *users_Action;
    QAction *MandatoryGroups_Action;
    QAction *AddDevice_Action;
    QAction *InitCams_action;
    QAction *AddDev_Action;
    QAction *ShowDevList_Action;
    QAction *eventlog_Action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QGridLayout *CamLayout;
    QTabWidget *Cams_TabWidget;
    QWidget *AllCams;
    QWidget *gridLayoutWidget;
    QGridLayout *camslay;
    QWidget *tab;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BuksanSpy)
    {
        if (BuksanSpy->objectName().isEmpty())
            BuksanSpy->setObjectName(QString::fromUtf8("BuksanSpy"));
        BuksanSpy->resize(898, 499);
        StartAllCams_Action = new QAction(BuksanSpy);
        StartAllCams_Action->setObjectName(QString::fromUtf8("StartAllCams_Action"));
        StartCurrentCam_Action = new QAction(BuksanSpy);
        StartCurrentCam_Action->setObjectName(QString::fromUtf8("StartCurrentCam_Action"));
        Quit_Action = new QAction(BuksanSpy);
        Quit_Action->setObjectName(QString::fromUtf8("Quit_Action"));
        users_Action = new QAction(BuksanSpy);
        users_Action->setObjectName(QString::fromUtf8("users_Action"));
        MandatoryGroups_Action = new QAction(BuksanSpy);
        MandatoryGroups_Action->setObjectName(QString::fromUtf8("MandatoryGroups_Action"));
        AddDevice_Action = new QAction(BuksanSpy);
        AddDevice_Action->setObjectName(QString::fromUtf8("AddDevice_Action"));
        InitCams_action = new QAction(BuksanSpy);
        InitCams_action->setObjectName(QString::fromUtf8("InitCams_action"));
        AddDev_Action = new QAction(BuksanSpy);
        AddDev_Action->setObjectName(QString::fromUtf8("AddDev_Action"));
        ShowDevList_Action = new QAction(BuksanSpy);
        ShowDevList_Action->setObjectName(QString::fromUtf8("ShowDevList_Action"));
        eventlog_Action = new QAction(BuksanSpy);
        eventlog_Action->setObjectName(QString::fromUtf8("eventlog_Action"));
        centralwidget = new QWidget(BuksanSpy);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font;
        font.setPointSize(14);
        pushButton_2->setFont(font);
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        CamLayout = new QGridLayout();
        CamLayout->setObjectName(QString::fromUtf8("CamLayout"));
        Cams_TabWidget = new QTabWidget(centralwidget);
        Cams_TabWidget->setObjectName(QString::fromUtf8("Cams_TabWidget"));
        AllCams = new QWidget();
        AllCams->setObjectName(QString::fromUtf8("AllCams"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AllCams->sizePolicy().hasHeightForWidth());
        AllCams->setSizePolicy(sizePolicy);
        AllCams->setMinimumSize(QSize(0, 0));
        gridLayoutWidget = new QWidget(AllCams);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 651, 401));
        camslay = new QGridLayout(gridLayoutWidget);
        camslay->setObjectName(QString::fromUtf8("camslay"));
        camslay->setContentsMargins(0, 0, 0, 0);
        Cams_TabWidget->addTab(AllCams, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        Cams_TabWidget->addTab(tab, QString());

        CamLayout->addWidget(Cams_TabWidget, 0, 0, 1, 1);


        gridLayout->addLayout(CamLayout, 0, 1, 6, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);
        pushButton_3->setFlat(false);

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        BuksanSpy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BuksanSpy);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 898, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menu_3);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        BuksanSpy->setMenuBar(menubar);
        statusbar = new QStatusBar(BuksanSpy);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BuksanSpy->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(InitCams_action);
        menu->addAction(StartAllCams_Action);
        menu->addAction(StartCurrentCam_Action);
        menu->addAction(Quit_Action);
        menu_3->addSeparator();
        menu_3->addAction(menu_4->menuAction());
        menu_3->addSeparator();
        menu_3->addAction(menu_5->menuAction());
        menu_3->addAction(eventlog_Action);
        menu_4->addAction(users_Action);
        menu_4->addAction(MandatoryGroups_Action);
        menu_5->addAction(ShowDevList_Action);

        retranslateUi(BuksanSpy);

        Cams_TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BuksanSpy);
    } // setupUi

    void retranslateUi(QMainWindow *BuksanSpy)
    {
        BuksanSpy->setWindowTitle(QApplication::translate("BuksanSpy", "BuksanSpy", 0, QApplication::UnicodeUTF8));
        StartAllCams_Action->setText(QApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \321\201\320\276 \320\262\321\201\320\265\321\205 \320\272\320\260\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        StartAllCams_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+A", 0, QApplication::UnicodeUTF8));
        StartCurrentCam_Action->setText(QApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \321\201 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\272\320\260\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        StartCurrentCam_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+C", 0, QApplication::UnicodeUTF8));
        Quit_Action->setText(QApplication::translate("BuksanSpy", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        Quit_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+Q", 0, QApplication::UnicodeUTF8));
        users_Action->setText(QApplication::translate("BuksanSpy", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", 0, QApplication::UnicodeUTF8));
        users_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+U", 0, QApplication::UnicodeUTF8));
        MandatoryGroups_Action->setText(QApplication::translate("BuksanSpy", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\321\213\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        MandatoryGroups_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+M", 0, QApplication::UnicodeUTF8));
        AddDevice_Action->setText(QApplication::translate("BuksanSpy", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        InitCams_action->setText(QApplication::translate("BuksanSpy", "\320\230\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        InitCams_action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+I", 0, QApplication::UnicodeUTF8));
        AddDev_Action->setText(QApplication::translate("BuksanSpy", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        AddDev_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+N", 0, QApplication::UnicodeUTF8));
        ShowDevList_Action->setText(QApplication::translate("BuksanSpy", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", 0, QApplication::UnicodeUTF8));
        ShowDevList_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        eventlog_Action->setText(QApplication::translate("BuksanSpy", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", 0, QApplication::UnicodeUTF8));
        eventlog_Action->setShortcut(QApplication::translate("BuksanSpy", "Ctrl+Shift+L", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \n"
" \321\201\320\276 \320\262\321\201\320\265\321\205 \320\272\320\260\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        Cams_TabWidget->setTabText(Cams_TabWidget->indexOf(AllCams), QApplication::translate("BuksanSpy", "\320\222\321\201\320\265", 0, QApplication::UnicodeUTF8));
        Cams_TabWidget->setTabText(Cams_TabWidget->indexOf(tab), QApplication::translate("BuksanSpy", "Page", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \n"
" \321\201 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\272\320\260\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("BuksanSpy", "\320\226\321\203\321\200\320\275\320\260\320\273", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("BuksanSpy", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("BuksanSpy", "\320\222\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\270", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("BuksanSpy", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("BuksanSpy", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270 \320\270 \320\263\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        menu_5->setTitle(QApplication::translate("BuksanSpy", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BuksanSpy: public Ui_BuksanSpy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUKSANSPY_H

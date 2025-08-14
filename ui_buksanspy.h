/********************************************************************************
** Form generated from reading UI file 'buksanspy.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUKSANSPY_H
#define UI_BUKSANSPY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

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
    QAction *action_help;
    QAction *action_Qt;
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
    QToolButton *toolButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BuksanSpy)
    {
        if (BuksanSpy->objectName().isEmpty())
            BuksanSpy->setObjectName("BuksanSpy");
        BuksanSpy->resize(898, 499);
        StartAllCams_Action = new QAction(BuksanSpy);
        StartAllCams_Action->setObjectName("StartAllCams_Action");
        StartCurrentCam_Action = new QAction(BuksanSpy);
        StartCurrentCam_Action->setObjectName("StartCurrentCam_Action");
        Quit_Action = new QAction(BuksanSpy);
        Quit_Action->setObjectName("Quit_Action");
        users_Action = new QAction(BuksanSpy);
        users_Action->setObjectName("users_Action");
        MandatoryGroups_Action = new QAction(BuksanSpy);
        MandatoryGroups_Action->setObjectName("MandatoryGroups_Action");
        AddDevice_Action = new QAction(BuksanSpy);
        AddDevice_Action->setObjectName("AddDevice_Action");
        InitCams_action = new QAction(BuksanSpy);
        InitCams_action->setObjectName("InitCams_action");
        AddDev_Action = new QAction(BuksanSpy);
        AddDev_Action->setObjectName("AddDev_Action");
        ShowDevList_Action = new QAction(BuksanSpy);
        ShowDevList_Action->setObjectName("ShowDevList_Action");
        eventlog_Action = new QAction(BuksanSpy);
        eventlog_Action->setObjectName("eventlog_Action");
        action_help = new QAction(BuksanSpy);
        action_help->setObjectName("action_help");
        action_Qt = new QAction(BuksanSpy);
        action_Qt->setObjectName("action_Qt");
        centralwidget = new QWidget(BuksanSpy);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        QFont font;
        font.setPointSize(14);
        pushButton_2->setFont(font);
        pushButton_2->setContextMenuPolicy(Qt::ActionsContextMenu);
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        CamLayout = new QGridLayout();
        CamLayout->setObjectName("CamLayout");
        Cams_TabWidget = new QTabWidget(centralwidget);
        Cams_TabWidget->setObjectName("Cams_TabWidget");
        AllCams = new QWidget();
        AllCams->setObjectName("AllCams");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AllCams->sizePolicy().hasHeightForWidth());
        AllCams->setSizePolicy(sizePolicy);
        AllCams->setMinimumSize(QSize(0, 0));
        gridLayoutWidget = new QWidget(AllCams);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 651, 401));
        camslay = new QGridLayout(gridLayoutWidget);
        camslay->setObjectName("camslay");
        camslay->setContentsMargins(0, 0, 0, 0);
        Cams_TabWidget->addTab(AllCams, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        Cams_TabWidget->addTab(tab, QString());

        CamLayout->addWidget(Cams_TabWidget, 0, 0, 1, 1);


        gridLayout->addLayout(CamLayout, 0, 1, 7, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setFont(font);
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setFont(font);
        pushButton_3->setFlat(false);

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/c8c21a9023c8c0ac8fa47b36403fdf1a.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon);

        gridLayout->addWidget(toolButton, 5, 0, 1, 1);

        BuksanSpy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BuksanSpy);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 898, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menu_3);
        menu_5->setObjectName("menu_5");
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName("menu_6");
        BuksanSpy->setMenuBar(menubar);
        statusbar = new QStatusBar(BuksanSpy);
        statusbar->setObjectName("statusbar");
        BuksanSpy->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_6->menuAction());
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
        menu_5->addAction(ShowDevList_Action);
        menu_6->addAction(action_help);
        menu_6->addAction(action_Qt);

        retranslateUi(BuksanSpy);

        Cams_TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BuksanSpy);
    } // setupUi

    void retranslateUi(QMainWindow *BuksanSpy)
    {
        BuksanSpy->setWindowTitle(QCoreApplication::translate("BuksanSpy", "BuksanSpy", nullptr));
        StartAllCams_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \321\201\320\276 \320\262\321\201\320\265\321\205 \320\272\320\260\320\274\320\265\321\200", nullptr));
#if QT_CONFIG(shortcut)
        StartAllCams_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        StartCurrentCam_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \321\201 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
#if QT_CONFIG(shortcut)
        StartCurrentCam_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        Quit_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
#if QT_CONFIG(shortcut)
        Quit_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        users_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
#if QT_CONFIG(shortcut)
        users_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+U", nullptr));
#endif // QT_CONFIG(shortcut)
        MandatoryGroups_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\321\213\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
#if QT_CONFIG(shortcut)
        MandatoryGroups_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+M", nullptr));
#endif // QT_CONFIG(shortcut)
        AddDevice_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
        InitCams_action->setText(QCoreApplication::translate("BuksanSpy", "\320\230\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
#if QT_CONFIG(shortcut)
        InitCams_action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+I", nullptr));
#endif // QT_CONFIG(shortcut)
        AddDev_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
#if QT_CONFIG(shortcut)
        AddDev_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        ShowDevList_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", nullptr));
#if QT_CONFIG(shortcut)
        ShowDevList_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        eventlog_Action->setText(QCoreApplication::translate("BuksanSpy", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", nullptr));
#if QT_CONFIG(shortcut)
        eventlog_Action->setShortcut(QCoreApplication::translate("BuksanSpy", "Ctrl+Shift+L", nullptr));
#endif // QT_CONFIG(shortcut)
        action_help->setText(QCoreApplication::translate("BuksanSpy", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        action_Qt->setText(QCoreApplication::translate("BuksanSpy", "\320\236 Qt", nullptr));
        pushButton_2->setText(QCoreApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \n"
" \321\201\320\276 \320\262\321\201\320\265\321\205 \320\272\320\260\320\274\320\265\321\200", nullptr));
        Cams_TabWidget->setTabText(Cams_TabWidget->indexOf(AllCams), QCoreApplication::translate("BuksanSpy", "\320\222\321\201\320\265", nullptr));
        Cams_TabWidget->setTabText(Cams_TabWidget->indexOf(tab), QCoreApplication::translate("BuksanSpy", "Page", nullptr));
        pushButton_4->setText(QCoreApplication::translate("BuksanSpy", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214 \n"
" \321\201 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("BuksanSpy", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
        toolButton->setText(QCoreApplication::translate("BuksanSpy", "Dowload linuc", nullptr));
        menu->setTitle(QCoreApplication::translate("BuksanSpy", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("BuksanSpy", "\320\222\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        menu_3->setTitle(QCoreApplication::translate("BuksanSpy", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        menu_4->setTitle(QCoreApplication::translate("BuksanSpy", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270 \320\270 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        menu_5->setTitle(QCoreApplication::translate("BuksanSpy", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        menu_6->setTitle(QCoreApplication::translate("BuksanSpy", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuksanSpy: public Ui_BuksanSpy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUKSANSPY_H

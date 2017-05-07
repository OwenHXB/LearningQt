/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Close;
    QAction *action_Save;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *action_Undo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Paste;
    QAction *action_Find;
    QAction *action_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(831, 402);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/myimages/actions/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myimages/actions/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Close = new QAction(MainWindow);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/myimages/actions/gtk-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Close->setIcon(icon2);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/myimages/actions/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon3);
        action_SaveAs = new QAction(MainWindow);
        action_SaveAs->setObjectName(QStringLiteral("action_SaveAs"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/myimages/actions/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveAs->setIcon(icon4);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/myimages/actions/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon5);
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/myimages/actions/edit-undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Undo->setIcon(icon6);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/myimages/actions/edit-cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon7);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/myimages/actions/edit-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon8);
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QStringLiteral("action_Paste"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/myimages/actions/edit-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Paste->setIcon(icon9);
        action_Find = new QAction(MainWindow);
        action_Find->setObjectName(QStringLiteral("action_Find"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/myimages/actions/edit-find.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Find->setIcon(icon10);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/myimages/actions/help-contents.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 831, 28));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(action_New);
        menu_F->addAction(action_Open);
        menu_F->addAction(action_Close);
        menu_F->addAction(action_Save);
        menu_F->addAction(action_SaveAs);
        menu_F->addAction(action_Exit);
        menu_E->addAction(action_Undo);
        menu_E->addAction(action_Cut);
        menu_E->addAction(action_Copy);
        menu_E->addAction(action_Paste);
        menu_E->addAction(action_Find);
        menu_H->addAction(action_2);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Undo);
        mainToolBar->addAction(action_Cut);
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(action_Paste);
        mainToolBar->addAction(action_Find);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", 0));
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", 0));
        action_Close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(C)", 0));
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", 0));
        action_SaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(A)", 0));
        action_Exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(X)", 0));
        action_Undo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(Z)", 0));
        action_Cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(X)", 0));
        action_Copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", 0));
        action_Paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(V)", 0));
        action_Find->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276(F)", 0));
        action_2->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\350\257\264\346\230\216", 0));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", 0));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", 0));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *openAction = new QAction(tr("&Open"), this);

    QIcon icon(":/myimages/actions/fileopen.png");
    openAction->setIcon(icon);
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));

    ui->menuFile_F->addAction(openAction);

    QMenu *menu_E = ui->menuBar->addMenu(tr("Edit(&E)"));
    QAction *findAction = new QAction(tr("&Find"), this);

    QIcon icon2(":/myimages/actions/find.png");
    findAction->setIcon(icon2);
    findAction->setShortcut(QKeySequence(tr("&Ctrl+F")));
//    findAction->setShortcut(QKeySequence::Open);
    menu_E->addAction(findAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

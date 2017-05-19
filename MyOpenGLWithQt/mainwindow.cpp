#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("HELLO OPENGL");
    setGeometry(0,0,640,480);
    connect(ui->OpenFileButton, SIGNAL(clicked()), ui->widget, SLOT(openFile()));
    ui->widget->setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *)
{
//    qDebug() << "MainWindow";
}

void MainWindow::keyPressEvent(QKeyEvent *)
{
    qDebug() << "MainWindow";
}

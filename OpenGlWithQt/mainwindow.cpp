#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Hello OpenGL");
    setGeometry(300,300,500,500);
    connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->xRotSlider,SLOT(setValue(int)) );
    connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->zRotSlider,SLOT(setValue(int)) );
    connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->yRotSlider,SLOT(setValue(int)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * e)
{
    switch (e->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Hello OpenGL");
    setGeometry(0,0,500,500);
    ui->MyGLWidget->size().height();
    ui->MyGLWidget->size().width();
}

MainWindow::~MainWindow()
{
    delete ui;
}

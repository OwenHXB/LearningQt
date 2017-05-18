#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("HELLO OPENGL");
    setGeometry(0,0,640,480);
    connect(ui->OpenFileButton, SIGNAL(clicked()), ui->widget, SLOT(openFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

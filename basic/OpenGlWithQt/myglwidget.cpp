#include "myglwidget.h"
#include "ui_myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyGLWidget)
{
    ui->setupUi(this);
}

MyGLWidget::~MyGLWidget()
{
    delete ui;
}

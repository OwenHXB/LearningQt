#include "myglwidget.h"

#include <QtOpenGL>
#include <QtWidgets>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QTimerEvent>
#include <QDebug>

MyGLWidget::MyGLWidget(QWidget *parent)
    :
//      QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
      QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
    startTimer(100);
    xRot = 0;
    yRot = 0;
    zRot = 0;
}


void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MyGLWidget::resizeGL(int width, int height)
{

//    qDebug() << width << height;
    int side = qMin(width, height);
    glViewport((width - side)/2, (height - side)/2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

//void MyGLWidget::keyPressEvent(QKeyEvent *event)
//{
//    switch (event->key()) {
//    case Qt::Key_Escape:
//        close();
//        break;
//    default:
//        break;
//    }
//}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if(event->buttons() & Qt::LeftButton){
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);

    }
    else if(event->buttons() & Qt::RightButton){
        setXRotation(xRot + 8 * dy);
        setYRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint point = event->pos();
    qDebug() << point.x() << point.y();

   if(event->delta() > 0){
      qDebug() << "forward" ;
   }
   else {
      qDebug() << "back" ;
   }
}

//void MyGLWidget::mouseDoubleClickEvent(QMouseEvent *event)
//{

//}

void MyGLWidget::timerEvent(QTimerEvent *event)
{
//    qDebug() << "hello hujianjun";
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

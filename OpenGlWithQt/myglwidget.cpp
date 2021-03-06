#include "myglwidget.h"

#include <QtOpenGL>
#include <QtWidgets>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QTimerEvent>
#include <QDebug>

static GLfloat lightPosition[4] = {0, 0, 10, 1.0};

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
    zoom = -10;
}


void MyGLWidget::initializeGL()
{
//    qglClearColor(Qt::black);
    glClearColor(0.2,0.2,0.2,0.2);
    glShadeModel(GL_SMOOTH); //  阴影平滑
    glClearDepth(5.0);//设置深度缓存;
    glEnable(GL_DEPTH_TEST); // 启用深度 test
    glDepthFunc(GL_LEQUAL); //深度测试的类型
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); //真正精细的透视修正
    glHint(GL_LINE_SMOOTH, GL_NICEST); // ju chi
    glEnable(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_LIGHTING);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, zoom);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
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
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint point = event->pos();

   if(event->delta() > 0){
       zoom += 0.2;
//       qDebug() << event->delta();
   }
   else {
//       qDebug() << event->delta();
       zoom -= 0.2;
   }
       updateGL();
}

//void MyGLWidget::mouseDoubleClickEvent(QMouseEvent *event)
//{

//}

void MyGLWidget::timerEvent(QTimerEvent *event)
{
//    updateGL();
//    qDebug() << zoom;
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
//        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
//        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
//        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::draw()
{
    qglColor(Qt::blue);
    glBegin(GL_QUADS);
    glNormal3f(0,0,-1);
        glVertex3f(-1,-1,0);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glNormal3f(0, -1.0, 0.707);
        glVertex3f(-1, -1, 0);
        glVertex3f(1, -1, 0);
        glVertex3f(0, 0, 1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(1,0, 0.707);
        glVertex3f(1,-1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1,0,0.707);
        glVertex3f(-1,1,0);
        glVertex3f(-1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
}

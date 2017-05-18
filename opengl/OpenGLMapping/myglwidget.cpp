#include "myglwidget.h"
#include <GL/glu.h>
#include <QDebug>

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
//    startTimer(5);
//    points[NUM][NUM][3] = {0};
}

//void MyGLWidget::initializeGL()
//{
//    glShadeModel( GL_SMOOTH);
//    glClearColor(0.2, 0.2, 0.2, 0.0);
//    glClearDepth(1.0);
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//    glEnable(GL_LINE_SMOOTH);
//    glHint(GL_LINE_SMOOTH, GL_NICEST);

//    glPolygonMode(GL_BACK, GL_LINE);
//    glPolygonMode(GL_FRONT, GL_LINE);

//    for (int x = 0; x < NUM; x++) {
//        for (int y = 0; y < NUM; y++) {
//            points[x][y][0] = float( x - NUM/2 );
//            points[x][y][1] = float( y - NUM/2 );
//            points[x][y][2] = 0.0;
//        }
//    }

//}

//void MyGLWidget::paintGL()
//{
//    qDebug() << "paintGL";
//    int x,y;
//    float float_x, float_y, float_xb, float_yb;
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//}

//void MyGLWidget::resizeGL(int width, int height)
//{
//    if (height == 0) {
//        height = 1;
//    }
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}

//void MyGLWidget::timerEvent(QTimerEvent *)
//{

//}

//void MyGLWidget::mouseMoveEvent(QMouseEvent *)
//{

//}

//void MyGLWidget::mousePressEvent(QMouseEvent *)
//{

//}

//void MyGLWidget::mouseReleaseEvent(QMouseEvent *)
//{

//}

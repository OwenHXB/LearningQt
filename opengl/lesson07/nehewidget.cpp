/*

    Qt OpenGL Tutorial - Lesson 01

    nehewidget.cpp
    v 1.00
    2002/12/05

    Copyright (C) 2002 Cavendish
                       cavendish@qiliang.net
                       http://www.qiliang.net/nehe_qt

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

*/

#include "nehewidget.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <GL/glu.h>

GLfloat lightAmbient[4] = {0.5, 0.5, 0.5, 1.0};
GLfloat lightDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat lightPosition[4] = {0.0, 0.0, 2.0, 1.0};

NeHeWidget::NeHeWidget( QWidget* parent, const QGLWidget* name, bool fs )
    : QGLWidget( parent, name )
{
    xRot = yRot = zRot = 0.0;
    zoom = -5.0;
    xSpeed = ySpeed = 0.0;
    filter = 0;
    light = false;
    fullscreen = fs; // status of fullscreen
    setGeometry( 0, 0, 640, 480 ); // location of the window, start point(0,0) end point(640, 480)
    //  setCaption( "NeHe's OpenGL Framework" );
    setWindowTitle("NeHe's OpenGL FrameWork"); // name of the window

    if ( fullscreen )
        showFullScreen(); // show full screen

    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()),this, SLOT(paintGL()));
    timer->start(1000);
}

NeHeWidget::~NeHeWidget()
{
}

/*
 *
 *
 */
void NeHeWidget::initializeGL()
{
    loadGLTextures();
    glEnable(GL_TEXTURE_2D);
    glShadeModel( GL_SMOOTH ); // smooth shading
    glClearColor( 0.0, 0.0, 0.0, 0.0 ); //clear the screen color
    glClearDepth( 1.0 ); // depth  设置深度缓存
    glEnable( GL_DEPTH_TEST ); // 启用深度测试
    glDepthFunc( GL_LEQUAL );//所作深度测试的类型。
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );//真正精细的透视修正

    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);

    glEnable(GL_LIGHT1);
}

void NeHeWidget::paintGL()
{
    qDebug() << "hello";
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); //清楚屏幕和深度缓存
  glLoadIdentity(); //重置当前的模型观察矩阵
  glTranslatef(0.0, 0.0, zoom);

  glRotatef(xRot, 1.0, 0.0, 0.0);
  glRotatef(yRot, 0.0, 1.0, 0.0);
  glRotatef(zRot, 0.0, 0.0, 1.0);

  glBindTexture(GL_TEXTURE_2D, texture[filter]);

  glBegin(GL_QUADS);
    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
    glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );

    glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
    glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );

    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0,  1.0,  1.0 );
    glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0,  1.0,  1.0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );

    glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0, -1.0, -1.0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0, -1.0, -1.0 );
    glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
    glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );

    glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
    glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );

    glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
    glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
    glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
    glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
  glEnd();

  xRot += xSpeed;
  yRot += ySpeed;
  zRot += 0.4;
}

void NeHeWidget::resizeGL( int width, int height )
{
  if ( height == 0 )
  {
    height = 1;
  }
  glViewport( 0, 0, (GLint)width, (GLint)height ); //重置当前的视口（Viewport）
  glMatrixMode( GL_PROJECTION );//选择投影矩阵
  glLoadIdentity();//重置投影矩阵
  gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );//建立透视投影矩阵
  glMatrixMode( GL_MODELVIEW );//选择模型观察矩阵
  glLoadIdentity();//重置模型观察矩阵
}

void NeHeWidget::keyPressEvent( QKeyEvent *e )
{
  switch ( e->key() )
  {
  case Qt::Key_L:
      light = !light;
      if(!light){
         glDisable(GL_LIGHTING);
      }
      else {
          glEnable(GL_LIGHTING);
      }
      updateGL();
      break;

  case Qt::Key_F:
      filter += 1;
      if(filter > 2){
          filter = 0;
      }
      updateGL();
      break;
  case Qt::Key_PageUp:
      zoom -= 0.2;
      updateGL();
      break;
  case Qt::Key_PageDown:
      zoom += 0.2;
      updateGL();
      break;
  case Qt::Key_Up:
      xSpeed -= 0.01;
      updateGL();
      break;
  case Qt::Key_Down:
      xSpeed += 0.01;
      updateGL();
      break;
  case Qt::Key_Right:
      ySpeed += 0.01;
      updateGL();
      break;
  case Qt::Key_Left:
      ySpeed -= 0.01;
      updateGL();
      break;
  case Qt::Key_F2:
    fullscreen = !fullscreen;
    if ( fullscreen )
    {
      showFullScreen();
    }
    else
    {
      showNormal();
      setGeometry( 0, 0, 640, 480 );
    }
    updateGL();
    break;
  case Qt::Key_Escape:
    close();
  }
}

void NeHeWidget::loadGLTextures()
{
    QImage tex, buf;
if(!buf.load("./data/Crate.bmp"))    {
    qWarning("Could not read image file, using single-color instead.");
    QImage dummy(128, 128, QImage::Format_RGB32);
    dummy.fill(Qt::green);
    buf = dummy;
}
tex = QGLWidget::convertToGLFormat(buf);
glGenTextures(3, &texture[0]);
//glGenTextures(1, texture);
glBindTexture(GL_TEXTURE_2D, texture[0]);
glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

glBindTexture(GL_TEXTURE_2D, texture[1]);
glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

glBindTexture( GL_TEXTURE_2D, texture[2] );
glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, tex.width(), tex.height(), GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
}

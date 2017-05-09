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
#include <GL/glu.h>

NeHeWidget::NeHeWidget( QWidget* parent, const QGLWidget* name, bool fs )
    : QGLWidget( parent, name )
{
  fullscreen = fs; // status of fullscreen
  setGeometry( 0, 0, 640, 480 ); // location of the window, start point(0,0) end point(640, 480)
//  setCaption( "NeHe's OpenGL Framework" );
  setWindowTitle("NeHe's OpenGL FrameWork"); // name of the window

  if ( fullscreen )
    showFullScreen(); // show full screen
}

NeHeWidget::~NeHeWidget()
{
}

/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
void NeHeWidget::initializeGL()
{
  glShadeModel( GL_SMOOTH ); // smooth shading
  glClearColor( 0.0, 0.0, 0.0, 0.0 ); //clear the screen color
  glClearDepth( 1.0 ); // depth  设置深度缓存
  glEnable( GL_DEPTH_TEST ); // 启用深度测试
  glDepthFunc( GL_LEQUAL );//所作深度测试的类型。
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );//真正精细的透视修正
}

void NeHeWidget::paintGL()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); //清楚屏幕和深度缓存
  glLoadIdentity(); //重置当前的模型观察矩阵
//  glTranslatef(-1.5, 0.0, -6.0); // 沿着 X, Y 和 Z 轴移动
  glTranslatef(-1.5, 0.0, -10.0); // 沿着 X, Y 和 Z 轴移动

  glBegin(GL_TRIANGLES); // begin draw triangles
  glVertex3f(0.0, 1.0, 2.0);
  glVertex3f(-1.0, -1.0, -2.0);
  glVertex3f(0.0, -1.0, 0.0);
  glEnd();// draw triangles finish

  glTranslatef(  3.0,  0.0,  0.0 );
  glBegin(GL_QUADS);// begin draw quads
  glVertex3f(-1.0, 1.0, 0.0); // left up
  glVertex3f(1.0, 1.0, 0.0);  // right up
  glVertex3f(1.0, -1.0, 0.0); // right down
  glVertex3f(-1.0, -1.0, 0.0); // left down
  glEnd();// draw quads finish


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

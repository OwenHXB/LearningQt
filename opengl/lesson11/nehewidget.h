/*

    Qt OpenGL Tutorial - Lesson 01

    nehewidget.h
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

#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <qgl.h>

class NeHeWidget : public QGLWidget
{
    Q_OBJECT

public:
    
  NeHeWidget(QWidget* parent = 0, const QGLWidget *name = 0, bool fs = false );
  ~NeHeWidget();

 public slots:

protected:

  void initializeGL();
  void resizeGL( int width, int height );
  void paintGL();
  void keyPressEvent( QKeyEvent *e );
  void loadGLTextures();
  void timerEvent(QTimerEvent *);
//  void hello();

protected:

  bool fullscreen;
  GLfloat xRot, yRot, zRot;
  GLfloat hold;
  GLuint texture[1];

  float points[45][45][3];
  int wiggle_count;
};

#endif//NEHEWIDGET_H

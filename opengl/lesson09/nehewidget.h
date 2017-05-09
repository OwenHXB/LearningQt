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


const GLuint num = 50;

typedef struct {
    int r, g, b;
    GLfloat dist;
    GLfloat angle;
} stars;

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
  GLfloat zoom; // star distance to watcher
  GLfloat tilt; // the qingjiao of the star
  GLfloat spin; // zhi zhuan of the star
  GLuint loop; //
  GLuint texture[1];

  bool twinkle; // star shan shuo

  stars star[num];
  GLfloat xSpeed, ySpeed;
  GLuint filter;
  bool light;
  bool blend;
};

#endif//NEHEWIDGET_H

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    MyGLWidget(QWidget *parent = 0);

protected:
void initializeGL();
void paintGL();
void resizeGL(int width, int height);



//void keyPressEvent(QKeyEvent *event);
void mousePressEvent(QMouseEvent *);
void mouseMoveEvent(QMouseEvent *);
void wheelEvent(QWheelEvent *);
//void mouseDoubleClickEvent(QMouseEvent *event);
void timerEvent(QTimerEvent *event);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
private:
    void draw();

    int xRot;
    int yRot;
    int zRot;
    GLfloat zoom;
    QPoint lastPos;
};

#endif // MYGLWIDGET_H

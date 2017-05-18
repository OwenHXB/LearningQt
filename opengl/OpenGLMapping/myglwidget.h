#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QTimerEvent>
#include <QMouseEvent>

#define NUM 10

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);

signals:

public slots:
//protected:
//    void initializeGL();
//    void paintGL();
//    void resizeGL(int, int);
//    void timerEvent(QTimerEvent *);
//    void mouseMoveEvent(QMouseEvent *);
//    void mousePressEvent(QMouseEvent *);
//    void mouseReleaseEvent(QMouseEvent *);
//private:
//    float points[NUM][NUM][3];
};

#endif // MYGLWIDGET_H

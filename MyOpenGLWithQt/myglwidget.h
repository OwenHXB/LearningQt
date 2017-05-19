#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H


#include <QGLWidget>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QWheelEvent>

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#define NUM 10


struct MapInfo {
    struct Header {
       int seq;
       struct Stamp{
           long long secs;
           long long nsecs;
       }stamp;
       QString frame_id;
    }header;
    struct Info {
       struct Map_Load_Time{
           int secs;
           int nsecs;
       }map_load_time;
       double resolution;
       int width;
       int height;
       struct Origin{
           struct Position{
               double x;
               double y;
               double z;
           }position;
           struct Orientation{
              double x;
              double y;
              double z;
              double w;
           }orientation;
       }origin;
    }info;
//    int data[][];
    int **data;
};

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);

signals:

public slots:
    void openFile();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int, int);
    void timerEvent(QTimerEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);
    void keyPressEvent(QKeyEvent *);

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setXTranslation(int distance);
    void setYTranslation(int distance);
    void setZTranslation(int distance);
private:
    float points[NUM][NUM][3];
    GLfloat zoom;
    GLfloat xRot, yRot, zRot;
    GLfloat xTrans, yTrans, zTrans;
    QPoint lastPos;
    MapInfo *mapinfo;
    GLfloat enlarge;

    bool MidButtonPressed; // 鼠标 midbutton pressed

    void getMapInfoFromFile(QTextStream &);

    void printMapInfo(MapInfo *);
};

#endif // MYGLWIDGET_H

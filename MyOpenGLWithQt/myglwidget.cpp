#include "myglwidget.h"
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <QDebug>
#include <QMap>
#include <QStringList>
#include <QString>
#include <qtconcurrentmap.h>
#include <iostream>
#include <QList>
#include <string>

int ccc(const QString &str)
{
    return std::stoi(str.toStdString());
}

GLfloat lightAmbient[4] = {0.5, 0.5, 0.5, 1.0};
GLfloat lightDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat lightPosition[4] = {0.0, 0.0, 2.0, 1.0};



static void qNormalizaAngle(int &angle) {
    while(angle < 0){
        angle += 360 * 16;
    }
    while (angle > 360) {
       angle -= 360 * 16;
    }
//    if(angle > 180) {
//        angle = angle - 360;
//    }
//    if(angle < -180) {
//        angle = angle + 360;
//    }
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent),
    zoom(-12.0),
    xRot(0.0),yRot(0.0),zRot(0.0),
    xTrans(0.0),yTrans(0.0),zTrans(0.0),
    lastPos(0,0),
    MidButtonPressed(false),
    enlarge(1.0)
{
    mapinfo = new MapInfo();
    startTimer(5);
    points[NUM][NUM][3] = {0};

}

void MyGLWidget::initializeGL()
{
    glShadeModel( GL_SMOOTH);
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE); //抗锯齿

//    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
//    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
//    glEnable(GL_LIGHT1);

//    glEnable(GL_LIGHTING);


//    glPolygonMode(GL_BACK, GL_FILL);
//    glPolygonMode(GL_FRONT, GL_FILL);

    for (int x = 0; x < NUM; x++) {
        for (int y = 0; y < NUM; y++) {
            points[x][y][0] = float( x - NUM/2 );
            points[x][y][1] = float( y - NUM/2 );
            points[x][y][2] = 0.0;
        }
    }

}

void MyGLWidget::paintGL()
{
    int x,y;
//    float float_x, float_y, float_xb, float_yb;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(xTrans, yTrans, -10);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    glEnable(GL_MULTISAMPLE); //抗锯齿
//    glColor3f(0.0, 0.0, 0.0);
    glColor3f(0.7, 0.7, 0.7);
//    qglColor(Qt::black);

    glPolygonMode(GL_BACK, GL_LINE);
    glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_QUADS);
        for(x = 0; x < NUM - 1; x++) {
            for(y = 0; y < NUM - 1; y++){
//                float_x = float(x)/(NUM - 1.0);
//                float_y = float(y)/(NUM - 1.0);
//                float_xb = float(x + 1)/(NUM - 1.0);
//                float_yb = float(y + 1)/(NUM - 1.0);

//                glTexCoord2d(float_x, float_y);
                glVertex3f(points[x][y][0] * enlarge, points[x][y][1] * enlarge, points[x][y][2] * enlarge);

//                glTexCoord2d(float_x, float_yb);
                glVertex3f(points[x][y + 1][0] * enlarge, points[x][y + 1][1] * enlarge, points[x][y + 1][2] * enlarge);

//                glTexCoord2d(float_xb, float_yb);
                glVertex3f(points[x + 1][y + 1][0] * enlarge, points[x + 1][y + 1][1] * enlarge, points[x + 1][y + 1][2] * enlarge);

//                glTexCoord2d(float_xb, float_y);
                glVertex3f(points[x + 1][y][0] * enlarge, points[x + 1][y][1] * enlarge, points[x + 1][y][2] * enlarge);
            }
        }
    glEnd();


    glPolygonMode(GL_BACK, GL_FILL);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_QUADS);
//    glTranslated(mapinfo->info.origin.position.x, mapinfo->info.origin.position.y,0);
//    qDebug() << mapinfo->info.width << ", " << mapinfo->info.height;
    for(x = 0; x < mapinfo->info.width - 1; x++){
        for(y = 0; y < mapinfo->info.height - 1; y++) {
            qDebug() << x << ", " << y;
            switch (mapinfo->data[x][y]) {
            case -1:
                glColor3f(0.5, 0.5, 0.5);
                break;
            case 0:
                glColor3f(1.0, 1.0, 1.0);
                break;
            case 100:
                glColor3f(0.0, 0.0, 0.0);
                break;
            default:
                break;

//                glVertex3f((x - mapinfo->info.width/2) * mapinfo->info.resolution ,(y - mapinfo->info.width/2) * mapinfo->info.resolution, 0.0);
//                glVertex3f((x - mapinfo->info.width/2) * mapinfo->info.resolution ,(y - mapinfo->info.width/2) * mapinfo->info.resolution, 0.0);

//                glVertex3f(mapinfo->data[x][y][0], mapinfo->data[x][y][1], mapinfo->data[x][y][2]);
//                glVertex3f(mapinfo->data[x][y + 1][0], mapinfo->data[x][y + 1][1], mapinfo->data[x][y + 1][2]);
//                glVertex3f(mapinfo->data[x + 1][y + 1][0], mapinfo->data[x][y + 1][1], mapinfo->data[x][y + 1][2]);
//                glVertex3f(mapinfo->data[x][y][0], mapinfo->data[x][y][1], mapinfo->data[x][y][2]);

            }
                int pos_x = (x - mapinfo->info.width/2) * mapinfo->info.resolution;
                int pos_y = (y - mapinfo->info.width/2) * mapinfo->info.resolution;
                glVertex3f(pos_x, pos_y, 0.0);
                glVertex3f(pos_x + mapinfo->info.resolution, pos_y, 0.0);
                glVertex3f(pos_x + mapinfo->info.resolution, pos_y + mapinfo->info.resolution, 0.0);
                glVertex3f(pos_x, pos_y = mapinfo->info.resolution, 0.0);

            }

            }


    glEnd();

    glDisable(GL_MULTISAMPLE); //抗锯齿
}

void MyGLWidget::resizeGL(int width, int height)
{
    if (height == 0) {
        height = 1;
    }
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyGLWidget::timerEvent(QTimerEvent *)
{
//    qDebug() << zoom;
//    qDebug() << xRot << ", " << yRot;
    paintGL();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if(MidButtonPressed) {
         setXTranslation(dx);
         setYTranslation(dy);
    }
    else {
        if(event->buttons() & Qt::LeftButton) {
            setXRotation(xRot + 8 * dy);
            setYRotation(yRot + 8 * dx);
        }
        else if(event->buttons() & Qt::RightButton) {
//            setXRotation(xRot + 8 * dy);
//            setZRotation(zRot + 8 * dx);
            setZTranslation(dy);
        }
    }
    lastPos = event->pos();
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{

    if(event->buttons() & Qt::MidButton)
    {
        MidButtonPressed = true;
    }
    else {
        MidButtonPressed = false;
    }
    lastPos = event->pos();
}

void MyGLWidget::mouseReleaseEvent(QMouseEvent *)
{

}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) {
        zoom += 0.8;
        enlarge += 0.01;
    }
    else {
        zoom -= 0.8;
        enlarge -= 0.01;
        if(enlarge < 0.001){
            enlarge = 0.001;
        }
    }
    qDebug() << enlarge;
    updateGL();
}

void MyGLWidget::keyPressEvent(QKeyEvent *)
{
   qDebug() << "MyGLWidget" ;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizaAngle(angle);
    xRot = angle;
    updateGL();
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizaAngle(angle);
    yRot = angle;
    updateGL();
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizaAngle(angle);
    zRot = angle;
    updateGL();
}

void MyGLWidget::setXTranslation(int distance)
{
    xTrans += GLfloat(distance) * 0.1;
    updateGL();
}

void MyGLWidget::setYTranslation(int distance)
{
    yTrans -= GLfloat(distance) * 0.1;
    updateGL();
}

void MyGLWidget::setZTranslation(int distance)
{
    zoom += GLfloat(distance) * 0.2;
    updateGL();
}


void MyGLWidget::openFile()
{
   QString path = QFileDialog::getOpenFileName(this,
                                               tr("Open map.txt"),
                                               ".",
                                               tr("Text Files(*.txt)"));
   if(!path.isEmpty()){
       QFile file(path);
       if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           QMessageBox::warning(this, tr("Read File"),
                                tr("Cannot open file:\n%1").arg(path));
            return;
       }
       QTextStream in(&file);
       getMapInfoFromFile(in);
       file.close();
   }
   else {
       QMessageBox::warning(this, tr("Path"),
                            tr("You did not select any file."));
   }
}



void MyGLWidget::getMapInfoFromFile(QTextStream &in)
{
    QString datatype;
    int pos = 0;
    QString type;
//    int int_data;
//    long long longlong_data;
//    double double_data;

    ////////////////////////////////////////////////////////////
    datatype = in.readLine().simplified();
    pos = datatype.indexOf(":");
    datatype = datatype.mid(0,pos);
    if(datatype == "header") {
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if (type == "seq")
        {
            mapinfo->header.seq = datatype.mid(pos + 2).toInt();
        }
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if(type == "stamp") {
            datatype = in.readLine().simplified();
            pos = datatype.indexOf(":");
            type = datatype.mid(0,pos);
            if  (type == "secs") {
                mapinfo->header.stamp.secs = datatype.mid(pos + 2).toLongLong();
            }
            datatype = in.readLine().simplified();
            pos = datatype.indexOf(":");
            type = datatype.mid(0,pos);
            if  (type == "nsecs") {
                mapinfo->header.stamp.nsecs = datatype.mid(pos + 2).toLongLong();
            }
        }
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if(type == "frame_id") {
            mapinfo->header.frame_id = datatype.mid(pos + 2);
        }
    }
    ////////////////////////////////////////////////////////////
    datatype = in.readLine().simplified();
    pos = datatype.indexOf(":");
    datatype = datatype.mid(0,pos);
    if(datatype == "info"){
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if  (type == "map_load_time") {
            datatype = in.readLine().simplified();
            pos = datatype.indexOf(":");
            type = datatype.mid(0,pos);
            if(type == "secs") {
                mapinfo->info.map_load_time.secs = datatype.mid(pos + 2).toInt();
            }
            datatype = in.readLine().simplified();
            pos = datatype.indexOf(":");
            type = datatype.mid(0,pos);
            if(type == "nsecs") {
                mapinfo->info.map_load_time.nsecs = datatype.mid(pos + 2).toInt();
            }
        }
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if(type == "resolution"){
           mapinfo->info.resolution = datatype.mid(pos + 2).toDouble();
        }
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if(type == "width"){
           mapinfo->info.width = datatype.mid(pos + 2).toDouble();
        }
        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if(type == "height"){
           mapinfo->info.height = datatype.mid(pos + 2).toDouble();
        }

        datatype = in.readLine().simplified();
        pos = datatype.indexOf(":");
        type = datatype.mid(0,pos);
        if(type == "origin"){
            datatype = in.readLine().simplified();
            pos = datatype.indexOf(":");
            type = datatype.mid(0,pos);
            if(type == "position"){
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "x"){
                    mapinfo->info.origin.position.x =  datatype.mid(pos + 2).toDouble();
                }
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "y"){
                    mapinfo->info.origin.position.y =  datatype.mid(pos + 2).toDouble();
                }
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "z"){
                    mapinfo->info.origin.position.z =  datatype.mid(pos + 2).toDouble();
                }
            }
            datatype = in.readLine().simplified();
            pos = datatype.indexOf(":");
            type = datatype.mid(0,pos);
            if(type == "orientation"){
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "x"){
                    mapinfo->info.origin.orientation.x =  datatype.mid(pos + 2).toDouble();
                }
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "y"){
                    mapinfo->info.origin.orientation.y =  datatype.mid(pos + 2).toDouble();
                }
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "z"){
                    mapinfo->info.origin.orientation.z =  datatype.mid(pos + 2).toDouble();
                }
                datatype = in.readLine().simplified();
                pos = datatype.indexOf(":");
                type = datatype.mid(0,pos);
                if(type == "w"){
                    mapinfo->info.origin.orientation.w =  datatype.mid(pos + 2).toDouble();
                }
            }
        }
    }

    mapinfo->data = (int**)malloc(sizeof(int*)*mapinfo->info.width);
    for(int i = 0; i < mapinfo->info.width; i ++){
        mapinfo->data[i] = (int*)malloc(sizeof(int)*mapinfo->info.height);
    }


    datatype = in.readLine().simplified();
    pos = datatype.indexOf(":");
    type = datatype.mid(0,pos);
    if  (type == "data") {
        datatype = datatype.remove("data: [");
        datatype = datatype.remove("]");
        QStringList tempList = datatype.split(", ");
        qDebug() << tempList[0];
        qDebug() << tempList[1];
        qDebug() << tempList.length();
        QList<int> tempdata = QtConcurrent::blockingMapped(tempList,ccc);
        qDebug() << tempdata[0];
        qDebug() << tempdata[1];
        qDebug() << tempdata.length();
        //rxy
        //datatype.append(", ");
//        datatype.push_front(' ');
//        qDebug() << datatype.count(",");
        int cnt = 0;
//        int pos1 = 0;
        int pos = sizeof("data: [") - 1;
        int lastpos = pos;
        for(int i = 0; i < mapinfo->info.width; i++) {
            for(int j = 0; j < mapinfo->info.height; j++){
//                pos = datatype.indexOf(" ",pos + 1);
                //mapinfo->data[i][j] = datatype.mid(lastpos,pos - lastpos - 1).toInt();
//                mapinfo->data[i][j] = tempList[i*2048+j].toInt();
//                mapinfo->data[i][j] = tempdata[i * 2048 + j];
                qDebug() << cnt ++;
//                pos1 = datatype.indexOf(" ",pos1);
//                mapinfo->data[i][j] = datatype.mid(0,datatype.indexOf(",")).toInt();
//                datatype = datatype.remove(0,datatype.indexOf(" ") + 1);
                lastpos = pos + 1;
            }
        }
//        qDebug() << cnt;
    }

    printMapInfo(mapinfo);
}

void MyGLWidget::printMapInfo(MapInfo *mapinfo)
{
   qDebug() << "header: " ;
   qDebug() << "\tseq: " << mapinfo->header.seq ;
   qDebug() << "\tstamp: " ;
   qDebug() << "\t\tsecs: " << mapinfo->header.stamp.secs;
   qDebug() << "\t\tnsecs: " << mapinfo->header.stamp.nsecs;
   qDebug() << "\tframe_id: " << mapinfo->header.frame_id;

   qDebug() << "info: ";
   qDebug() << "\tmap_load_time: ";
   qDebug() << "\t\tsecs: " << mapinfo->info.map_load_time.secs;
   qDebug() << "\t\tnsecs: " << mapinfo->info.map_load_time.nsecs;
   qDebug() << "\tresolution: " << mapinfo->info.resolution;
   qDebug() << "\twidth: " << mapinfo->info.width;
   qDebug() << "\theight: " << mapinfo->info.height;
   qDebug() << "\torigin: ";
   qDebug() << "\t\tposition: ";
   qDebug() << "\t\t\tx: " << mapinfo->info.origin.position.x;
   qDebug() << "\t\t\ty: " << mapinfo->info.origin.position.y;
   qDebug() << "\t\t\tz: " << mapinfo->info.origin.position.z;
   qDebug() << "\t\torientation: ";
   qDebug() << "\t\t\tx: " << mapinfo->info.origin.orientation.x;
   qDebug() << "\t\t\ty: " << mapinfo->info.origin.orientation.y;
   qDebug() << "\t\t\tz: " << mapinfo->info.origin.orientation.z;
   qDebug() << "\t\t\tw: " << mapinfo->info.origin.orientation.z;
   qDebug() << "\tdata: ";

   QString path = QFileDialog::getSaveFileName(this,
                                               tr("Save mapinfo_data.txt"),
                                               ".",
                                               tr("Text Files(*.txt)"));
   if(!path.isEmpty()){
       QFile file(path);
       if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
           QMessageBox::warning(this, tr("Write File"),
                                tr("Cannot open file:\n%1").arg(path));
            return;
       }
       QTextStream out(&file);
//       getMapInfoFromFile(in);
       for(int i = 0; i < mapinfo->info.width; i++){
           for(int j = 0; j < mapinfo->info.height; j++){
               out << mapinfo->data[i][j] << " ";
           }
           out << "\n";
       }
       file.close();
   }
   else {
       QMessageBox::warning(this, tr("Path"),
                            tr("You did not select any file."));
   }
}

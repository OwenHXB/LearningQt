#include "mainwindow.h"
#include <QApplication>
#include <QDebug>


#define test

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef test
    MainWindow w;
    w.show();
//    int pos = 0;
//    QString datatype = "data: [-100, -1, -33, -1, -1, -90, -1, -1, -1, -1]";
//    int p = datatype.indexOf(",");
//    qDebug() << p;
//    p = datatype.indexOf(",",p+1);
//    qDebug() << p;
//    p = datatype.indexOf(",",p+1);
//    qDebug() << p;
//    p = datatype.indexOf(",",p+1);
//    qDebug() << p;
//    p = datatype.indexOf(",",p+1);
//    qDebug() << p;
//    p = datatype.indexOf(",",p+1);
//    qDebug() << p;
//    p = datatype.indexOf(",",p+1);
//    qDebug() << p;
#else
    int **data;
    data = (int**)malloc(sizeof(int*)*3);
    for(int i = 0; i < 3; i ++){
        data[i] = (int*)malloc(sizeof(int)*3);
    }
    QString datatype = "data: [-100, -1, -33, -1, -1, -90, -1, -1, -1, -1]";
    int pos = datatype.indexOf(":");
    QString type = datatype.mid(0,pos);
    if(type == "data"){
//        datatype = datatype.remove("data: [");
        datatype = datatype.remove("]");
//        datatype.push_front(' ');
        datatype.append(", ");
    qDebug() << datatype;
    int pos = sizeof("data: [") - 1;
    int lastpos = pos;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) {
                pos = datatype.indexOf(" ", pos + 1);
                qDebug() << pos;
                qDebug() << datatype.mid(lastpos, pos - lastpos - 1);
//                pos += p + 1;
//               data[i][j] = datatype.mid(0,datatype.indexOf(",")).toInt();
//               datatype = datatype.remove(0,datatype.indexOf(" ") + 1);
//    qDebug() << datatype;
                lastpos = pos + 1;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
//            qDebug() << data[i][j];
        }
    }
#endif

    return a.exec();
}

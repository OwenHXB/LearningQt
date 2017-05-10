#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QMainWindow>

namespace Ui {
class MyGLWidget;
}

class MyGLWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

private:
    Ui::MyGLWidget *ui;
};

#endif // MYGLWIDGET_H

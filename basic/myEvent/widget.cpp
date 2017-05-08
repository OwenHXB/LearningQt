#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    ui->pushButton->setText(tr("%1, %2").arg(event->x()).arg(event->y()));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
   int x = ui->pushButton->x();
   int y = ui->pushButton->y();
   switch (event->key()) {
   case Qt::Key_K:
      ui->pushButton->move(x, y - 10) ;
       break;
   case Qt::Key_J:
      ui->pushButton->move(x, y + 10) ;
       break;
   case Qt::Key_H:
      ui->pushButton->move(x - 10, y) ;
       break;
   case Qt::Key_L:
      ui->pushButton->move(x + 10, y) ;
       break;
   default:
       break;
   }
}

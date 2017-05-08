#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void timerUpdate();

private:
    Ui::Widget *ui;
    int id1;
    int id2;
    int id3;
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // WIDGET_H

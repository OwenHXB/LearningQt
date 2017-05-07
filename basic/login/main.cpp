#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog loginDialog;
    if(loginDialog.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }
    else if(loginDialog.exec() == QDialog::Rejected){
        qDebug() << "hehehe";
        return 0;
    }
    else {
        return 0;
    }
}

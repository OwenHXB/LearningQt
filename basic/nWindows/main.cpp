#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    MainWindow w;
    LoginDialog loginDialog();
    if(loginDialog.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else {
        return 0;
    }

}

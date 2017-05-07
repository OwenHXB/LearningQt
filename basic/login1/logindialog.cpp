#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent)
{
    usrLabel = new QLabel(this);
    usrLabel->move(70, 80);
    usrLabel->setText(tr("usrname:"));

    usrLineEdit = new QLineEdit(this);
    usrLineEdit->move(140, 80);
    usrLineEdit->setPlaceholderText(tr("please input your name"));

    pwdLabel = new QLabel(this);
    pwdLabel->move(70, 130);
    pwdLabel->setText(tr("password:"));

    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    pwdLineEdit->move(140, 130);
    pwdLineEdit->setPlaceholderText(tr("please input your password"));


    loginButton = new QPushButton(this);
    loginButton->move(50, 200);
    loginButton->setText(tr("login"));

    exitButton = new QPushButton(this);
    exitButton->move(210, 200);
    exitButton->setText(tr("exit"));
//    usrLineEdit->setPlace
    connect(loginButton, SIGNAL(clicked()), this, SLOT(login()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

LoginDialog::~LoginDialog() {

}

void LoginDialog::login(){
    if(usrLineEdit->text().trimmed() == tr("hujianjun") && pwdLineEdit->text() == tr("101800")){
       accept() ;
    }
    else {
        QMessageBox::warning(this,
                             tr("warning"),
                             tr("usrname or password wrong"),
                             QMessageBox::Yes);
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }

}

#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text() == tr("hujianjun") && ui->pwdLineEdit->text() == tr("hxb101800")){
        accept();
    }
    else {
        QMessageBox::warning(this,
                             QString(tr("warining")),
                             QString(tr("user name or password error")),
                             QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
        ui->usrLineEdit->setFocus();
    }
}

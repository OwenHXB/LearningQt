#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

signals:

public slots:
    void login();
private:
    QLabel *usrLabel;
    QLabel *pwdLabel;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *loginButton;
    QPushButton *exitButton;

};

#endif // LOGINDIALOG_H

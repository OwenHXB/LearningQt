#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isUntilted = true;
    curFile = tr("unknow.txt");
    setWindowTitle(curFile);
//    QPushButton *button = new QPushButton(this);
//    QLineEdit *lineEdit = new QLineEdit(this);
//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(button, 0, 0, 1, 1);
//    layout->addWidget(lineEdit, 0, 1, 1, 2);
//    layout->addWidget(ui->textEdit, 1, 0, 1, 3);
//    layout->addWidget(ui->verticalLayout,1, 1, 1, 3 );
//    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile(){
    if (maybeSave()) {
        isUntilted = true;
        curFile = tr("unknow.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave(){
    if(ui->textEdit->document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("warning"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr("尚未保存，是否保存?"));
        QPushButton *yesButton = box.addButton(tr("Yes(&Y)"), QMessageBox::YesRole);
        box.addButton(tr("No(&N)"), QMessageBox::NoRole);
        QPushButton *cancelButton = box.addButton(tr("取消"), QMessageBox::RejectRole);

        box.exec();
        if(box.clickedButton() == yesButton)
            return save();
        else if (box.clickedButton() == cancelButton)
            return false;
    }
    return true;
}

bool MainWindow::save() {
    if(isUntilted){
        return saveAs();
    }
    else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile);
    if(fileName.isEmpty())return false;
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName){
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,
                             tr("多文档编辑器"),
                             tr("Can not write file %1: /n %2").arg(fileName).arg(file.errorString())
                             );
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();

    QApplication::restoreOverrideCursor();

    isUntilted = false;

    curFile = QFileInfo(fileName).canonicalPath();
    setWindowTitle(curFile);
    return true;
}


void MainWindow::on_action_New_triggered()
{
    newFile();
}



void MainWindow::on_action_Save_triggered()
{
    save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    saveAs();
}

bool MainWindow::loadFile(const QString &fileName){
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取file %1: \n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_Open_triggered()
{
    if (maybeSave()){
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty()){
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_action_Close_triggered()
{
    if(maybeSave()) {
        ui->textEdit->setVisible(true);
    }
}



void MainWindow::on_action_Exit_triggered()
{
    on_action_Close_triggered();
    qApp->quit();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Cut_triggered()
{
   ui->textEdit->cut();
}

void MainWindow::on_action_Copy_triggered()
{
   ui->textEdit->copy();
}

void MainWindow::on_action_Paste_triggered()
{
   ui->textEdit->paste();
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (maybeSave()) {
        event->accept();
    }
    else {
        event->ignore();
    }
}

#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDir>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
=======
    QString fileName;
    QDir dir;
    fileName = dir.currentPath();
    qDebug() << fileName;
>>>>>>> e0d8c92cf47f9da0b2bf323627de982a918e74a2
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_button_Login_clicked()
{
    /*
     * check username and password
    */

    close();

    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
}

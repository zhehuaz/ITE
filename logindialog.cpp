#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDir>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QString fileName;
    QDir dir;
    fileName = dir.currentPath();
    qDebug() << fileName;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

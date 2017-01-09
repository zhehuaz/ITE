#include "newprojectpathwidget.h"
#include "ui_newprojectpathwidget.h"

#include <QFileDialog>

NewProjectPathWidget::NewProjectPathWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewProjectPathWidget)
{
    ui->setupUi(this);
}

NewProjectPathWidget::~NewProjectPathWidget()
{
    delete ui;
}

void NewProjectPathWidget::on_selectButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    ui->textEdit->setText(path);
}

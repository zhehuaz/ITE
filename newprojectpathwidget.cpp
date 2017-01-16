#include "newprojectpathwidget.h"
#include "ui_newprojectpathwidget.h"

#include <QFileDialog>

NewProjectPathWidget::NewProjectPathWidget(QWidget *parent) :
    NewProjectWidget(parent),
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
    QString path = QFileDialog::getExistingDirectory();
    ui->textEdit->setText(path);
    ((NewProjectDialog*)this->parent())->projectPath = path;
}

void NewProjectPathWidget::onNext()
{
    ((NewProjectDialog*)this->parent())->projectName = ui->nameEdit->toPlainText();
}

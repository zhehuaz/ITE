#include "newprojectvcwidget.h"
#include "ui_newprojectvcwidget.h"

NewProjectVCWidget::NewProjectVCWidget(QWidget *parent) :
    NewProjectWidget(parent),
    ui(new Ui::NewProjectVCWidget)
{
    ui->setupUi(this);
}

NewProjectVCWidget::~NewProjectVCWidget()
{
    delete ui;
}

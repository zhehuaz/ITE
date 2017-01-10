#include "newprojectmemberwidget.h"
#include "ui_newprojectmemberwidget.h"

NewProjectMemberWidget::NewProjectMemberWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewProjectMemberWidget)
{
    ui->setupUi(this);
}

NewProjectMemberWidget::~NewProjectMemberWidget()
{
    delete ui;
}

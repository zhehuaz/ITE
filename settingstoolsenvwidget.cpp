#include "settingstoolsenvwidget.h"
#include "ui_settingstoolsenvwidget.h"

SettingsToolsEnvWidget::SettingsToolsEnvWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsToolsEnvWidget)
{
    ui->setupUi(this);

    this->move(180, 20);
}

SettingsToolsEnvWidget::~SettingsToolsEnvWidget()
{
    delete ui;
}

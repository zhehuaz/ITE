#include "settingsrunenvwidget.h"
#include "ui_settingsrunenvwidget.h"

SettingsRunEnvWidget::SettingsRunEnvWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsRunEnvWidget)
{
    ui->setupUi(this);

    this->move(180, 20);
}

SettingsRunEnvWidget::~SettingsRunEnvWidget()
{
    delete ui;
}

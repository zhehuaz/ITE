#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->settingList->addItem("Run Environment");
    ui->settingList->addItem("Tool Environment");

    widgetList.push_back(new SettingsRunEnvWidget(this));
    widgetList.push_back(new SettingsToolsEnvWidget(this));

    //curWidget = widgetList.at(0);
    for (int i = 0;i < widgetList.size(); i ++)
    {
        widgetList.at(i)->hide();
    }
    curWidgetIdx = 0;
}

SettingsDialog::~SettingsDialog()
{
    for (int i = 0; i < widgetList.size(); i ++)
    {
        delete widgetList.at(i);
    }
    delete ui;
}

void SettingsDialog::on_settingList_doubleClicked(const QModelIndex &index)
{
    widgetList.at(curWidgetIdx)->hide();

    curWidgetIdx = index.row();
    widgetList.at(curWidgetIdx)->show();
}

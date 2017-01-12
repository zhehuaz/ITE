#ifndef SETTINGSTOOLSENVWIDGET_H
#define SETTINGSTOOLSENVWIDGET_H

#include <QWidget>

namespace Ui {
class SettingsToolsEnvWidget;
}

class SettingsToolsEnvWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsToolsEnvWidget(QWidget *parent = 0);
    ~SettingsToolsEnvWidget();

private:
    Ui::SettingsToolsEnvWidget *ui;
};

#endif // SETTINGSTOOLSENVWIDGET_H

#ifndef SETTINGSRUNENVWIDGET_H
#define SETTINGSRUNENVWIDGET_H

#include <QWidget>

namespace Ui {
class SettingsRunEnvWidget;
}

class SettingsRunEnvWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsRunEnvWidget(QWidget *parent = 0);
    ~SettingsRunEnvWidget();

private:
    Ui::SettingsRunEnvWidget *ui;
};

#endif // SETTINGSRUNENVWIDGET_H

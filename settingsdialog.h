#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QVector>
#include "settingsrunenvwidget.h"
#include "settingstoolsenvwidget.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    void on_settingList_doubleClicked(const QModelIndex &index);

private:
    Ui::SettingsDialog *ui;
    QVector<QWidget*> widgetList;
    //QWidget* curWidget = NULL;
    int curWidgetIdx = 0;
};

#endif // SETTINGSDIALOG_H

#ifndef NEWPROJECTPATHWIDGET_H
#define NEWPROJECTPATHWIDGET_H

#include "newprojectwidget.h"
#include <newprojectdialog.h>

namespace Ui {
class NewProjectPathWidget;
}

class NewProjectPathWidget : public NewProjectWidget
{
    Q_OBJECT

public:
    explicit NewProjectPathWidget(QWidget *parent = 0);
    ~NewProjectPathWidget();
    virtual void onNext();

private slots:
    void on_selectButton_clicked();

private:
    Ui::NewProjectPathWidget *ui;
};

#endif // NEWPROJECTPATHWIDGET_H

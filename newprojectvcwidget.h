#ifndef NEWPROJECTVCWIDGET_H
#define NEWPROJECTVCWIDGET_H

#include "newprojectwidget.h"

namespace Ui {
class NewProjectVCWidget;
}

class NewProjectVCWidget : public NewProjectWidget
{
    Q_OBJECT

public:
    explicit NewProjectVCWidget(QWidget *parent = 0);
    ~NewProjectVCWidget();

private:
    Ui::NewProjectVCWidget *ui;
};

#endif // NEWPROJECTVCWIDGET_H

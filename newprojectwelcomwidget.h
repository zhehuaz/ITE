#ifndef NEWPROJECTWELCOMWIDGET_H
#define NEWPROJECTWELCOMWIDGET_H

#include "newprojectwidget.h"

namespace Ui {
class NewProjectWelcomWidget;
}

class NewProjectWelcomWidget : public NewProjectWidget
{
    Q_OBJECT

public:
    explicit NewProjectWelcomWidget(QWidget *parent = 0);
    ~NewProjectWelcomWidget();

private:
    Ui::NewProjectWelcomWidget *ui;
};

#endif // NEWPROJECTWELCOMWIDGET_H

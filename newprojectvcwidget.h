#ifndef NEWPROJECTVCWIDGET_H
#define NEWPROJECTVCWIDGET_H

#include <QWidget>

namespace Ui {
class NewProjectVCWidget;
}

class NewProjectVCWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewProjectVCWidget(QWidget *parent = 0);
    ~NewProjectVCWidget();

private:
    Ui::NewProjectVCWidget *ui;
};

#endif // NEWPROJECTVCWIDGET_H

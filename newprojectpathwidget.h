#ifndef NEWPROJECTPATHWIDGET_H
#define NEWPROJECTPATHWIDGET_H

#include <QWidget>
#include <newprojectdialog.h>

namespace Ui {
class NewProjectPathWidget;
}

class NewProjectPathWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewProjectPathWidget(QWidget *parent = 0);
    ~NewProjectPathWidget();

private slots:
    void on_selectButton_clicked();

private:
    Ui::NewProjectPathWidget *ui;
};

#endif // NEWPROJECTPATHWIDGET_H

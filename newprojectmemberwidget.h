#ifndef NEWPROJECTMEMBERWIDGET_H
#define NEWPROJECTMEMBERWIDGET_H

#include <QWidget>

namespace Ui {
class NewProjectMemberWidget;
}

class NewProjectMemberWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewProjectMemberWidget(QWidget *parent = 0);
    ~NewProjectMemberWidget();

private:
    Ui::NewProjectMemberWidget *ui;
};

#endif // NEWPROJECTMEMBERWIDGET_H

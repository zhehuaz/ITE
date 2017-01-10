#ifndef NEWPROJECTMEMBERWIDGET_H
#define NEWPROJECTMEMBERWIDGET_H

#include <QWidget>
#include <QList>

namespace Ui {
class NewProjectMemberWidget;
}

class NewProjectMemberWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewProjectMemberWidget(QWidget *parent = 0);
    ~NewProjectMemberWidget();

private slots:
    void on_selectButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::NewProjectMemberWidget *ui;
};

#endif // NEWPROJECTMEMBERWIDGET_H

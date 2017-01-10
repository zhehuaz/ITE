#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <list>
#include "newprojectpathwidget.h"
#include "newprojectwelcomwidget.h"
#include "newprojectvcwidget.h"
#include "newprojectmemberwidget.h"

namespace Ui {
class NewProjectDialog;
}

using namespace std;

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

private:
    Ui::NewProjectDialog *ui;
    list<QWidget*> widgetList;
    list<QWidget*>::iterator widgetListIt;
    list<QWidget*>::iterator widgetListItLast;
    NewProjectPathWidget *pathWidget;
    NewProjectWelcomWidget *welcomWidget;
private slots:
    void on_nextButton_clicked();
    void on_backButton_clicked();
};

#endif // NEWPROJECTDIALOG_H

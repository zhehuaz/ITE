#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include <QDir>
#include <mainwindow.h>

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    ui->backButton->setVisible(false);

    widgetList.push_back(new NewProjectWelcomWidget(this));
    widgetList.push_back(new NewProjectPathWidget(this));
    widgetList.push_back(new NewProjectVCWidget(this));
    widgetList.push_back(new NewProjectMemberWidget(this));

    widgetListIt = widgetList.begin();
    widgetListIt ++;
    for ( ; widgetListIt != widgetList.end(); widgetListIt ++)
    {
        (*widgetListIt)->setVisible(false);
    }

    widgetListIt = widgetList.begin();
    widgetListItLast = widgetList.end();
    widgetListItLast --;
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;

    for (widgetListIt = widgetList.begin(); widgetListIt != widgetList.end(); widgetListIt ++)
    {
        delete (*widgetListIt);
    }
}

void NewProjectDialog::finishCreating()
{
    if (projectPath.length() > 0)
    {
        QDir dir(projectPath);
        if (!dir.exists())
        {
            dir.mkpath(".");
        }
        dir.mkpath("./hello");
        dir.mkpath("./test");
        dir.mkpath("./yes");
        QFile file(dir.filePath("new.prj"));
        file.open(QFile::WriteOnly);
        MainWindow *mainwindow = new MainWindow();
        mainwindow->show();
    }
}

void NewProjectDialog::on_nextButton_clicked()
{
    (*widgetListIt)->setVisible(false);
    widgetListIt ++;

    if (widgetListIt == widgetList.end())
    {
        // click 'Done'
        this->accept();
        this->finishCreating();
    }
    else
    {
        (*widgetListIt)->setVisible(true);

        if (widgetListIt == widgetListItLast)
        {
            ui->backButton->setVisible(true);
            ui->nextButton->setText("Done");
            if (this->projectPath.length() == 0)
            {
                ui->nextButton->setEnabled(false);
            }
            else
            {
                ui->nextButton->setEnabled(true);
            }
        }
        else
        {
            ui->backButton->setVisible(true);
        }
    }
}

void NewProjectDialog::on_backButton_clicked()
{
    ui->nextButton->setText("Next");
    ui->nextButton->setEnabled(true);
    (*widgetListIt)->setVisible(false);
    widgetListIt --;
    (*widgetListIt)->setVisible(true);

    if (widgetListIt == widgetList.begin())
    {
        ui->backButton->setVisible(false);
    }
    else
    {
        ui->backButton->setVisible(true);
    }
}

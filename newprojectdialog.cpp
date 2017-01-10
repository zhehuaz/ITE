#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

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

void NewProjectDialog::on_nextButton_clicked()
{
    (*widgetListIt)->setVisible(false);
    widgetListIt ++;

    if (widgetListIt == widgetList.end())
    {
        // click 'Done'
        this->accept();
    }
    else
    {
        (*widgetListIt)->setVisible(true);

        if (widgetListIt == widgetListItLast)
        {
            ui->backButton->setVisible(true);
            ui->nextButton->setText("Done");
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

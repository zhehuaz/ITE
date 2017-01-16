#include "newprojectmemberwidget.h"
#include "ui_newprojectmemberwidget.h"

NewProjectMemberWidget::NewProjectMemberWidget(QWidget *parent) :
    NewProjectWidget(parent),
    ui(new Ui::NewProjectMemberWidget)
{
    ui->setupUi(this);
    ui->candiList->addItem(new QListWidgetItem("Mary"));
    ui->candiList->addItem(new QListWidgetItem("Candy"));
    ui->candiList->addItem(new QListWidgetItem("Micheal"));
    ui->candiList->addItem(new QListWidgetItem("Alex"));
    ui->candiList->addItem(new QListWidgetItem("Tony"));
    ui->candiList->addItem(new QListWidgetItem("Bob"));
    ui->candiList->addItem(new QListWidgetItem("Alice"));
    ui->candiList->addItem(new QListWidgetItem("Bill"));
    ui->candiList->addItem(new QListWidgetItem("John"));
    ui->candiList->addItem(new QListWidgetItem("Amy"));
    ui->candiList->addItem(new QListWidgetItem("Jack"));
    ui->candiList->addItem(new QListWidgetItem("Keasy"));
    ui->candiList->addItem(new QListWidgetItem("Shone"));
    ui->candiList->addItem(new QListWidgetItem("Ben"));
    ui->candiList->addItem(new QListWidgetItem("Fillip"));
    ui->candiList->addItem(new QListWidgetItem("Carearl"));
    ui->candiList->addItem(new QListWidgetItem("Sam"));
}

NewProjectMemberWidget::~NewProjectMemberWidget()
{
    delete ui;
}

void NewProjectMemberWidget::on_selectButton_clicked()
{
    QList<QListWidgetItem*> selectedList = ui->candiList->selectedItems();
    for (QList<QListWidgetItem*>::iterator it = selectedList.begin(); it != selectedList.end(); it ++)
    {
        ui->candiList->takeItem(ui->candiList->row(*it));
        ui->selectList->addItem((*it)->text());
    }
}

void NewProjectMemberWidget::on_pushButton_clicked()
{
    QList<QListWidgetItem*> selectedList = ui->selectList->selectedItems();
    for (QList<QListWidgetItem*>::iterator it = selectedList.begin(); it != selectedList.end(); it ++)
    {
        QListWidgetItem* item = ui->selectList->takeItem(ui->selectList->row(*it));
        ui->candiList->addItem(item->text());
    }
}

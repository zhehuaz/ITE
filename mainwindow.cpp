#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createAction();
    createMenu();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenu()
{
    fileMenu = this->menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(fileOpenAction);
}

void MainWindow::createAction()
{
    fileOpenAction = new QAction(tr("Open File"),this);
}

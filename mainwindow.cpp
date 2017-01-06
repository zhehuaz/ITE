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
    fileMenu->addAction(fileNew);
    fileMenu->addAction(fileOpen);
    fileMenu->addAction(fileClose);
    fileMenu->addAction(fileSave);
    fileMenu->addAction(fileSaveAs);

    editMenu = this->menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(undo);
    editMenu->addAction(redo);
    editMenu->addAction(cut);
    editMenu->addAction(copy);
    editMenu->addAction(paste);
    editMenu->addAction(search);

    viewMenu = this->menuBar()->addMenu(tr("视图"));
    viewMenu->addAction(projectView);
    viewMenu->addAction(processView);
    viewMenu->addAction(reportView);
    viewMenu->addAction(statusView);
    viewMenu->addAction(scriptView);
    viewMenu->addAction(messageView);
    viewMenu->addAction(toolBar);
    viewMenu->addAction(statusBar);
    viewMenu->addAction(fileDirectory);
    viewMenu->addAction(saveView);
    viewMenu->addAction(loadView);
    viewMenu->addAction(font);

    windowMenu = this->menuBar()->addMenu(tr("窗口"));
    windowMenu->addAction(windowClose);
    windowMenu->addAction(windowMinimize);
    windowMenu->addAction(layoutHorizontal);
    windowMenu->addAction(layoutVertical);

    helpMenu = this->menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(about);
}

void MainWindow::createAction()
{
    fileNew = new QAction(tr("新建文件"),this);
    fileOpen = new QAction(tr("打开文件"),this);
    fileClose = new QAction(tr("关闭文件"),this);
    fileSave= new QAction(tr("保存文件"),this);
    fileSaveAs= new QAction(tr("另存文件"),this);

    undo = new QAction(tr("撤销"),this);
    redo = new QAction(tr("重做"),this);
    cut = new QAction(tr("剪切"),this);
    copy = new QAction(tr("拷贝"),this);
    paste = new QAction(tr("粘贴"),this);
    search = new QAction(tr("查找"),this);

    projectView = new QAction(tr("工程界面"),this);
    processView = new QAction(tr("进程界面"),this);
    reportView = new QAction(tr("报告界面"),this);
    statusView = new QAction(tr("测试状态界面"),this);
    scriptView = new QAction(tr("脚本界面"),this);
    messageView = new QAction(tr("信息界面"),this);
    toolBar = new QAction(tr("工具栏"),this);
    statusBar = new QAction(tr("状态栏"),this);
    fileDirectory = new QAction(tr("文件路径"),this);
    saveView = new QAction(tr("视图布局保存"),this);
    loadView = new QAction(tr("视图布局载入"),this);
    font = new QAction(tr("字体"),this);

    windowClose = new QAction(tr("关闭窗口"),this);
    windowMinimize = new QAction(tr("最小化窗口"),this);
    layoutHorizontal = new QAction(tr("水平分布窗口"),this);
    layoutVertical = new QAction(tr("垂直分布窗口"),this);

    about = new QAction(tr("关于"),this);
}

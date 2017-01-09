#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //setGeometry(100, 100, 800, 600);
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
    fileMenu->addSeparator();
    fileMenu->addAction(fileSave);
    fileMenu->addAction(fileSaveAs);

    editMenu = this->menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(undo);
    editMenu->addAction(redo);
    editMenu->addAction(cut);
    editMenu->addAction(copy);
    editMenu->addAction(paste);
    editMenu->addSeparator();
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
    viewMenu->addSeparator();
    viewMenu->addAction(fileDirectory);
    viewMenu->addSeparator();
    viewMenu->addAction(saveView);
    viewMenu->addAction(loadView);
    viewMenu->addSeparator();
    viewMenu->addAction(font);

    projectMenu = this->menuBar()->addMenu(tr("工程"));
    projectMenu->addAction(projectNew);
    projectMenu->addAction(projectOpen);
    projectMenu->addAction(projectClose);
    projectMenu->addAction(projectSave);
    projectMenu->addAction(projectQuit);
    projectMenu->addAction(projectRecent);
    projectMenu->addAction(projectClean);
    projectMenu->addSeparator();
    projectMenu->addAction(versionControl);
    projectMenu->addSeparator();
    projectMenu->addAction(projectProperty);

    windowMenu = this->menuBar()->addMenu(tr("窗口"));
    windowMenu->addAction(windowClose);
    windowMenu->addAction(windowMinimize);
    windowMenu->addSeparator();
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
    projectView->setCheckable(true);
    processView = new QAction(tr("进程界面"),this);
    processView->setCheckable(true);
    reportView = new QAction(tr("报告界面"),this);
    reportView->setCheckable(true);
    statusView = new QAction(tr("测试状态界面"),this);
    statusView->setCheckable(true);
    scriptView = new QAction(tr("脚本界面"),this);
    scriptView->setCheckable(true);

    messageView = new QAction(tr("信息界面"),this);
    messageViewSubMenu = new QMenu(this);
    sysConsole = new QAction(tr("系统控制台"),messageView);
    sysConsole->setCheckable(true);
    sysConsoleError = new QAction(tr("系统控制台错误"),messageView);
    sysConsoleError->setCheckable(true);
    sysConsoleWarning = new QAction(tr("系统控制台警告"),messageView);
    sysConsoleWarning->setCheckable(true);
    testConsoleError = new QAction(tr("测试控制台错误"),messageView);
    testConsoleError->setCheckable(true);
    testConsoleWarning = new QAction(tr("测试控制台警告"),messageView);
    testConsoleWarning->setCheckable(true);
    messageViewSubMenu->addAction(sysConsole);
    messageViewSubMenu->addAction(sysConsoleError);
    messageViewSubMenu->addAction(sysConsoleWarning);
    messageViewSubMenu->addAction(testConsoleError);
    messageViewSubMenu->addAction(testConsoleWarning);
    messageView->setMenu(messageViewSubMenu);

    toolBar = new QAction(tr("工具栏"),this);
    toolBar->setCheckable(true);
    statusBar = new QAction(tr("状态栏"),this);
    statusBar->setCheckable(true);
    fileDirectory = new QAction(tr("文件路径"),this);
    fileDirectorySubMenu = new QMenu(this);
    fileDirectoryGroup = new QActionGroup(this);
    absolutePath = new QAction(tr("以绝对路径显示文件"),fileDirectory);
    absolutePath->setCheckable(true);
    relativePath = new QAction(tr("以相对路径显示文件"),fileDirectory);
    relativePath->setCheckable(true);
    fileDirectorySubMenu->addAction(absolutePath);
    fileDirectorySubMenu->addAction(relativePath);
    fileDirectory->setMenu(fileDirectorySubMenu);
    fileDirectoryGroup->addAction(absolutePath);
    fileDirectoryGroup->addAction(relativePath);
    fileDirectoryGroup->setExclusive(true);


    saveView = new QAction(tr("视图布局保存"),this);
    loadView = new QAction(tr("视图布局载入"),this);   
    font = new QAction(tr("字体"),this);

    projectNew = new QAction(tr("新建工程"),this);
    projectOpen = new QAction(tr("打开工程"),this);
    projectClose = new QAction(tr("关闭工程"),this);
    projectSave = new QAction(tr("保存工程"),this);
    projectQuit = new QAction(tr("工程退出"),this);
    projectRecent = new QAction(tr("最近工程"),this);
    projectClean = new QAction(tr("清除工程"),this);
    versionControl = new QAction(tr("版本管理"),this);
    projectProperty = new QAction(tr("工程属性"),this);

    windowClose = new QAction(tr("关闭窗口"),this);
    windowMinimize = new QAction(tr("最小化窗口"),this);
    layoutActionGroup = new QActionGroup(this);
    layoutHorizontal = new QAction(tr("水平分布窗口"),this);
    layoutHorizontal->setCheckable(true);
    layoutVertical = new QAction(tr("垂直分布窗口"),this);
    layoutVertical->setCheckable(true);
    layoutActionGroup->addAction(layoutHorizontal);
    layoutActionGroup->addAction(layoutVertical);
    layoutActionGroup->setExclusive(true);

    about = new QAction(tr("关于"),this);
}

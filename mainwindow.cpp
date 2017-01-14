#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("软件产品质量保证应用平台"));
    setGeometry(100, 100, 800, 600);
    createLayout();
    createAction();
    createMenu();
}

MainWindow::~MainWindow()
{
    delete fileMenu;
    delete fileNew;
    delete fileOpen;
    delete fileClose;
    delete fileSave;
    delete fileSaveAs;

    delete editMenu;
    delete undo;
    delete redo;
    delete cut;
    delete copy;
    delete paste;
    delete search;

    delete viewMenu;
    delete projectView;
    delete processView;
    delete reportView;
    delete statusView;
    delete scriptView;

    delete messageView;
    delete messageViewSubMenu;
    delete sysConsole;
    delete sysConsoleError;
    delete sysConsoleWarning;
    delete testConsoleError;
    delete testConsoleWarning;

    delete toolBar;
    delete statusBar;
    delete fileDirectory;
    delete fileDirectorySubMenu;
    delete fileDirectoryGroup;
    delete absolutePath;
    delete relativePath;
    delete saveView;
    delete loadView;
    delete font;

    delete projectMenu;
    delete projectNew;
    delete projectOpen;
    delete projectClose;
    delete projectSave;
    delete projectQuit;
    delete projectRecent;
    delete projectClean;
    delete versionControl;
    delete projectProperty;

    delete windowMenu;
    delete windowClose;
    delete windowMinimize;
    delete layoutActionGroup;
    delete layoutHorizontal;
    delete layoutVertical;

    delete helpMenu;
    delete about;
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
    connect(projectNew, SIGNAL(triggered()),this,SLOT(newProject()));
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
    connect(projectProperty, SIGNAL(triggered()),this,SLOT(projectSettings()));

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

void MainWindow::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *upLayout = new QHBoxLayout;
    QVBoxLayout *viewLayout = new QVBoxLayout;
    QVBoxLayout *showLayout = new QVBoxLayout;
    QVBoxLayout *msgLayout = new QVBoxLayout;
    QTabWidget *viewTab = new QTabWidget;
    QTabWidget *showTab = new QTabWidget;
    QTabWidget *msgTab = new QTabWidget;

    QWidget *fileWidget = new QWidget;
    QWidget *reportWidget = new QWidget;
    QWidget *taskWidget = new QWidget;
    viewTab->addTab(fileWidget, tr("解决方案"));
    viewTab->addTab(reportWidget, tr("报表数据"));
    viewTab->addTab(taskWidget, tr("执行任务列表"));
    viewTab->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    viewTab->setMaximumWidth(280);
    viewLayout->addWidget(viewTab);

    TreeView *fileTreeView = new TreeView;
    createFileTree(fileTreeView);
    QVBoxLayout *fileTreeLayout = new QVBoxLayout;
    fileWidget->setLayout(fileTreeLayout);
    fileTreeLayout->addWidget(fileTreeView);

    TreeView *reportTreeView = new TreeView;
    createReportFiletree(reportTreeView);
    QVBoxLayout *reportTreeLayout = new QVBoxLayout;
    reportWidget->setLayout(reportTreeLayout);
    reportTreeLayout->addWidget(reportTreeView);

    TreeView *taskTreeView = new TreeView;
    createTaskFileTree(taskTreeView);
    QVBoxLayout *taskTreeLayout = new QVBoxLayout;
    taskWidget->setLayout(taskTreeLayout);
    taskTreeLayout->addWidget(taskTreeView);

    QWidget *sysCnsErrWidget = new QWidget;
    QWidget *sysCnsWrnWidget = new QWidget;
    QWidget *tstCnsErrWidget = new QWidget;
    QWidget *tstCnsWrnWidget = new QWidget;

    QTextEdit *sysCnsTxt = new QTextEdit;
    QString sysCnsString = " 1>-- 已启动生成：项目：Demo.prj 配置：d.ini --\n"
                           " 1>加载规则约束文件...\n"
                           " 1>加载测试用例TC...\n 1>正在编译...\n"
                           " 1>正在编译..."
                           " 1>Demo.prj - 0个错误， 0个警告"
                           " ==== 运行：成功1个，失败0个 ====";
    sysCnsTxt->setPlainText(sysCnsString);

    msgTab->addTab(sysCnsTxt, tr("系统控制台错误"));
    msgTab->addTab(sysCnsWrnWidget, tr("系统控制台警告"));
    msgTab->addTab(tstCnsErrWidget, tr("测试控制台错误"));
    msgTab->addTab(tstCnsWrnWidget, tr("测试控制台警告"));
    msgTab->setFixedHeight(150);
    msgLayout->addWidget(msgTab);


    QWidget *showWidget = new QWidget;
    showWidget->setFixedWidth(500);

    QTextEdit *showTxtEdit = new QTextEdit;
    showTxtEdit->setEnabled(true);
    showTab->addTab(showTxtEdit, tr("编辑"));
    showLayout->addWidget(showTab);

    QTableWidget *pjtPptTable = new QTableWidget(6,2);
    pjtPptTable->horizontalHeader()->setStretchLastSection(true);
    pjtPptTable->setSelectionBehavior(QAbstractItemView::SelectItems);
    pjtPptTable->setEditTriggers(QAbstractItemView::DoubleClicked);

    QTableWidgetItem *item0_0 = new QTableWidgetItem;
    QTableWidgetItem *item0_1 = new QTableWidgetItem;
    QTableWidgetItem *item1_0 = new QTableWidgetItem;
    QTableWidgetItem *item1_1 = new QTableWidgetItem;
    QTableWidgetItem *item2_0 = new QTableWidgetItem;
    QTableWidgetItem *item2_1 = new QTableWidgetItem;
    QTableWidgetItem *item3_0 = new QTableWidgetItem;
    QTableWidgetItem *item3_1 = new QTableWidgetItem;
    QTableWidgetItem *item4_0 = new QTableWidgetItem;
    QTableWidgetItem *item4_1 = new QTableWidgetItem;
    QTableWidgetItem *item5_0 = new QTableWidgetItem;
    QTableWidgetItem *item5_1 = new QTableWidgetItem;

    QStringList title;
    title<<" "<<" ";
    pjtPptTable->setHorizontalHeaderLabels(title);
    title<<" "<<" "<<" "<<" ";
    pjtPptTable->setVerticalHeaderLabels(title);

    item0_0->setText("工程名称");
    item0_0->setBackgroundColor(QColor(192, 192, 192));
    item0_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(0,0,item0_0);
    item0_1->setText(tr("Demo.prj"));
    item0_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(0,1,item0_1);
    item1_0->setText(tr("被测软件"));
    item1_0->setBackgroundColor(QColor(192, 192, 192));
    item1_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(1,0,item1_0);
    item1_1->setText(tr("XX"));
    item1_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(1,1,item1_1);
    item2_0->setText(tr("芯片厂商"));
    item2_0->setBackgroundColor(QColor(192, 192, 192));
    item2_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(2,0,item2_0);
    item2_1->setText(tr("Xilinx"));
    item2_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(2,1,item2_1);
    item3_0->setText(tr("开发软件"));
    item3_0->setBackgroundColor(QColor(192, 192, 192));
    item3_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(3,0,item3_0);
    item3_1->setText(tr("TestCode"));
    item3_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(3,1,item3_1);
    item4_0->setText(tr("开发版本"));
    item4_0->setBackgroundColor(QColor(192, 192, 192));
    item4_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(4,0,item4_0);
    item4_1->setText(tr("V1.0"));
    item4_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(4,1,item4_1);
    item5_0->setText(tr("代码行数统计"));
    item5_0->setBackgroundColor(QColor(192, 192, 192));
    item5_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(5,0,item5_0);
    item5_1->setText(tr("2141"));
    item5_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    pjtPptTable->setItem(5,1,item5_1);

    showTab->addTab(pjtPptTable, tr("工程属性"));

    QTableWidget *staticTestTable = new QTableWidget(4,4);
    staticTestTable->horizontalHeader()->setStretchLastSection(true);
    staticTestTable->setSelectionBehavior(QAbstractItemView::SelectItems);
    staticTestTable->setEditTriggers(QAbstractItemView::DoubleClicked);

    QStringList title2;
    title2<<"测试类型"<<"执行结果"<<"测试通过"<<"备注";
    staticTestTable->setHorizontalHeaderLabels(title2);
    staticTestTable->setVerticalHeaderLabels(title);

    QTableWidgetItem *stcItem0_0 = new QTableWidgetItem;
    QTableWidgetItem *stcItem0_1 = new QTableWidgetItem;
    QTableWidgetItem *stcItem0_2 = new QTableWidgetItem;
    QTableWidgetItem *stcItem0_3 = new QTableWidgetItem;
    QTableWidgetItem *stcItem1_0 = new QTableWidgetItem;
    QTableWidgetItem *stcItem1_1 = new QTableWidgetItem;
    QTableWidgetItem *stcItem1_2 = new QTableWidgetItem;
    QTableWidgetItem *stcItem1_3 = new QTableWidgetItem;
    QTableWidgetItem *stcItem2_0 = new QTableWidgetItem;
    QTableWidgetItem *stcItem2_1 = new QTableWidgetItem;
    QTableWidgetItem *stcItem2_2 = new QTableWidgetItem;
    QTableWidgetItem *stcItem2_3 = new QTableWidgetItem;
    QTableWidgetItem *stcItem3_0 = new QTableWidgetItem;
    QTableWidgetItem *stcItem3_1 = new QTableWidgetItem;
    QTableWidgetItem *stcItem3_2 = new QTableWidgetItem;
    QTableWidgetItem *stcItem3_3 = new QTableWidgetItem;

    stcItem0_0->setText(tr("规则检查"));
    stcItem0_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(0,0,stcItem0_0);
    stcItem1_0->setText(tr("静态时序分析"));
    stcItem1_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(1,0,stcItem1_0);
    stcItem2_0->setText(tr("跨时钟域检查"));
    stcItem2_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(2,0,stcItem2_0);
    stcItem3_0->setText(tr("一致性检查"));
    stcItem3_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(3,0,stcItem3_0);

    stcItem0_1->setCheckState(Qt::CheckState::Checked);
    stcItem0_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(0,1,stcItem0_1);
    stcItem1_1->setCheckState(Qt::CheckState::Checked);
    stcItem1_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(1,1,stcItem1_1);
    stcItem2_1->setCheckState(Qt::CheckState::Checked);
    stcItem2_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(2,1,stcItem2_1);
    stcItem3_1->setCheckState(Qt::CheckState::Checked);
    stcItem3_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(3,1,stcItem3_1);

    stcItem0_2->setCheckState(Qt::CheckState::Unchecked);
    stcItem0_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(0,2,stcItem0_2);
    stcItem1_2->setCheckState(Qt::CheckState::Unchecked);
    stcItem1_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(1,2,stcItem1_2);
    stcItem2_2->setCheckState(Qt::CheckState::Unchecked);
    stcItem2_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(2,2,stcItem2_2);
    stcItem3_2->setCheckState(Qt::CheckState::Unchecked);
    stcItem3_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    staticTestTable->setItem(3,2,stcItem3_2);

    staticTestTable->setItem(0,3,stcItem0_3);
    staticTestTable->setItem(1,3,stcItem1_3);
    staticTestTable->setItem(2,3,stcItem2_3);
    staticTestTable->setItem(3,3,stcItem3_3);

    showTab->addTab(staticTestTable, tr("静态测试状态"));


    upLayout->addLayout(viewLayout);
    upLayout->addLayout(showLayout);
    mainLayout->addLayout(upLayout);
    mainLayout->addLayout(msgLayout);

    QWidget *Mwidget = new QWidget(this);
    Mwidget->setLayout(mainLayout);
    this->setCentralWidget(Mwidget);
}

void MainWindow::createTaskFileTree(TreeView *treeview)
{
    QStandardItemModel *model = new QStandardItemModel(treeview);
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("名称"));

    QStandardItem *itemStaticTool = new QStandardItem(QStringLiteral("静态工具"));
    itemStaticTool->setIcon(QIcon(":/bg/icon_folder"));

    QStandardItem *itemDynamicTool = new QStandardItem(QStringLiteral("动态工具"));
    itemDynamicTool->setIcon(QIcon(":/bg/icon_folder"));

    QStandardItem *itemDebugTool = new QStandardItem(QStringLiteral("调试工具"));
    itemDebugTool->setIcon(QIcon(":/bg/icon_folder"));

    model->appendRow(itemStaticTool);
    model->appendRow(itemDynamicTool);
    model->appendRow(itemDebugTool);

    QStandardItem *check1_1 = new QStandardItem(QStringLiteral("规则检查"));
    check1_1->setIcon(QIcon(":/bg/icon_checked"));
    QStandardItem *check1_2 = new QStandardItem(QStringLiteral("跨时钟域检查"));
    check1_2->setIcon(QIcon(":/bg/icon_checked"));
    QStandardItem *check1_3 = new QStandardItem(QStringLiteral("静态时序分析"));
    check1_3->setIcon(QIcon(":/bg/icon_wrong"));
    QStandardItem *check1_4 = new QStandardItem(QStringLiteral("一致性检查"));
    check1_4->setIcon(QIcon(":/bg/icon_unchecked"));

    itemStaticTool->appendRow(check1_1);
    itemStaticTool->appendRow(check1_2);
    itemStaticTool->appendRow(check1_3);
    itemStaticTool->appendRow(check1_4);

    QStandardItem *check2_1 = new QStandardItem(QStringLiteral("测试平台创建"));
    check2_1->setIcon(QIcon(":/bg/icon_checked"));
    QStandardItem *check2_2 = new QStandardItem(QStringLiteral("测试用例创建"));
    check2_2->setIcon(QIcon(":/bg/icon_checked"));
    QStandardItem *check2_3 = new QStandardItem(QStringLiteral("功能仿真"));
    check2_3->setIcon(QIcon(":/bg/icon_checked"));
    QStandardItem *check2_4 = new QStandardItem(QStringLiteral("时序仿真"));
    check2_4->setIcon(QIcon(":/bg/icon_wrong"));
    QStandardItem *check2_3_1 = new QStandardItem(QStringLiteral("测试用例TC_xx"));
    check2_3_1->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *check2_4_1 = new QStandardItem(QStringLiteral("测试用例TC_xx"));
    check2_4_1->setIcon(QIcon(":/bg/icon_file"));

    itemDynamicTool->appendRow(check2_1);
    itemDynamicTool->appendRow(check2_2);
    itemDynamicTool->appendRow(check2_3);
    itemDynamicTool->appendRow(check2_4);
    check2_3->appendRow(check2_3_1);
    check2_4->appendRow(check2_4_1);

    QStandardItem *check3_1 = new QStandardItem(QStringLiteral("Verdi"));
    check3_1->setIcon(QIcon(":/bg/icon_checked"));

    itemDebugTool->appendRow(check3_1);

    treeview->setModel(model);
}

void MainWindow::createReportFiletree(TreeView *treeview)
{
    QStandardItemModel *model = new QStandardItemModel(treeview);
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("名称"));

    QStandardItem *itemStaticTool = new QStandardItem(QStringLiteral("静态工具"));
    itemStaticTool->setIcon(QIcon(":/bg/icon_folder"));

    QStandardItem *itemDynamicTool = new QStandardItem(QStringLiteral("动态工具"));
    itemDynamicTool->setIcon(QIcon(":/bg/icon_folder"));

    QStandardItem *itemDebugTool = new QStandardItem(QStringLiteral("调试工具"));
    itemDebugTool->setIcon(QIcon(":/bg/icon_folder"));

    model->appendRow(itemStaticTool);
    model->appendRow(itemDynamicTool);
    model->appendRow(itemDebugTool);

    QStandardItem *file1_1 = new QStandardItem(QStringLiteral("代码行数日志.log"));
    file1_1->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file1_2 = new QStandardItem(QStringLiteral("规则检查日志.log"));
    file1_2->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file1_3 = new QStandardItem(QStringLiteral("跨时钟域检查日志.log"));
    file1_3->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file1_4 = new QStandardItem(QStringLiteral("静态时序分析日志.log"));
    file1_4->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file1_5 = new QStandardItem(QStringLiteral("一致性检查日志.log"));
    file1_5->setIcon(QIcon(":/bg/icon_file"));

    itemStaticTool->appendRow(file1_1);
    itemStaticTool->appendRow(file1_2);
    itemStaticTool->appendRow(file1_3);
    itemStaticTool->appendRow(file1_4);
    itemStaticTool->appendRow(file1_5);

    QStandardItem *itemDynamicSti = new QStandardItem(QStringLiteral("功能仿真"));
    itemDynamicSti->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *itemTimeSti = new QStandardItem(QStringLiteral("时序仿真"));
    itemTimeSti->setIcon(QIcon(":/bg/icon_folder"));

    itemDynamicTool->appendRow(itemDynamicSti);
    itemDynamicTool->appendRow(itemTimeSti);

    QStandardItem *file2_1_1 = new QStandardItem(QStringLiteral("测试用例TC_xx日志.log"));
    file2_1_1->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file2_2_1 = new QStandardItem(QStringLiteral("测试用例TC_xx日志.log"));
    file2_2_1->setIcon(QIcon(":/bg/icon_file"));

    itemDynamicSti->appendRow(file2_1_1);
    itemTimeSti->appendRow(file2_2_1);

    QStandardItem *verdi = new QStandardItem(QStringLiteral("Verdi"));
    verdi->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *file3_1_1 = new QStandardItem(QStringLiteral("测试用例TC_xx日志.log"));
    file3_1_1->setIcon(QIcon(":/bg/icon_file"));

    itemDebugTool->appendRow(verdi);
    verdi->appendRow(file3_1_1);

    QStandardItem *filterInfo = new QStandardItem(QStringLiteral("过滤信息"));
    QStandardItem *showError = new QStandardItem(QStringLiteral("显示error"));
    showError->setCheckState(Qt::Checked);
    showError->setCheckable(true);
    QStandardItem *showWarning = new QStandardItem(QStringLiteral("显示warning"));
    showWarning->setCheckState(Qt::Unchecked);
    showWarning->setCheckable(true);
    QStandardItem *showUserChar = new QStandardItem(QStringLiteral("显示用户定制字符"));
    showUserChar->setCheckState(Qt::Checked);
    showUserChar->setCheckable(true);

    model->appendRow(filterInfo);
    filterInfo->appendRow(showError);
    filterInfo->appendRow(showWarning);
    filterInfo->appendRow(showUserChar);

    treeview->setModel(model);
}

void MainWindow::createFileTree(TreeView *treeview)
{
    QStandardItemModel *model = new QStandardItemModel(treeview);
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("名称"));
    QStandardItem *itemProject = new QStandardItem(QStringLiteral("项目"));
    itemProject->setIcon(QIcon(":/bg/icon_project"));
    model->appendRow(itemProject);
    //model->setItem(model->indexFromItem(itemProject).row(), 1, new QStandardItem(QStringLiteral("项目信息说明")));

    QStandardItem *folder1 = new QStandardItem("规则检查文件夹");
    folder1->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *folder2 = new QStandardItem("跨时钟域检查文件夹");
    folder2->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *folder3 = new QStandardItem("功能时序仿真文件夹");
    folder3->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *folder4 = new QStandardItem("静态时序分析文件夹");
    folder4->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *folder5 = new QStandardItem("一致性文件夹");
    folder5->setIcon(QIcon(":/bg/icon_folder"));

    itemProject->appendRow(folder1);
    itemProject->appendRow(folder2);
    itemProject->appendRow(folder3);
    itemProject->appendRow(folder4);
    itemProject->appendRow(folder5);

    QStandardItem *file1_1 = new QStandardItem("规则约束文件.rule");
    folder1->appendRow(file1_1);
    file1_1->setIcon(QIcon(":/bg/icon_file"));

    QStandardItem *file2_1 = new QStandardItem("directive.tcl");
    file2_1->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file2_2 = new QStandardItem("test.c");
    file2_2->setIcon(QIcon(":/bg/icon_file"));
    folder2->appendRow(file2_1);
    folder2->appendRow(file2_2);

    QStandardItem *folder3_1 = new QStandardItem("测试平台TB");
    folder3_1->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *folder3_2 = new QStandardItem("验证vip");
    folder3_2->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *folder3_3 = new QStandardItem("库文件LIB");
    folder3_3->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *file3_3_1 = new QStandardItem("a.lib");
    file3_3_1->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *file3_3_2 = new QStandardItem("b.lib");
    file3_3_2->setIcon(QIcon(":/bg/icon_file"));
    QStandardItem *folder3_4 = new QStandardItem("测试用例TC");
    folder3_4->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *file3_5 = new QStandardItem("工具配置文件.ini");
    file3_5->setIcon(QIcon(":/bg/icon_file"));

    folder3->appendRow(folder3_1);
    folder3->appendRow(folder3_2);
    folder3->appendRow(folder3_3);
    folder3->appendRow(folder3_4);
    folder3->appendRow(file3_5);
    folder3_3->appendRow(file3_3_1);
    folder3_3->appendRow(file3_3_2);

    QStandardItem *folder4_1 = new QStandardItem("源文件SRC");
    folder4_1->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *file4_2 = new QStandardItem("工具配置文件.ini");
    file4_2->setIcon(QIcon(":/bg/icon_file"));

    folder4->appendRow(folder4_1);
    folder4->appendRow(file4_2);

    QStandardItem *folder5_1 = new QStandardItem("源文件SRC");
    folder5_1->setIcon(QIcon(":/bg/icon_folder"));
    QStandardItem *file5_2 = new QStandardItem("工具配置文件.ini");
    file5_2->setIcon(QIcon(":/bg/icon_file"));

    folder5->appendRow(folder5_1);
    folder5->appendRow(file5_2);

    treeview->setModel(model);
    //treeview->iterateOverItems();
    //treeview->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::newProject()
{
    NewProjectDialog *newProjectDialog = new NewProjectDialog;
    newProjectDialog->show();
}

void MainWindow::projectSettings()
{
    SettingsDialog *settingsDialog = new SettingsDialog;
    settingsDialog->show();
}

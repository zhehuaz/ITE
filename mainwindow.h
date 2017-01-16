#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define PROJECT 1
//#define FILE 2
//#define TC 3
//#define STATIC 4
//#define DYNAMIC 5

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QTableWidget>
#include <QHeaderView>
#include "newprojectdialog.h"
#include "settingsdialog.h"
#include "treeview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString pjName = "项目");
    ~MainWindow();
    QString projectName;

public slots:
    void newProject();
    void projectSettings();

private:
    void createLayout();
    void createMenu();
    void createAction();

    void createFileTree(TreeView *treeview);
    void createReportFiletree(TreeView *treeview);
    void createTaskFileTree(TreeView *treeview);

    QMenu *fileMenu;
    QAction *fileNew;
    QAction *fileOpen;
    QAction *fileClose;
    QAction *fileSave;
    QAction *fileSaveAs;

    QMenu *editMenu;
    QAction *undo;
    QAction *redo;
    QAction *cut;
    QAction *copy;
    QAction *paste;
    QAction *search;

    QMenu *viewMenu;
    QAction *projectView;
    QAction *processView;
    QAction *reportView;
    QAction *statusView;
    QAction *scriptView;

    QAction *messageView;
    QMenu *messageViewSubMenu;
    QAction *sysConsole;
    QAction *sysConsoleError;
    QAction *sysConsoleWarning;
    QAction *testConsoleError;
    QAction *testConsoleWarning;

    QAction *toolBar;
    QAction *statusBar;
    QAction *fileDirectory;
    QMenu *fileDirectorySubMenu;
    QActionGroup *fileDirectoryGroup;
    QAction *absolutePath;
    QAction *relativePath;
    QAction *saveView;
    QAction *loadView;
    QAction *font;

    QMenu *projectMenu;
    QAction *projectNew;
    QAction *projectOpen;
    QAction *projectClose;
    QAction *projectSave;
    QAction *projectQuit;
    QAction *projectRecent;
    QAction *projectClean;
    QAction *versionControl;
    QAction *projectProperty;

    QMenu *windowMenu;
    QAction *windowClose;
    QAction *windowMinimize;
    QActionGroup *layoutActionGroup;
    QAction *layoutHorizontal;
    QAction *layoutVertical;

    QMenu *helpMenu;
    QAction *about;
};

#endif // MAINWINDOW_H

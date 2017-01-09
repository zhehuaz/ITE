#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "treeview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createLayout();
    void createMenu();
    void createAction();

    void createFileTree(TreeView *treeview);

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

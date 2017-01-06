#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createMenu();
    void createAction();

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
    QAction *toolBar;
    QAction *statusBar;
    QAction *fileDirectory;
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
    QAction *layoutHorizontal;
    QAction *layoutVertical;

    QMenu *helpMenu;
    QAction *about;
};

#endif // MAINWINDOW_H

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
    QAction *fileOpenAction;
    QAction *fileCloseAction;
};

#endif // MAINWINDOW_H

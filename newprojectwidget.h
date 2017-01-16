#ifndef NEWPROJECTWIDGET_H
#define NEWPROJECTWIDGET_H

#include <QWidget>

class NewProjectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NewProjectWidget(QWidget *parent = 0);

public:
    virtual void onNext();
};

#endif // NEWPROJECTWIDGET_H

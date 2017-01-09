#include "treeview.h"

TreeView::TreeView() : QTreeView()
{

}

QList<QStandardItem*> TreeView::returnTheItems()
{
    return model->findItems("*", Qt::MatchWildcard | Qt::MatchRecursive);
}

void TreeView::iterateOverItems()
{
    QList<QStandardItem*> list = returnTheItems();

    foreach (QStandardItem* item, list) {
        qDebug() << item->text();
    }
}

void TreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QModelIndex index0 = currentIndex();
        qDebug() << index0.data().toString();
    }
}

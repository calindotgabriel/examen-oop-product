#include "appwindow.h"

#include <QStandardItemModel>
#include <QString>

AppWindow::AppWindow(ProductCtrl* ctrl, QWidget *parent)
    : QWidget(parent), ctrl(ctrl)
{
    holder.setupUI(this);

    load();
}

void AppWindow::load() {
    std::vector<Product> products = ctrl->getSorted();

    int k = 0;
    QStandardItemModel* model = new QStandardItemModel(products.size(), 3);
    for (Product& p : products) {
        QString qId = QString::number(p.getId());
        QString qName = QString::fromStdString(p.getName());
        QString qQty = QString::number(p.getQty());

        QStandardItem* idItem = new QStandardItem(qId);
        QStandardItem* nameItem = new QStandardItem(qName);
        QStandardItem* qtyItem = new QStandardItem(qQty);

        model->setItem(k, 0, idItem);
        model->setItem(k, 1, nameItem);
        model->setItem(k, 2, qtyItem);
        k++;
    }

    holder.tableView->setModel(model);
    holder.tableView->setColumnHidden(0, true);
    holder.tableView->model()->setHeaderData(1, Qt::Horizontal, "Name");
    holder.tableView->model()->setHeaderData(2, Qt::Horizontal, "Role");

    holder.chartsWidget->setValues(ctrl->getAll());
}

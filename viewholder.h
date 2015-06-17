#ifndef VIEWHOLDER
#define VIEWHOLDER

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QTableView>

#include "chartswidget.h"

class ViewHolder
{
public:
    QVBoxLayout* mainLayout;
    QTableView* tableView;
    QPushButton* updateBtn;
    ChartsWidget* chartsWidget;


    void setupUI(QWidget* parent) {
        mainLayout = new QVBoxLayout();
        parent->setLayout(mainLayout);

        tableView = new QTableView();
        mainLayout->addWidget(tableView);

        chartsWidget = new ChartsWidget();
        mainLayout->addWidget(chartsWidget);
    }
};

#endif // VIEWHOLDER


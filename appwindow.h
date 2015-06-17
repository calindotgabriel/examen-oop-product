#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>

#include "viewholder.h"
#include "productctrl.h"

class AppWindow : public QWidget
{
    Q_OBJECT
private:
    ViewHolder holder;
    ProductCtrl* ctrl;
public:
    explicit AppWindow(ProductCtrl* ctrl, QWidget *parent = 0);
    void load();
signals:

public slots:
};

#endif // APPWINDOW_H

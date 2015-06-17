#ifndef CHARTSWIDGET_H
#define CHARTSWIDGET_H

#include <QWidget>
#include <vector>
#include "product.h"

class ChartsWidget : public QWidget
{
    Q_OBJECT
private:
    std::vector<Product> products;
public:
    ChartsWidget(QWidget *parent = 0);
    void setValues(std::vector<Product> products);

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // CHARTSWIDGET_H

#include "chartswidget.h"

#include<QPainter>


ChartsWidget::ChartsWidget(QWidget *parent)
    :QWidget(parent){
    setFixedSize(QSize(300, 200));
}


void ChartsWidget::setValues(std::vector<Product> products) {
    this->products = products;
    update();
}

void ChartsWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    int w = width();
    int h = height();
    int baselineY = h - 100;
    int barWidth = 50;

    painter.drawLine(0, baselineY + 2, w, baselineY + 2);

    for (size_t i = 0; i < products.size(); i++) {
        int barX = i * barWidth + barWidth / 2;
//        painter.drawLine(barX, baselineY - frequencies[i], barX, baselineY);
        painter.drawRect(barX, baselineY - products[i].getQty() - 1, barWidth / 2, products[i].getQty());
        painter.drawText(barX, baselineY + 20, QString::fromStdString(products[i].getName()));
        painter.drawText(barX, baselineY + 40, QString::number(products[i].getQty()));
    }
}


#ifndef PRODUCTCTRL_H
#define PRODUCTCTRL_H

#include "productrepo.h"

class ProductCtrl
{
private:
    ProductRepo* repo;
public:
    ProductCtrl(ProductRepo* repo);
    std::vector<Product> getAll();
    std::vector<Product> getSorted();
    std::vector<long> getQtys();
};

#endif // PRODUCTCTRL_H

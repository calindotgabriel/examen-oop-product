#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#include <string>
#include <vector>
#include <mutex>
#include <thread>

#include "product.h"

class ProductRepo
{
private:
    std::string fIdName;
    std::string fNameQty;
    std::vector<Product> products;

    void _load();
    void _save();

public:
    ProductRepo(std::string fIdName, std::string fNameQty);
    ProductRepo();
    std::string& getFileNameIdName();
    std::string& getFileNameIdQty();
    std::vector<Product> getProducts();
    Product& findByID(int id);
};

#endif // PRODUCTREPO_H

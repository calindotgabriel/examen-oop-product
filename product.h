#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    int id;
    std::string name;
    long qty;
public:
    Product();
    Product(int id, std::string name, long qty);
    int getId();
    void setId(int id);
    std::string getName();
    void setName(std::string name);
    long getQty();
    void setQty(long qty);
};

#endif // PRODUCT_H

#include "productrepo.h"

#include <iostream>
#include <fstream>
#include <exception>

ProductRepo::ProductRepo()
{

}

ProductRepo::ProductRepo(std::string fIdName,
                         std::string fNameQty)
    : fIdName(fIdName), fNameQty(fNameQty)
{
    std::thread load(&ProductRepo::_load, this);
    load.join();
}

std::string& ProductRepo::getFileNameIdName() {
    return fIdName;
}

std::string& ProductRepo::getFileNameIdQty() {
    return fNameQty;
}

std::vector<Product> ProductRepo::getProducts() {
    return products;
}

Product& ProductRepo::findByID(int id) {
    for (Product& p : products) {
        if (p.getId() == id) {
            return p;
        }
    }
    throw std::exception();
}

void ProductRepo::_load(){

    // ****** {id}, {name} ******
    if (getFileNameIdName().empty()) {
        return;
    }

    std::ifstream loaderIdNameProducts(getFileNameIdName());

    if (!loaderIdNameProducts) {
        std::cout << "Can't read first file\n";
        return;
    }

    bool stillReading = true;
    while (stillReading) {
        Product* p = new Product;

        int id;
        std::string name;

        if (loaderIdNameProducts >> id >> name) {
            p->setId(id);
            p->setName(name);
            products.push_back(*p);
        } else {
            stillReading = false;
        }
    }

    loaderIdNameProducts.close();


    // ****** {id}, {qty} ********



    if (getFileNameIdQty().empty()) {
        return;
    }


    std::ifstream loaderIdQtyProducts(getFileNameIdQty());

    if (!loaderIdQtyProducts) {
        std::cout << "Can't read first file\n";
        return;
    }

    stillReading = true;
    while (stillReading) {
        int id;
        long qty;

        if (loaderIdQtyProducts >> id >> qty) {
            try {
                Product& p = findByID(id);
//                std::cout << "Found " << p.getName() <<"\n" ;
                p.setQty(qty);
            } catch (std::exception e) {
                std::cout << "No product with id: " << id <<"\n";
            }

        } else {

            stillReading = false;
        }
    }
}


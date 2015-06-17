#include "product.h"

Product::Product() : id(0), name(""), qty(0.0) { }

Product::Product(int id, std::string name, long qty):
    id(id), name(name), qty(qty) {  }

int Product::getId() {
    return id;
}

void Product::setId(int id) {
    this->id = id;
}

std::string Product::getName() {
    return name;
}

void Product::setName(std::string name) {
    this->name = name;
}

long Product::getQty() {
    return qty;
}

void Product::setQty(long qty) {
    this->qty = qty;
}

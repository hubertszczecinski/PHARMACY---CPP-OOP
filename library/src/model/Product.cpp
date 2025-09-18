#include "model/Product.h"

double Product::getCostBeforeDiscount() const {
    return costBeforeDiscount;
}

const std::string &Product::getProductName() const {
    return productName;
}

unsigned int Product::getProductID() const {
    return productID;
}

bool Product::isOrdered() const {
    return ordered;
}

bool Product::isSold() const {
    return sold;
}

void Product::setCostBeforeDiscount(double newCostBeforeDiscount) {
    if(newCostBeforeDiscount > 0)
        Product::costBeforeDiscount = newCostBeforeDiscount;
}

void Product::setProductName(const std::string &newProductName) {
    if(!newProductName.empty())
        Product::productName = newProductName;
}

Product::Product(double costBeforeDiscount, const std::string &productName, unsigned int productID)
        : costBeforeDiscount(costBeforeDiscount), productName(productName), productID(productID) {}

Product::~Product() {

}

std::string Product::getInfo() {
    return "Product Name: " + productName + " Cost Before Discount: " + std::to_string(costBeforeDiscount) + " Product ID:" + std::to_string(productID);
}

void Product::setOrdered(bool newOrdered) {
    Product::ordered = newOrdered;
}

void Product::setSold(bool newSold) {
    Product::sold = newSold;
}

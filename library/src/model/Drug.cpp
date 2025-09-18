#include <string>
#include "model/Product.h"
#include "model/Drug.h"

Drug::Drug(double costBeforeDiscount, const std::string &productName, unsigned int productId, bool perscribed)
        : Product(costBeforeDiscount, productName, productId), perscribed(perscribed) {}

Drug::~Drug() {

}

std::string Drug::getInfo() {
    return Product::getInfo() + " Is perscribed?: " + std::to_string(perscribed);
}


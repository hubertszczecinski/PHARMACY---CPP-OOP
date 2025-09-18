#include <string>
#include "model/Product.h"
#include "model/Supplement.h"

Supplement::Supplement(double costBeforeDiscount, const std::__cxx11::basic_string<char> &productName,
                       unsigned int productId, unsigned int dose) : Product(costBeforeDiscount, productName, productId),
                                                                    dose(dose) {}

Supplement::~Supplement() {

}

std::string Supplement::getInfo() {
    return Product::getInfo() + " Dose: " + std::to_string(dose);
}

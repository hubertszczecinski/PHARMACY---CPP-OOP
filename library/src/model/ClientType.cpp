#include "model/ClientType.h"

double DefaultClient::applyDiscount(double price) const {
    return price;
}

std::string DefaultClient::getInfo() const {
    return "Default";
}

double RetiredClient::applyDiscount(double price) const {
    return price * 0.5;
}

std::string RetiredClient::getInfo() const {
    return "Retired";
}

ClientType::~ClientType() {

}

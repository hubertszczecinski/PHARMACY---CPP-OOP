#include "model/Order.h"
#include "model/Client.h"
#include "model/Product.h"

unsigned int Order::getId() const {
    return id;
}

const boost::posix_time::ptime &Order::getOrderTime() const {
    return orderTime;
}

const boost::posix_time::ptime &Order::getFinalizationTime() const {
    return finalizationTime;
}

Order::Order(unsigned int id, const pt::ptime &orderTime, const ProductPtr &product, const ClientPtr &client) : id(id),
                                                                                                                orderTime(
                                                                                                                        orderTime),
                                                                                                                product(product),
                                                                                                                client(client) {
    product->setOrdered(true);
    if(orderTime == pt::not_a_date_time)
        this->orderTime = pt::second_clock::local_time();
    this->finalizationTime = pt::not_a_date_time;
}

Order::~Order() {

}

std::string Order::getInfo() {
    std::stringstream begin;
    begin << orderTime;
    std::stringstream end;
    end << finalizationTime;
    return "Order ID: " + std::to_string(id) + " " + client->getInfo() + " " + product->getInfo() + " Order Time:" + begin.str() + " Finalization Time:" + end.str();
}

double Order::getOrderCost() const {
    return client->applyDiscount(product->getCostBeforeDiscount());
}

void Order::finalizeOrder(const pt::ptime &specifiedFinalizationTime) {
    bool isFinalized = false;
    if (this->finalizationTime == pt::not_a_date_time && specifiedFinalizationTime == pt::not_a_date_time) {
        this->finalizationTime = pt::second_clock::local_time();
        isFinalized = true;
    }
    else if (this->finalizationTime == pt::not_a_date_time && specifiedFinalizationTime <= this->orderTime) {
        this->finalizationTime = this->orderTime;
        isFinalized = true;
    }
    else if (this->finalizationTime == pt::not_a_date_time && specifiedFinalizationTime <= pt::second_clock::local_time()) {
        this->finalizationTime = specifiedFinalizationTime;
        isFinalized = true;
    }

    if(isFinalized) {
        product->setOrdered(false);
        product->setSold(true);
    }
}

const ProductPtr &Order::getProduct() const {
    return product;
}

const ClientPtr &Order::getClient() const {
    return client;
}



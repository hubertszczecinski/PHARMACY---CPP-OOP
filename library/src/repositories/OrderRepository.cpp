#include "repositories/OrderRepository.h"
#include "typedefs.h"
#include "model/Order.h"


OrderPtr OrderRepository::findOrderByIndex(unsigned int index) {
    if(orderRepo[index] != nullptr) {
        return orderRepo[index];
    }
    return nullptr;
}


bool OrderRepository::addOrder(OrderPtr order)
{
    if(order != nullptr)
    {
        orderRepo.push_back(order);
        return true;
    }
    return false;
}

bool OrderRepository::removeOrder(OrderPtr order) {
    if(order != nullptr)
    {
        for (unsigned int i = 0; i < orderRepo.size(); i++)
        {
            if (orderRepo[i] == order) {
                orderRepo.erase(orderRepo.begin() + i);
                return true;
            }
        }
    }
    return false;
}

std::vector<OrderPtr> OrderRepository::findBy(OrderPredicate predicate) const {
    std::vector<OrderPtr> found;
    for (unsigned int i = 0; i < orderRepo.size(); i++) {
        if (orderRepo[i] != nullptr && predicate(orderRepo[i])) {
            found.push_back(orderRepo[i]);
        }
    }
    return found;
}

OrderRepository::OrderRepository() {}

OrderRepository::~OrderRepository() {

}


unsigned int OrderRepository::getIlosc() const {
    return orderRepo.size();
}

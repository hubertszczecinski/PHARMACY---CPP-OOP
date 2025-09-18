#include <stdexcept>
#include "typedefs.h"
#include "managers/OrderManager.h"
#include "repositories/OrderRepository.h"
#include "model/Order.h"

OrderManager::OrderManager() {
    CurrentOrder = std::make_shared<OrderRepository>();
    OrderArchive = std::make_shared<OrderRepository>();
}


OrderManager::~OrderManager() = default;

OrderPtr OrderManager::registerOrder(const unsigned int id, const pt::ptime &orderTime, ProductPtr product,ClientPtr client) {
    auto order = std::make_shared<Order>(id, orderTime, product, client);

    bool isInCurrentList = !CurrentOrder->findBy([id](const OrderPtr &ptr)->bool{
        return ptr->getId() == id;
    }).empty();

    bool isInOrderArchive = !OrderArchive->findBy([id](const OrderPtr &ptr)->bool{
        return ptr->getId() == id;
    }).empty();

    if (!isInCurrentList) {
        if (!isInOrderArchive)
        {
            CurrentOrder->addOrder(order);
            OrderArchive->addOrder(order);
        }
        else
        {
            CurrentOrder->addOrder(order);
        }
    }
    else
    {
        throw std::logic_error("Zamowienie o podanym ID juz istnieje");
    }

    return order;
}

void OrderManager::unregisterOrder(const OrderPtr &order) {

    if(CurrentOrder->findBy([order](const OrderPtr &ptr)->bool{
        return ptr == order;
    }).empty())
    {
        throw std::logic_error("Zamowienie nie istnieje");
    }
    else
    {
        CurrentOrder->removeOrder(order);
    }
}

OrderPtr OrderManager::getOrderByOrderID(const unsigned int id) const {
    std::vector<OrderPtr> found = CurrentOrder->findBy([id](const OrderPtr &ptr)->bool{
        return ptr->getId() == id;
    });
    if(found.empty()){
        throw std::logic_error("Nie znaleziono zamowienia o podanym ID");
    } else {
        return found[0];
    }
}

std::vector<OrderPtr> OrderManager::findAllCurrentOrders() const {
    return CurrentOrder->findBy([](OrderPtr)->bool{
        return true;
    });
}

std::vector<OrderPtr> OrderManager::findAllArchivedOrders() const {
    return OrderArchive->findBy([](OrderPtr)->bool{
        return true;
    });
}






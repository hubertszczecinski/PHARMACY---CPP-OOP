//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_ORDERREPOSITORY_H
#define APTEKA_ORDERREPOSITORY_H

#include <memory>
#include <vector>
#include "model/Order.h"

class OrderRepository{
private:
    std::vector<std::shared_ptr<Order>> orderRepo;

public:
    bool addOrder(OrderPtr order);

    bool removeOrder(OrderPtr order);

    OrderPtr findOrderByIndex(unsigned int index);

    std::vector<OrderPtr> findBy(OrderPredicate predicate) const;

    OrderRepository();

    virtual ~OrderRepository();

    unsigned int getIlosc() const;

};
#endif //APTEKA_ORDERREPOSITORY_H

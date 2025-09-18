//
// Created by huber on 10.06.2024.
//

#ifndef APTEKA_ORDERMANAGER_H
#define APTEKA_ORDERMANAGER_H
#include "typedefs.h"
#include <vector>
#include <boost/date_time/posix_time/ptime.hpp>

namespace pt = boost::posix_time;

class OrderManager {
private:
    OrderRepositoryPtr CurrentOrder;
    OrderRepositoryPtr OrderArchive;

public:


    OrderManager();

    OrderPtr registerOrder(const unsigned int id, const pt::ptime &orderTime, ProductPtr product, ClientPtr client);

    void unregisterOrder(const OrderPtr &order);

    OrderPtr getOrderByOrderID(const unsigned int id) const;

    std::vector<OrderPtr> findAllCurrentOrders() const;

    std::vector<OrderPtr> findAllArchivedOrders() const;

    virtual ~OrderManager();
};

#endif //APTEKA_ORDERMANAGER_H

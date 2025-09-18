#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include "typedefs.h"
#include "managers/OrderManager.h"
#include "model/ClientType.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Drug.h"
#include "model/Supplement.h"
#include "model/Order.h"

namespace btt = boost::test_tools;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct OrderManagerFixture {
    OrderManager orderManager;
    ClientTypePtr defaultType;
    AddressPtr address;
    ClientPtr client;
    ProductPtr product1;
    ProductPtr product2;

    OrderManagerFixture() : defaultType(std::make_shared<DefaultClient>()),
                            address(std::make_shared<Address>("kolo","kwiatowa",7)),
                            client(std::make_shared<Client>("Hubert", "Szczecinski", 15523 , 2137, defaultType, address)),
                            product1(std::make_shared<Drug>(100, "Drug", 56, true)),
                            product2(std::make_shared<Supplement>(200, "Supplement", 87, 10)) {
    }

    ~OrderManagerFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(OrderManagerSuite, OrderManagerFixture)

    BOOST_AUTO_TEST_CASE(RegisterOrderTest) {
        BOOST_TEST(orderManager.findAllCurrentOrders().size() == 0);
        OrderPtr order = orderManager.registerOrder(6786, pt::not_a_date_time, product1, client);
        BOOST_TEST(orderManager.findAllCurrentOrders().size() == 1);
        BOOST_TEST(orderManager.findAllCurrentOrders()[0] == order);
        try {
            orderManager.registerOrder(6786, pt::not_a_date_time, product2, client);
        } catch (std::exception &wyjatek) {
            BOOST_TEST(std::string(wyjatek.what()) == "Zamowienie o podanym ID juz istnieje");
        }
        BOOST_TEST(orderManager.findAllCurrentOrders().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(UnregisterOrderTest) {
        OrderPtr order = orderManager.registerOrder(0007, pt::not_a_date_time, product1, client);
        BOOST_TEST(order != nullptr);
        BOOST_TEST(orderManager.findAllCurrentOrders().size() == 1);
        orderManager.unregisterOrder(order);
        BOOST_TEST(orderManager.findAllCurrentOrders().size() == 0);
        BOOST_TEST(orderManager.findAllArchivedOrders()[0] == order);
        BOOST_TEST(orderManager.findAllArchivedOrders().size() == 1);
        try {
            orderManager.unregisterOrder(order);
        } catch (std::exception &wyjatek) {
            BOOST_TEST(std::string(wyjatek.what()) == "Zamowienie nie istnieje");
        }
    }

    BOOST_AUTO_TEST_CASE(GetOrderByOrderIDTest) {
        OrderPtr order = orderManager.registerOrder(9, pt::not_a_date_time, product1, client);
        BOOST_TEST(order != nullptr);
        OrderPtr foundOrder = orderManager.getOrderByOrderID(9);
        BOOST_CHECK_EQUAL(foundOrder->getId(), 9);
        try {
            orderManager.getOrderByOrderID(11111);
        } catch (std::exception &wyjatek) {
            BOOST_TEST(std::string(wyjatek.what()) == "Nie znaleziono zamowienia o podanym ID");
        }
    }

    BOOST_AUTO_TEST_CASE(FindAllCurrentOrdersTest) {
        OrderPtr order1 = orderManager.registerOrder(1, pt::not_a_date_time, product1, client);
        OrderPtr order2 = orderManager.registerOrder(2, pt::not_a_date_time, product2, client);
        BOOST_TEST(order1 != nullptr);
        BOOST_TEST(order2 != nullptr);
        std::vector<std::shared_ptr<Order>> foundOrder1 = orderManager.findAllCurrentOrders();
        BOOST_CHECK_EQUAL(foundOrder1.size(), 2);
        orderManager.unregisterOrder(order1);
        orderManager.unregisterOrder(order2);
        std::vector<std::shared_ptr<Order>> foundOrder2 = orderManager.findAllCurrentOrders();
        BOOST_CHECK_EQUAL(foundOrder2.size(), 0);
    }

    BOOST_AUTO_TEST_CASE(FindAllArchivedOrdersTest) {
        OrderPtr order1 = orderManager.registerOrder(3, pt::not_a_date_time, product1, client);
        OrderPtr order2 = orderManager.registerOrder(4, pt::not_a_date_time, product2, client);
        BOOST_TEST(order1 != nullptr);
        BOOST_TEST(order2 != nullptr);
        std::vector<std::shared_ptr<Order>> foundOrder1 = orderManager.findAllArchivedOrders();
        BOOST_CHECK_EQUAL(foundOrder1.size(), 2);
        orderManager.unregisterOrder(order1);
        orderManager.unregisterOrder(order2);
        std::vector<std::shared_ptr<Order>> foundOrder2 = orderManager.findAllArchivedOrders();
        BOOST_CHECK_EQUAL(foundOrder2.size(), 2);

    }

BOOST_AUTO_TEST_SUITE_END()
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Order.h"
#include "repositories/OrderRepository.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include "model/ClientType.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Drug.h"
#include "model/Supplement.h"

namespace btt = boost::test_tools;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteOrderRepoFixture {
    ClientTypePtr defaultType;
    AddressPtr address;
    ClientPtr client;
    ProductPtr product1;
    ProductPtr product2;
    OrderPtr order1;
    OrderPtr order2;

    TestSuiteOrderRepoFixture() : defaultType(std::make_shared<DefaultClient>()),
                                  address(std::make_shared<Address>("kolo","kwiatowa",7)),
                                  client(std::make_shared<Client>("Hubert", "Szczecinski", 15523 , 2137, defaultType, address)),
                                  product1(std::make_shared<Drug>(100, "Drug", 001, true)),
                                  product2(std::make_shared<Supplement>(200, "Supplement", 002, 10)),
                                  order1(std::make_shared<Order>(001, pt::not_a_date_time, product1, client)),
                                  order2(std::make_shared<Order>(002, pt::not_a_date_time, product2, client)) {
    }

    ~TestSuiteOrderRepoFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteOrderRepository, TestSuiteOrderRepoFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        OrderRepository orderRepository;
        BOOST_TEST(orderRepository.getIlosc() == 0);
    }

    BOOST_AUTO_TEST_CASE(AddAndRemoveOrderTests) {
        OrderRepository orderRepository;
        BOOST_TEST(orderRepository.getIlosc() == 0);

        orderRepository.addOrder(order1);
        BOOST_TEST(orderRepository.getIlosc() == 1);
        orderRepository.addOrder(nullptr);
        BOOST_TEST(orderRepository.getIlosc() == 1);

        orderRepository.removeOrder(nullptr);
        BOOST_TEST(orderRepository.getIlosc() == 1);
        orderRepository.removeOrder(order1);
        BOOST_TEST(orderRepository.getIlosc() == 0);
    }

    BOOST_AUTO_TEST_CASE(FindTests) {
        OrderRepository orderRepository;
        orderRepository.addOrder(order1);
        orderRepository.addOrder(order2);
        BOOST_TEST(orderRepository.getIlosc() == 2);

        BOOST_TEST(orderRepository.findOrderByIndex(0) == order1);
        BOOST_TEST(orderRepository.findOrderByIndex(1) == order2);

        unsigned int id1 = 001;
        BOOST_TEST(orderRepository.findBy([id1](const OrderPtr &ptr)->bool{
            return ptr->getId() == id1;
        })[0] == order1);

        unsigned int id2 = 002;
        BOOST_TEST(orderRepository.findBy([id2](const OrderPtr &ptr)->bool{
            return ptr->getId() == id2;
        })[0] == order2);
    }

BOOST_AUTO_TEST_SUITE_END()

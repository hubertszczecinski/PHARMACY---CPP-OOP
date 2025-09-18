#include <boost/test/unit_test.hpp>
#include "model/Order.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Drug.h"
#include "model/Supplement.h"
#include "model/ClientType.h"

namespace btt = boost::test_tools;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteOrderFixture {
    const std::string testName = "Name";
    const std::string testSurname = "Surname";
    const unsigned int testPersonalID = 1212121212;
    const unsigned int testPhoneNumber = 234234234;
    const std::string testProductName = "Name";
    const unsigned int testProductId = 0001;
    const double testCostBeforeDiscount = 10;
    const unsigned int testId = 0001;

    AddressPtr testAddress;
    ClientTypePtr testClientType;
    ClientPtr testClient;
    ProductPtr testDrug;
    ProductPtr testSupplement;

    TestSuiteOrderFixture() : testAddress(std::make_shared<Address>("City", "Street", 1)),
                              testClientType(std::make_shared<DefaultClient>()),
                              testClient(std::make_shared<Client>(testName, testSurname, testPhoneNumber, testPersonalID, testClientType, testAddress)),
                              testDrug(std::make_shared<Drug>(testCostBeforeDiscount, testProductName, testProductId, true)),
                              testSupplement(std::make_shared<Supplement>(testCostBeforeDiscount, testProductName, testProductId, 10)) {

    }

    ~TestSuiteOrderFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteOrder, TestSuiteOrderFixture)

    /**
     * @brief Testy konstruktora parametrowego
     * Zawiera testy sprawdzajace czy kazda z wartosci zostala ustawiona poprawnie przez konstruktor
     */
    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        OrderPtr testOrder = std::make_shared<Order>(testId, pt::not_a_date_time, testDrug, testClient);
        BOOST_TEST(testOrder->getId() == testId);
        BOOST_TEST(testOrder->getClient() == testClient);
        BOOST_TEST(testOrder->getProduct() == testDrug);
        testOrder->finalizeOrder(testOrder->getFinalizationTime());
    }

    /**
     * @brief Testy oznaczenia produktu jako zamowiony
     */
    BOOST_AUTO_TEST_CASE(IsOrderedTests) {
        BOOST_TEST(testDrug->isOrdered() == false);
        OrderPtr testOrder = std::make_shared<Order>(testId, pt::not_a_date_time, testDrug, testClient);
        BOOST_TEST(testDrug->isOrdered() == true);
        testOrder->finalizeOrder(testOrder->getFinalizationTime());
    }

    /**
     * @brief Testy ustawienia orderTime
     */
    BOOST_AUTO_TEST_CASE(OrderTimeTests)
    {
        OrderPtr testOrder = std::make_shared<Order>(testId, pt::not_a_date_time, testDrug, testClient);
        pt::ptime now = pt::second_clock::local_time();
        BOOST_TEST_REQUIRE(!testOrder->getOrderTime().is_not_a_date_time());
        pt::time_period period = pt::time_period(testOrder->getOrderTime(), now);
        BOOST_TEST((period.length().hours()==0 && period.length().minutes()==0));
        testOrder->finalizeOrder(testOrder->getFinalizationTime());
    }

    /**
     * @brief Testy ustawienia finalizationTime
     */
    BOOST_AUTO_TEST_CASE(FinalizationTimeTests)
    {
        OrderPtr testOrder = std::make_shared<Order>(testId, pt::not_a_date_time, testDrug, testClient);
        testOrder->finalizeOrder(testOrder->getFinalizationTime());
        pt::ptime now = pt::second_clock::local_time();
        BOOST_TEST_REQUIRE(!testOrder->getFinalizationTime().is_not_a_date_time());
        BOOST_TEST_REQUIRE(testOrder->getFinalizationTime() >= testOrder->getOrderTime());
        pt::time_period period = pt::time_period(testOrder->getFinalizationTime(), now);
        BOOST_TEST((period.length().hours()==0 && period.length().minutes()==0));
    }

    /**
     * @brief Testy zrealizowania zmowienia
     */
    BOOST_AUTO_TEST_CASE(FinalizeOrderTests)
    {
        BOOST_TEST(testDrug->isOrdered() == false);
        BOOST_TEST(testDrug->isSold() == false);
        OrderPtr testOrder = std::make_shared<Order>(testId, pt::not_a_date_time, testDrug, testClient);
        BOOST_TEST(testDrug->isOrdered() == true);
        BOOST_TEST(testDrug->isSold() == false);
        testOrder->finalizeOrder(testOrder->getFinalizationTime());
        BOOST_TEST(testDrug->isOrdered() == false);
        BOOST_TEST(testDrug->isSold() == true);
    }

    /**
     * @brief Testy liczenia kosztu
     */
    BOOST_AUTO_TEST_CASE(GetOrderCostTests) {
        OrderPtr testOrder = std::make_shared<Order>(testId, pt::not_a_date_time, testSupplement, testClient);
        BOOST_TEST(testOrder->getOrderCost() == testClient->applyDiscount(testSupplement->getCostBeforeDiscount()));
        testOrder->finalizeOrder(testOrder->getFinalizationTime());
    }

BOOST_AUTO_TEST_SUITE_END()
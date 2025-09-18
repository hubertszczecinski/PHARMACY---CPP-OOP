#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Drug.h"
#include "model/Supplement.h"

namespace btt = boost::test_tools;

struct TestSuiteProductFixture {
    const std::string testProductName = "Name";
    const unsigned int testProductId = 0001;
    const double testCostBeforeDiscount = 10;

    ProductPtr testDrug;
    ProductPtr testSupplement;

    TestSuiteProductFixture() : testDrug(std::make_shared<Drug>(testCostBeforeDiscount, testProductName, testProductId, true)),
                                testSupplement(std::make_shared<Supplement>(testCostBeforeDiscount, testProductName, testProductId, 10)) {
    }

    ~TestSuiteProductFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteProduct, TestSuiteProductFixture)

    /**
     * @brief Testy konstruktora parametrowego
     * Zawiera testy sprawdzajace czy kazda z wartosci zostala ustawiona poprawnie przez konstruktor
     * Dodatkowo test bada poprawnosc getterow
     */
    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        BOOST_TEST(testProductName == testDrug->getProductName());
        BOOST_TEST(testProductId == testDrug->getProductID());
        BOOST_TEST(testCostBeforeDiscount == testDrug->getCostBeforeDiscount());

        BOOST_TEST(testProductName == testSupplement->getProductName());
        BOOST_TEST(testProductId == testSupplement->getProductID());
        BOOST_TEST(testCostBeforeDiscount == testSupplement->getCostBeforeDiscount());
    }

    /**
     * @brief Test settera setProductName
     * Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setProductNameTests) {
        testDrug->setProductName("Name2");
        BOOST_TEST(testDrug->getProductName() == "Name2");
        testDrug->setProductName("");
        BOOST_TEST(testDrug->getProductName() == "Name2");
    }

    /**
     * @brief Test settera setCostBeforeDiscount
     *Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setCostBeforeDiscountTests) {
        testDrug->setCostBeforeDiscount(20);
        BOOST_TEST(testDrug->getCostBeforeDiscount() == 20);
        testDrug->setCostBeforeDiscount(-10);
        BOOST_TEST(testDrug->getCostBeforeDiscount() == 20);
    }

    /**
     * @brief Test settera setOrdered
     */
    BOOST_AUTO_TEST_CASE(setsetOrderedTests) {
        BOOST_TEST(testDrug->isOrdered() == false);
        testDrug->setOrdered(true);
        BOOST_TEST(testDrug->isOrdered() == true);
    }

    /**
     * @brief Test settera setSold
     */
    BOOST_AUTO_TEST_CASE(setsetSoldTests) {
        BOOST_TEST(testDrug->isSold() == false);
        testDrug->setSold(true);
        BOOST_TEST(testDrug->isSold() == true);
    }

BOOST_AUTO_TEST_SUITE_END()
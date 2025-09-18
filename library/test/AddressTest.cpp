#include <boost/test/unit_test.hpp>
#include "model/Address.h"
#include "typedefs.h"
namespace btt = boost::test_tools;

struct TestSuiteAddressFixture {
    const std::string testCity = "City";
    const std::string testStreet = "Street";
    const unsigned int testNumber = 15;
    AddressPtr testAddress;

    TestSuiteAddressFixture() : testAddress(std::make_shared<Address>(testCity, testStreet, testNumber)) {
    }

    ~TestSuiteAddressFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    /**
     * @brief Testy konstruktora parametrowego
     * Zawiera trzy testy sprawdzajace czy kazda z wartosci zostala ustawiona poprawnie przez konstruktor
     * Dodatkowo test bada poprawnosc getterow
     */
    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        BOOST_TEST(testAddress->getCity() == testCity);
        BOOST_TEST(testAddress->getStreet() == testStreet);
        BOOST_TEST(testAddress->getNumber() == testNumber);
    }

    /**
     * @brief Test settera setCity
     * Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setCityTests) {
        testAddress->setCity("City2");
        BOOST_TEST(testAddress->getCity() == "City2");
        testAddress->setCity("");
        BOOST_TEST(testAddress->getCity() == "City2");
    }

    /**
     * @brief Test settera setStreet
     * Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setStreetTests) {
        testAddress->setStreet("Street2");
        BOOST_TEST(testAddress->getStreet() == "Street2");
        testAddress->setCity("");
        BOOST_TEST(testAddress->getStreet() == "Street2");
    }

    /**
     * @brief Test settera setNumber
     * Zawiera test pozytywny
     */
    BOOST_AUTO_TEST_CASE(setNumberTests) {
        testAddress->setNumber(34);
        BOOST_TEST(testAddress->getNumber() == 34);
    }

BOOST_AUTO_TEST_SUITE_END()
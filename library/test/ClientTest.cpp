#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "typedefs.h"
#include "model/ClientType.h"

namespace btt = boost::test_tools;

struct TestSuiteClientFixture {
    const std::string testName = "Name";
    const std::string testSurname = "Surname";
    const unsigned int testPersonalID = 1212121212;
    const unsigned int testPhoneNumber = 234234234;
    AddressPtr testAddress1;
    AddressPtr testAddress2;
    ClientTypePtr testType1;
    ClientTypePtr testType2;
    ClientPtr testClient;

    TestSuiteClientFixture() : testAddress1(std::make_shared<Address>("City1", "Street1", 1)),
                               testAddress2(std::make_shared<Address>("City2", "Street2", 2)),
                               testType1(std::make_shared<DefaultClient>()), testType2(std::make_shared<RetiredClient>()),
                               testClient(std::make_shared<Client>(testName, testSurname, testPhoneNumber, testPersonalID, testType1, testAddress1)) {
    }

    ~TestSuiteClientFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    /**
     * @brief Testy konstruktora parametrowego
     * Zawiera testy sprawdzajace czy kazda z wartosci zostala ustawiona poprawnie przez konstruktor
     */
    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        BOOST_TEST(testName == testClient->getName());
        BOOST_TEST(testSurname == testClient->getSurname());
        BOOST_TEST(testPhoneNumber == testClient->getPhoneNumber());
        BOOST_TEST(testPersonalID == testClient->getPersonalID());
        BOOST_TEST(testAddress1 == testClient->getAddress());
        BOOST_TEST(testType1 == testClient->getClientType());
    }

    /**
     * @brief Test settera setFirstName
     * Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setNameTests) {
        testClient->setName("Kordian");
        BOOST_TEST(testClient->getName() == "Kordian");
        testClient->setName("");
        BOOST_TEST(testClient->getName() == "Kordian");
    }

    /**
     * @brief Test settera setSurname
     * Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setSurnameTests) {
        testClient->setSurname("Mickiewicz");
        BOOST_TEST(testClient->getSurname() == "Mickiewicz");
        testClient->setSurname("");
        BOOST_TEST(testClient->getSurname() == "Mickiewicz");
    }

    /**
     * @brief Test settera setPhoneNumber
     * Zawiera test pozytywny
     */
    BOOST_AUTO_TEST_CASE(setPhoneNumberTests) {
        testClient->setPhoneNumber(111111111);
        BOOST_TEST(testClient->getPhoneNumber() == 111111111);
    }

    /**
     * @brief Test settera setAddress
     * Zawiera test pozytywny i test negatywny
     */
    BOOST_AUTO_TEST_CASE(setAddress) {
        testClient->setAddress(testAddress2);
        BOOST_TEST(testAddress2 == testClient->getAddress());
        testClient->setAddress(nullptr);
        BOOST_TEST(testAddress2 == testClient->getAddress());
    }

    /**
     * @brief Testy settera setClientType
     * Zawiera test pozytywny
     */
    BOOST_AUTO_TEST_CASE(setClientTypeTests) {
        testClient->setClientType(testType2);
        BOOST_TEST(testType2 == testClient->getClientType());
    }



    /**
     * @brief Testy metody applyDiscount
     */
    BOOST_AUTO_TEST_CASE(applyDiscountTests) {
        BOOST_TEST(testType1 == testClient->getClientType());
        BOOST_TEST(testClient->applyDiscount(100) == 100);
        testClient->setClientType(testType2);
        BOOST_TEST(testType2 == testClient->getClientType());
        BOOST_TEST(testClient->applyDiscount(100) == 50);
    }

BOOST_AUTO_TEST_SUITE_END()
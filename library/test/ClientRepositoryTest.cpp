#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/ClientType.h"
#include "repositories/ClientRepository.h"
#include "model/Address.h"
#include "model/Client.h"


struct TestSuiteClientRepoFixture {
    ClientTypePtr defaultType;
    AddressPtr address;
    ClientPtr client1;          
    ClientPtr client2;

    TestSuiteClientRepoFixture() :  defaultType(std::make_shared<DefaultClient>()),
                                    address(std::make_shared<Address>("kolo","kwiatowa",7)),
                                    client1(std::make_shared<Client>("Hubert", "Szczecinski", 15523 , 2137, defaultType, address)),
                                    client2(std::make_shared<Client>("Hanna", "Dudek", 24352 , 100, defaultType, address)) {
    }

    ~TestSuiteClientRepoFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository, TestSuiteClientRepoFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        ClientRepository clientRepository;
        BOOST_TEST(clientRepository.getIlosc() == 0);
    }

    BOOST_AUTO_TEST_CASE(AddAndRemoveClientTests) {
        ClientRepository clientRepository;
        BOOST_TEST(clientRepository.getIlosc() == 0);

        clientRepository.addClient(client1);
        BOOST_TEST(clientRepository.getIlosc() == 1);
        clientRepository.addClient(nullptr);
        BOOST_TEST(clientRepository.getIlosc() == 1);

        clientRepository.removeClient(nullptr);
        BOOST_TEST(clientRepository.getIlosc() == 1);
        clientRepository.removeClient(client1);
        BOOST_TEST(clientRepository.getIlosc() == 0);
    }

    BOOST_AUTO_TEST_CASE(FindTests) {
        ClientRepository clientRepository;
        clientRepository.addClient(client1);
        clientRepository.addClient(client2);
        BOOST_TEST(clientRepository.getIlosc() == 2);

        BOOST_TEST(clientRepository.findClientByIndex(0) == client1);
        BOOST_TEST(clientRepository.findClientByIndex(1) == client2);

        unsigned int personalId = 2137;
        BOOST_TEST(clientRepository.findBy([personalId](const ClientPtr &ptr)->bool{
            return ptr->getPersonalID() == personalId;
        })[0] == client1);

        unsigned int phoneNumber = 24352;
        BOOST_TEST(clientRepository.findBy([phoneNumber](const ClientPtr &ptr)->bool{
            return ptr->getPhoneNumber() == phoneNumber;
        })[0] == client2);
    }

BOOST_AUTO_TEST_SUITE_END()
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "managers/ClientManager.h"
#include "model/ClientType.h"
#include "model/Address.h"
#include "model/Client.h"

struct ClientManagerFixture {
    ClientManager clientManager;
    ClientTypePtr defaultType;
    AddressPtr address;

    ClientManagerFixture() : defaultType(std::make_shared<DefaultClient>()),
                             address(std::make_shared<Address>("kolo","kwiatowa",7)) {
    }

    ~ClientManagerFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(ClientManagerSuite, ClientManagerFixture)

    BOOST_AUTO_TEST_CASE(RegisterClientTest) {
        ClientPtr client = clientManager.registerClient("Hania", "Dudek",12345, 12345, defaultType, address);
        BOOST_TEST(clientManager.findAllListClients().size() == 1);
        BOOST_TEST(clientManager.findAllListClients()[0] == client);
        try {
            clientManager.registerClient("Name", "Surname", 11111 , 12345 , defaultType, address);
        } catch (std::exception &wyjatek) {
            BOOST_TEST(std::string(wyjatek.what()) == "Klient o podanym ID juz istnieje w liscie klientow");
        }
        BOOST_TEST(clientManager.findAllListClients().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        ClientPtr client = clientManager.registerClient("Ktoto", "Taki", 1245,124551, defaultType, address);
        BOOST_TEST(client != nullptr);
        BOOST_TEST(clientManager.findAllListClients().size() == 1);
        clientManager.unregisterClient(client);
        BOOST_TEST(clientManager.findAllListClients().size() == 0);
        BOOST_TEST(clientManager.findAllArchivedClients()[0] == client);
        BOOST_TEST(clientManager.findAllArchivedClients().size() == 1);
        try {
            clientManager.unregisterClient(client);
        } catch (std::exception &wyjatek) {
            BOOST_TEST(std::string(wyjatek.what()) == "Client nie istnieje w liscie klientow");
        }
    }

    BOOST_AUTO_TEST_CASE(GetClientByPersonalIDTest) {
        ClientPtr client = clientManager.registerClient("Anna", "Kowalska", 51613, 12345, defaultType, address);
        BOOST_TEST(client != nullptr);
        ClientPtr foundClient = clientManager.getClientByPersonalID(12345);
        BOOST_CHECK_EQUAL(foundClient->getPersonalID(), 12345);
        try {
            clientManager.getClientByPersonalID(11111);
        } catch (std::exception &wyjatek) {
            BOOST_TEST(std::string(wyjatek.what()) == "Nie znaleziono osoby o podanym ID w liscie klientow");
        }
    }

    BOOST_AUTO_TEST_CASE(FindAllListClientsTest) {
        ClientPtr client1 = clientManager.registerClient("Walaszek", "Poc", 1234, 124567, defaultType,address);
        ClientPtr client2 = clientManager.registerClient("S[pejson", "Kloc", 1234, 1234567, defaultType, address);
        BOOST_TEST(client1 != nullptr);
        BOOST_TEST(client2 != nullptr);
        std::vector<std::shared_ptr<Client>> foundClient1 = clientManager.findAllListClients();
        BOOST_CHECK_EQUAL(foundClient1.size(), 2);
        clientManager.unregisterClient(client1);
        clientManager.unregisterClient(client2);
        std::vector<std::shared_ptr<Client>> foundClient2 = clientManager.findAllListClients();
        BOOST_CHECK_EQUAL(foundClient2.size(), 0);
    }

    BOOST_AUTO_TEST_CASE(FindAllArchivedClientsTest) {
        ClientPtr client1 = clientManager.registerClient("Walaszek", "Poc", 1234, 124567, defaultType,address);
        ClientPtr client2 = clientManager.registerClient("S[pejson", "Kloc", 1234, 1234567, defaultType, address);
        BOOST_TEST(client1 != nullptr);
        BOOST_TEST(client2 != nullptr);
        std::vector<std::shared_ptr<Client>> foundClient1 = clientManager.findAllArchivedClients();
        BOOST_CHECK_EQUAL(foundClient1.size(), 2);
        clientManager.unregisterClient(client1);
        clientManager.unregisterClient(client2);
        std::vector<std::shared_ptr<Client>> foundClient2 = clientManager.findAllArchivedClients();
        BOOST_CHECK_EQUAL(foundClient2.size(), 2);

    }

BOOST_AUTO_TEST_SUITE_END()
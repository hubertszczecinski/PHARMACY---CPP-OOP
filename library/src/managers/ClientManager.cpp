
#include <stdexcept>
#include <memory>
#include <vector>
#include <fstream>
#include "managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include "model/Client.h"

ClientManager::ClientManager() {
    ClientList = std::make_shared<ClientRepository>();
    ClientArchive = std::make_shared<ClientRepository>();
}

ClientManager::~ClientManager() = default;



void ClientManager::unregisterClient(const ClientPtr &client) {

    bool clientExists = !ClientList->findBy([client](const ClientPtr &ptr) -> bool {
        return ptr == client;
    }).empty();

    if (!clientExists)
    {

        throw std::logic_error("Client nie istnieje w liscie klientow");
    }
    else {
        ClientList->removeClient(client);
        std::string path = "../../dysk/ClientListDisk";
        std::string path1 = "../../dysk/temp";
        std::ifstream inFile(path);
        std::ofstream tempFile(path1);

        if (!inFile.is_open() || !tempFile.is_open())
        {
            throw std::ios_base::failure("Nie mozna otworzyc pliku clients do odczytu lub temp_clients do zapisu.");
        }

        std::string line;
        bool removed = false;
        while (std::getline(inFile, line)) {
            if (line.find(client->getInfo()) == std::string::npos) {
                tempFile << line << std::endl;
            } else {
                removed = true;
            }
        }

        inFile.close();
        tempFile.close();

        if (!removed) {
            throw std::logic_error("Nie znaleziono klienta w pliku ClientListDisk.");
        }

        inFile.open(path, std::ofstream::out | std::ofstream::trunc);
        inFile.close();

        inFile.open(path1);
        tempFile.open(path);

        if (!inFile.is_open() || !tempFile.is_open()) {
            throw std::ios_base::failure("Nie mozna otworzyc pliku clients lub temp_clients do zapisu.");
        }

        while (std::getline(inFile, line)) {
            tempFile << line << std::endl;
        }

        inFile.close();
        tempFile.close();

    }
}



ClientPtr ClientManager::registerClient(const std::string &name, const std::string &surname, const unsigned int &phoneNumber,
                              const unsigned int &personalID, ClientTypePtr clientType, AddressPtr address) {

    auto client = std::make_shared<Client>(name, surname, phoneNumber, personalID, clientType, address);

    bool existsInClientList = !ClientList->findBy([personalID](const ClientPtr &ptr) -> bool {
        return ptr->getPersonalID() == personalID;
    }).empty();

    bool existsInArchive = !ClientArchive->findBy([personalID](const ClientPtr &ptr) -> bool {
        return ptr->getPersonalID() == personalID;
    }).empty();

    if (!existsInClientList) {
        if (!existsInArchive) {
            ClientList->addClient(client);
            ClientArchive->addClient(client);
            std::string Path = "../../dysk/ClientListDisk";
            std::string Path2 = "../../dysk/ClientArchiveDisk";
            std::ofstream outFile(Path, std::ios_base::app);
            if (outFile.is_open()) {
                outFile << client->getInfo() << std::endl;
                outFile.close();
            } else {
                throw std::ios_base::failure("Nie mozna otworzyc pliku do zapisu.");
            }
            std::ofstream outFile2(Path2, std::ios_base::app);
            if (outFile2.is_open()) {
                outFile2 << client->getInfo() << std::endl;
                outFile2.close();
            } else {
                throw std::ios_base::failure("Nie mozna otworzyc pliku do zapisu.");
            }
        }
        else
        {
            ClientList->addClient(client);
            std::string Path = "../../dysk/ClientListDisk";
            std::ofstream outFile(Path, std::ios_base::app);
            if (outFile.is_open()) {
                outFile << client->getInfo() << std::endl;
                outFile.close();
            } else {
                throw std::ios_base::failure("Nie mozna otworzyc pliku do zapisu.");
            }
        }
    }
    else
    {
        throw std::logic_error("Klient o podanym ID juz istnieje w liscie klientow");
    }

    return client;
}

ClientPtr ClientManager::getClientByPersonalID(const unsigned int &personalID) const {

    std::vector<ClientPtr> found = ClientList->findBy([personalID](const ClientPtr &ptr)->bool{
        return ptr->getPersonalID() == personalID;
    });
    if(found.empty())
    {
        throw std::logic_error("Nie znaleziono osoby o podanym ID w liscie klientow");
    }
    else {
        return found[0];
    }
}

std::vector<ClientPtr> ClientManager::findAllListClients() const {
    return ClientList->findBy([](ClientPtr)->bool{
        return true;
    });
}

std::vector<ClientPtr> ClientManager::findAllArchivedClients() const {
    return ClientArchive->findBy([](ClientPtr)->bool{
        return true;
    });
}










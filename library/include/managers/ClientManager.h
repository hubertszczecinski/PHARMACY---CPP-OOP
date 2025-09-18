//
// Created by huber on 10.06.2024.
//

#ifndef APTEKA_CLIENTMANAGER_H
#define APTEKA_CLIENTMANAGER_H
#include "typedefs.h"
#include <string>
#include <vector>
#include "repositories/ClientRepository.h"

class ClientManager {
private:
    ClientRepositoryPtr ClientList;
    ClientRepositoryPtr ClientArchive;

public:
    ClientManager();

    ClientPtr registerClient(const std::string &name, const std::string &surname, const unsigned int &phoneNumber, const unsigned int &personalID, ClientTypePtr clientType, AddressPtr address);

    void unregisterClient(const ClientPtr &client);

    ClientPtr getClientByPersonalID(const unsigned int &personalID) const;

    std::vector<ClientPtr> findAllListClients() const;

    std::vector<ClientPtr> findAllArchivedClients() const;

    virtual ~ClientManager();
};
#endif //APTEKA_CLIENTMANAGER_H

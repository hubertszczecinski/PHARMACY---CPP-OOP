#include "repositories/ClientRepository.h"
#include "typedefs.h"

bool ClientRepository::addClient(ClientPtr client) {
        if (client != nullptr) {
            clientRepo.push_back(client);
            return true;
        }
        return false;
}

bool ClientRepository::removeClient(ClientPtr client) {
    if(client != nullptr) {
        for (unsigned int i = 0; i < clientRepo.size(); i++) {
            if (clientRepo[i] == client) {
                clientRepo.erase(clientRepo.begin() + i);
                return true;
            }
        }
    }
    return false;
}

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {}

ClientPtr ClientRepository::findClientByIndex(unsigned int index) {
    if(clientRepo[index] != nullptr)
    {
        return clientRepo[index];
    }
    return nullptr;
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < clientRepo.size(); i++) {
        if (clientRepo[i] != nullptr && predicate(clientRepo[i])) {
            found.push_back(clientRepo[i]);
        }
    }
    return found;
}

unsigned int ClientRepository::getIlosc() const {
    return clientRepo.size();
}



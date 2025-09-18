//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_CLIENTREPOSITORY_H
#define APTEKA_CLIENTREPOSITORY_H
#include "typedefs.h"
#include <memory>
#include <vector>

class Client;

class ClientRepository{
private:
    std::vector<ClientPtr> clientRepo;
public:
    ClientRepository();

    ~ClientRepository();

    bool addClient(ClientPtr client);

    bool removeClient(ClientPtr client);

    ClientPtr findClientByIndex(unsigned int index);

    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;

    unsigned int getIlosc() const;
};
#endif //APTEKA_CLIENTREPOSITORY_H

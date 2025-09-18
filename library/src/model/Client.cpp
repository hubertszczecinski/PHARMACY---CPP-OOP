#include "model/Client.h"
#include "model/Address.h"
#include "model/ClientType.h"

const std::string &Client::getName() const {
    return name;
}

void Client::setName(const std::string &newName) {
    if(!newName.empty())
        Client::name = newName;
}

const std::string &Client::getSurname() const {
    return surname;
}

void Client::setSurname(const std::string &newSurname) {
    if(!newSurname.empty())
        Client::surname = newSurname;
}

unsigned int Client::getPhoneNumber() const {
    return phoneNumber;
}

void Client::setPhoneNumber(unsigned int newPhoneNumber) {
    Client::phoneNumber = newPhoneNumber;
}

unsigned int Client::getPersonalID() const {
    return personalID;
}


void Client::setClientType(const ClientTypePtr &newType) {
    Client::clientType = newType;
}

Client::~Client() {

}

std::string Client::getInfo() {
    return "Client: " + name + " " + surname + " Pesel:" + std::to_string(personalID) + " " + address->getInfo() + " Type:" + clientType->getInfo();
}

const AddressPtr &Client::getAddress() const {
    return address;
}

void Client::setAddress(const AddressPtr &newAddress) {
    if(newAddress != nullptr)
        Client::address = newAddress;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

double Client::applyDiscount(double price) const {
    return clientType->applyDiscount(price);;
}

Client::Client(const std::string &name, const std::string &surname, unsigned int phoneNumber, unsigned int personalId,
               const ClientTypePtr &clientType, const AddressPtr &address) : name(name), surname(surname),
                                                                             phoneNumber(phoneNumber),
                                                                             personalID(personalId),
                                                                             clientType(clientType), address(address) {}

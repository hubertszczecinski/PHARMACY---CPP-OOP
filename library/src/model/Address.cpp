#include <string>
#include "model/Address.h"

const std::string &Address::getCity() const {
    return city;
}

const std::string &Address::getStreet() const {
    return street;
}

unsigned int Address::getNumber() const {
    return number;
}

void Address::setCity(const std::string &newCity) {
    if(!newCity.empty())
        Address::city = newCity;
}

void Address::setStreet(const std::string &newStreet) {
    if(!newStreet.empty())
        Address::street = newStreet;
}

void Address::setNumber(unsigned int newNumber) {
        Address::number = newNumber;
}

std::string Address::getInfo() {
    return "Adress: " + city + " " + street + " " + std::to_string(number);
}

Address::Address(const std::string &city, const std::string &street, unsigned int number) : city(city), street(street),
                                                                                            number(number) {}

Address::~Address() {

}




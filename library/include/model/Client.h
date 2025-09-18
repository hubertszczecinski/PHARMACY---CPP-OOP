//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_CLIENT_H
#define APTEKA_CLIENT_H
#include <iostream>
#include "typedefs.h"

/**
 * @brief Klasa stanowiaca reprezentacje klienta
 */
class Client{
private:
    std::string name;
    std::string surname;
    unsigned int phoneNumber;
    unsigned int personalID;
    ClientTypePtr clientType;
    AddressPtr address;

public:
    /**
     * @brief Konstruktor parametrowy
     * Tworzy obiekt klasy Client z podanymi parametrami
     *
     * @param name
     * @param surname
     * @param phoneNumber
     * @param personalId
     * @param clientType
     */
    Client(const std::string &name, const std::string &surname, unsigned int phoneNumber, unsigned int personalId,
           const ClientTypePtr &clientType, const AddressPtr &address);

    /**
     * @brief Destruktor
     * Usuwa obiekt klasy Client
     */
    virtual ~Client();

    /**
     * @brief Metoda dostepowa zwracajaca numer telefonu klienta
     *
     * @return unsigned int - numer telefonu klienta
     */
    unsigned int getPhoneNumber() const;

    /**
     * @brief Metoda dostepowa ustawiajaca numer telefonu klienta
     *
     * @param phoneNumber
     */
    void setPhoneNumber(unsigned int phoneNumber);

    /**
     * @brief Metoda dostepowa zwracajaca pesel klienta
     *
     * @return string - pesel klienta
     */
    unsigned int getPersonalID() const;

    /**
     * @brief Metoda dostepowa zwracajaca adres klienta
     *
     * @return Address - adres
     */
    const AddressPtr &getAddress() const;

    /**
     * @brief Metoda dostepowa ustawiajaca adres klienta
     *
     * @param address
     */
    void setAddress(const AddressPtr &address);

    /**
     * @brief Metoda dostepowa zwracajaca imie klienta
     *
     * @return string - imie klienta
     */
    const std::string &getName() const;

    /**
     * @brief Metoda dostepowa ustawiajaca imie klienta
     *
     * @param name
     */
    void setName(const std::string &name);

    /**
     * @brief Metoda dostepowa zwracajaca nazwisko klienta
     *
     * @return string - nazwisko
     */
    const std::string &getSurname() const;

    /**
     * @brief Metoda dostepowa ustawiajaca nazwisko klienta
     *
     * @param surname
     */
    void setSurname(const std::string &surname);

    /**
     * @brief Metoda dostepowa zwracajaca typ klienta
     *
     * @return ClientTypePtr - typ
     */
    const ClientTypePtr &getClientType() const;

    /**
     * @brief Metoda dostepowa ustawiajaca typ klienta
     *
     * @param clientType
     */
    void setClientType(const ClientTypePtr &clientType);

    /**
     * @brief Metoda zwracająca informacje o kliencie
     *
     * @return string - lancuch znakow zlozony z informacji o kliencie
     */
    std::string getInfo();

    /**
     * @brief Metoda zwracajaca cene ze znizka
     * w zaleznosci od typu klienta
     *
     * @return double - cena
     */
    double applyDiscount(double price) const;
};

#endif //APTEKA_CLIENT_H

//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_ADDRESS_H
#define APTEKA_ADDRESS_H
#include <iostream>
#include <string>

/**
 * @brief Klasa stanowiaca reprezentacje Adresu
 */
class Address{
private:
    std::string city;
    std::string street;
    unsigned int number;

public:

    /**
     * @brief Konstruktor parametrowy
     * Tworzy obiekt klasy Address z podanymi parametrami
     *
     * @param city
     * @param street
     * @param number
     */
    Address(const std::string &city, const std::string &street, unsigned int number);

    /**
     * @brief Destruktor
     * Usuwa obiekt klasy Address
     */
    virtual ~Address();

    /**
     * @brief Metoda dostepowa zwracajaca numer
     *
     * @return unsigned int - numer
     */
    unsigned int getNumber() const;

    /**
     * @brief Metoda dostepowa zwracajaca ulice
     *
     * @return string - ulica
     */
    const std::string &getStreet() const;

    /**
     * @brief Metoda dostepowa zwracajaca miasto
     *
     * @return string - miasto
     */
    const std::string &getCity() const;

    /**
     * @brief Metoda dostepowa ustawiajaca miasto
     *
     * @param city
     */
    void setCity(const std::string &city);

    /**
     * @brief Metoda dostepowa ustawiajaca ulice
     *
     * @param street
     */
    void setStreet(const std::string &street);

    /**
     * @brief Metoda dostepowa ustawiajaca numer
     *
     * @param number
     */
    void setNumber(unsigned int number);

    /**
    * @brief Metoda zwracająca informacje o Adresie
    *
    * @return string - lancuch znakow zlozony z informacji o adresie
    */
    std::string getInfo();

};

#endif //APTEKA_ADDRESS_H

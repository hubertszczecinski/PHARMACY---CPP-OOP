//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_CLIENTTYPE_H
#define APTEKA_CLIENTTYPE_H

#include <string>

/**
 * @brief Klasa stanowiaca reprezentacje typu klienta
 */
class ClientType {
public:
    /**
     * @brief Metoda zwracajaca cene ze znizka
     * w zaleznosci od typu klienta
     *
     * @return double - cena ze znizka
     */
    virtual double applyDiscount(double price) const = 0;

    /**
     * @brief Metoda zwracająca informacje o typie klienta
     *
     * @return string - lancuch znakow, informacja o typie
     */
    virtual std::string getInfo() const = 0;

    /**
     * @brief Destruktor
     * Usuwa obiekt klasy ClientType
     */
    virtual ~ClientType() = 0;
};

/**
 * @brief Klasa stanowiaca reprezentacje typu DefaultClient
 */
class DefaultClient : public ClientType {
public:
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa stanowiaca reprezentacje typu RetiredClient
 */
class RetiredClient : public ClientType {
public:
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

#endif //APTEKA_CLIENTTYPE_H

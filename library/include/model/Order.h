//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_ORDER_H
#define APTEKA_ORDER_H
#include <iostream>
#include <boost/date_time.hpp>
#include "typedefs.h"

namespace pt = boost::posix_time;

/**
 * @brief Klasa stanowiaca reprezentacje zamowienia
 */
class Order{
private:
    unsigned int id;
    pt::ptime orderTime;
    pt::ptime finalizationTime;
    ProductPtr product;
    ClientPtr client;

public:
    /**
     * @brief Konstruktor parametrowy
     * Tworzy obiekt klasy Order z podanymi parametrami
     *
     * @param id
     * @param orderTime
     * @param product
     * @param client
     */
    Order(unsigned int id, const pt::ptime &orderTime, const ProductPtr &product, const ClientPtr &client);

    /**
     * @brief Destruktor
     * Usuwa obiekt klasy Order
     */
    virtual ~Order();

    /**
     * @brief Metoda zwracająca informacje o zamowieniu
     *
     * @return string - lancuch znakow zlozony z informacji o zamowieniu
     */
    std::string getInfo();

    /**
     * @brief Metoda dostepowa zwracajaca ID zamowienia
     *
     * @return unsigned int - id
     */
    unsigned int getId() const;

    /**
     * @brief Metoda dostepowa zwracajaca czas zlozenia zamowienia
     *
     * @return pt::ptime - orderTime
     */
    const pt::ptime &getOrderTime() const;

    /**
     * @brief Metoda dostepowa zwracajaca czas finalizacji zamowienia
     *
     * @return pt::ptime - finalizationTime
     */
    const pt::ptime &getFinalizationTime() const;

    /**
     * @brief Metoda zwracajaca koszt zamowienia
     *
     * @return double - order cost
     */
    double getOrderCost() const;

    /**
     * @brief Metoda finalizujaca zamowienie
     *
     * @param finalizationTime
     */
    void finalizeOrder(const pt::ptime &finalizationTime);

    /**
     * @brief Metoda dostepowa zwracajaca produkt
     *
     * @return ProductPtr - produkt
     */
    const ProductPtr &getProduct() const;

    /**
     * @brief Metoda dostepowa zwracajaca klienta
     *
     * @return ClientPtr - klient
     */
    const ClientPtr &getClient() const;

};

#endif //APTEKA_ORDER_H

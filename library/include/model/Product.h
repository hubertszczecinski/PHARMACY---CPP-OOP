//
// Created by hania on 06.06.2024.
//

#ifndef APTEKA_PRODUCT_H
#define APTEKA_PRODUCT_H
#include <iostream>

/**
 * @brief Klasa stanowiaca reprezentacje Produktu
 */
class Product {
private:
    double costBeforeDiscount;
    std::string productName;
    unsigned int productID;
    bool ordered = false;
    bool sold = false;


public:
    /**
     * @brief Konstruktor parametrowy
     * Tworzy obiekt klasy Product z podanymi parametrami
     *
     * @param costBeforeDiscount
     * @param productName
     * @param productId
     */
    Product(double costBeforeDiscount, const std::string &productName, unsigned int productIDo);

    /**
     * @brief Destruktor
     * Usuwa obiekt klasy Product
     */
    virtual ~Product() = 0;

    /**
     * @brief Metoda zwracająca informacje o produkcie
     *
     * @return string - lancuch znakow zlozony z informacji o produkcie
     */
    virtual std::string getInfo();

    /**
     * @brief Metoda dostepowa zwracajaca koszt przed obnizka
     *
     * @return double - koszt
     */
    double getCostBeforeDiscount() const;

    /**
     * @brief Metoda dostepowa zwracajaca nazwe produktu
     *
     * @return string - nazwa produktu
     */
    const std::string &getProductName() const;

    /**
     * @brief Metoda dostepowa zwracajaca ID produktu
     *
     * @return unsigned int - ID produktu
     */
    unsigned int getProductID() const;

    /**
     * @brief Metoda dostepowa zwracajaca informacje o stanie zamowienia
     *
     * @return bool
     */
    bool isOrdered() const;

    /**
     * @brief Metoda dostepowa zwracajaca informacje o stanie sprzedania
     *
     * @return bool
     */
    bool isSold() const;

    /**
     * @brief Metoda dostepowa ustawiajaca koszt przed obnizka
     *
     * @param costBeforeDiscount
     */
    void setCostBeforeDiscount(double costBeforeDiscount);

    /**
     * @brief Metoda dostepowa ustawiajaca nazwe produktu
     *
     * @param productName
     */
    void setProductName(const std::string &productName);

    /**
     * @brief Metoda dostepowa ustawiajaca stan zamowienia
     *
     * @param ordered
     */
    void setOrdered(bool ordered);

    /**
     * @brief Metoda dostepowa ustawiajaca stan sprzedania
     *
     * @param sold
     */
    void setSold(bool sold);
};

#endif //APTEKA_PRODUCT_H

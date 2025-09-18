//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_DRUG_H
#define APTEKA_DRUG_H

#include "Product.h"

/**
 * @brief Klasa stanowiaca reprezentacje Produktu - leku
 */
class Drug : public Product {
private:
    bool perscribed;


public:
    /**
     * @brief Konstruktor parametrowy
     * Tworzy obiekt klasy Drug z podanymi parametrami
     *
     * @param costBeforeDiscount
     * @param productName
     * @param productId
     * @param perscribed
     */
    Drug(double costBeforeDiscount, const std::string &productName, unsigned int productId, bool perscribed);

    ~Drug() override;

    std::string getInfo() override;

};

#endif //APTEKA_DRUG_H

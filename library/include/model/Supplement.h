//
// Created by huber on 24.05.2024.
//

#ifndef APTEKA_SUPPLEMENT_H
#define APTEKA_SUPPLEMENT_H

#include "Product.h"

/**
 * @brief Klasa stanowiaca reprezentacje Produktu - suplementu
 */
class Supplement : public Product {
private:
    unsigned int dose;

public:
    /**
     * @brief Konstruktor parametrowy
     * Tworzy obiekt klasy Supplement z podanymi parametrami
     *
     * @param costBeforeDiscount
     * @param productName
     * @param productId
     * @param dose
     */
    Supplement(double costBeforeDiscount, const std::string &productName, unsigned int productId, unsigned int dose);

    ~Supplement() override;

    std::string getInfo() override;

};

#endif //APTEKA_SUPPLEMENT_H

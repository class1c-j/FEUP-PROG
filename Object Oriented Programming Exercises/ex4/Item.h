
#ifndef FICHAOOP_ITEM_H
#define FICHAOOP_ITEM_H

#include <string>
#include "Product.h"


class Item {
public:
    Item();
    Item(const Product& product, int quantity);

    const std::string &getDescription() const;

    unsigned int getQuantity() const;

    double getPrice() const;

    double getTotal() const;

private:
    std::string m_description;
    unsigned m_quantity{};
    double m_price{};
    double m_total{};
};


#endif //FICHAOOP_ITEM_H

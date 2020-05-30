
#include "Product.h"

Product::Product() = default;

Product::Product(std::string description, double price)
        : m_description(std::move(description)), m_price(price) {
}

const std::string &Product::getDescription() const {
    return m_description;
}

double Product::getPrice() const {
    return m_price;
}



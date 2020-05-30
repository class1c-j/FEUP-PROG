
#include "Item.h"

Item::Item() = default;

Item::Item(const Product& product, int quantity)
    : m_description(product.getDescription()), m_price(product.getPrice()), m_quantity(quantity),
    m_total(m_price * m_quantity){
}

const std::string &Item::getDescription() const {
    return m_description;
}

unsigned int Item::getQuantity() const {
    return m_quantity;
}

double Item::getPrice() const {
    return m_price;
}

double Item::getTotal() const {
    return m_total;
}

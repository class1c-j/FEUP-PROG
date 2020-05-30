
#ifndef FICHAOOP_PRODUCT_H
#define FICHAOOP_PRODUCT_H

#include <string>

class Product {
public:
    Product();

    Product(std::string mDescription, double price);

    const std::string &getDescription() const;

    double getPrice() const;

private:
    std::string m_description;
    double m_price{};
};


#endif //FICHAOOP_PRODUCT_H

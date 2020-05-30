
#ifndef FICHAOOP_INVOICE_H
#define FICHAOOP_INVOICE_H

#include "Client.h"
#include "Item.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Invoice {
public:
    Invoice();
    Invoice(const Client &client, std::vector<Item> items);
    void show();
    void add(const Item &item);
private:
    std::string m_clientName{};
    Address m_clientAddress{};
    std::vector<Item> m_items{};
    double m_totalAmount{};
};


#endif //FICHAOOP_INVOICE_H

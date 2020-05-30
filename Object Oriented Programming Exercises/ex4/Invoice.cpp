
#include "Invoice.h"

Invoice::Invoice() = default;

Invoice::Invoice(const Client &client, std::vector<Item> items) : m_clientAddress(client.getAddress()),
        m_clientName(client.getName()), m_items(std::move(items)) {
    for (const auto &i : m_items) m_totalAmount += i.getTotal();
}

void Invoice::show() {

    std::cout << std::left << m_clientName << "\n" << std::left << m_clientAddress.m_streetName
              << "\n" << m_clientAddress.m_postalCode << " - " << m_clientAddress.m_city << "\n\n";

    std::cout  << std::setw(20) << std::left << "Description" << std::setw(10) << std::left << "Price"
    << std::setw(10) << std::left << "Qty" << std::setw(10) << std::left << "Total" ;

    std::cout << std::setfill('-') << std::setw(50) << "\n" << std::setfill(' ');

    for (const auto &item : m_items) {
        std::cout << "\n";
        std::cout << std::setw(20) << std::left << item.getDescription() << std::setw(10) << std::right
        << item.getPrice() << std::setw(10) << std::right << item.getQuantity() << std::setw(10) << std::right
        << item.getTotal();
    }
    std::cout << "\n\n" << "Total Amount: " << m_totalAmount << " euro\n";
}

void Invoice::add(const Item &item) {
    m_items.push_back(item);
}

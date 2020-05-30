
#include "Client.h"

#include <utility>

Client::Client() = default;

Client::Client(std::string name, Address address)
        : m_name(std::move(name)), m_address(std::move(address)) {
}

const std::string &Client::getName() const {
    return m_name;
}

const Address &Client::getAddress() const {
    return m_address;
}

Address::Address(std::string mStreetName, std::string mPostalCode, std::string mCity)
        : m_streetName(std::move(mStreetName)), m_postalCode(std::move(mPostalCode)), m_city(std::move(mCity)) {}

Address::Address() = default;
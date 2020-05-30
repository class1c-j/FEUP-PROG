
#ifndef FICHAOOP_CLIENT_H
#define FICHAOOP_CLIENT_H

#include <string>

struct Address {
    std::string m_streetName;
    std::string m_postalCode;
    std::string m_city;
    Address();
    Address(std::string mStreetName, std::string mPostalCode, std::string mCity);

};

class Client {
public:

    Client();

    Client(std::string name, Address address);

    const std::string &getName() const;

    const Address & getAddress() const;

private:

    std::string m_name{};
    Address m_address{};

};


#endif //FICHAOOP_CLIENT_H

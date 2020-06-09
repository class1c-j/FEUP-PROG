//
// Created by ritam on 08/06/20.
//

#include "FeupPerson.h"

FeupPerson::FeupPerson() {
    this->id = 0;
    this->name = "";
    this->address = "";
}

FeupPerson::FeupPerson(int id, std::string name, std::string address) {
    this->id = id;
    this->name = name;
    this->address = address;
}

void FeupPerson::showRecord() {
    std::cout << "-----------------------------\n";
    std::cout << "Name    : "<< name << std::endl
              << "ID      : "<< id << std::endl
              << "Address : "<< address << std::endl;
    std::cout << "-----------------------------\n";
}

void FeupPerson::changeAddress(std::string newAddress) {
    this->address = newAddress;
}
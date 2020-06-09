
#ifndef STUFY_FEUPPERSON_H
#define STUFY_FEUPPERSON_H

#include <string>
#include <iostream>

class FeupPerson {
public:
    FeupPerson();
    FeupPerson(int id, std::string name, std::string address);
    // virtual ~FeupPerson();
    virtual void showRecord();
    void changeAddress(std::string newAddress);

protected:  // accessible inside the class and by all of its subclasses
    int id;
    std::string name;
    std::string address;
};


#endif //STUFY_FEUPPERSON_H

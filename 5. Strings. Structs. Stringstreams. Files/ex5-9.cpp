#include <iostream>
#include <string>
#include <vector>

/*
  
   a) Declare a struct that can be used to represent a street address. For simplicity, consider that the only
   elements of the address are: street, door number, and city.
  
*/

struct Address {
    std::string street;
    unsigned doorNumber;
    std::string city;
};

/*
  
   b) Declare a struct that can be used to represent a person. For simplicity, consider that the only attributes
   of the person are: name, age, gender and address. Use the struct declared in a) to represent the address.
  
*/

struct Person {
    std::string name;
    unsigned age;
    std::string gender;
    Address address;
};

/*
   
   c) Write a program that reads, from the keyborad, the data relative to a set of persons, including their address,
   and then  shows the name of the persons that live in the same street of a given city (input by the user).
   Suggestion: use functions to read and to write an address and the person's data.
 
*/

void readAddress(Address &a) {
    unsigned n;
    std::cout << "Street ? ";
    std::getline(std::cin, a.street);
    std::cout << "Door number ? ";
    std::cin >> n;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cout << "Invalid, try again: ";
        std::cin >> n;
    }
    std::cin.ignore(9999, '\n');
    a.doorNumber = n;
    std::cout << "City ? ";
    std::getline(std::cin, a.city);
}

void readPerson(Person &p) {
    unsigned a;
    std::cout << "\n";
    std::cout << "Name ? ";
    std::getline(std::cin, p.name);
    std::cout << "Age ? ";
    std::cin >> a;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cout << "Invalid, try again: ";
        std::cin >> a;
    }
    p.age = a;
    std::cin.ignore(9999, '\n');
    std::cout << "Gender ? ";
    std::getline(std::cin, p.gender);
    readAddress(p.address);
}

int main() {
    int n;
    std::cout << "How many people ? ";
    std::cin >> n;
    std::cin.ignore(9999, '\n');
    std::vector<Person> people;
    for (int i = 0; i < n; i++) {
        Person p;
        readPerson(p);
        people.push_back(p);
    }
    for (int i = 1; i < people.size(); i++) {
        if (people.at(i - 1).address.street == people.at(i).address.street &&
            people.at(i - 1).address.city == people.at(i).address.city) {
            std::cout << people.at(i - 1).name << " and " << people.at(i).name << " both live in "
                      << people.at(i).address.street
                      << ", " << people.at(i).address.city << std::endl;
        }
    }
}

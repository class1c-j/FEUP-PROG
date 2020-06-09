//
// Created by ritam on 08/06/20.
//

#include "Student.h"

Student::Student(int id, std::string name, std::string address, std::string course, int year)
        : FeupPerson(id, name, address) {
    this->course = course;
    this->year = year;
}

void Student::addClassTaken(Class* newClass) {
    classesTaken.push_back(newClass);
}

void Student::showRecord() {
    std::cout << "-----------------------------\n";
    std::cout << "Name    : "<< name << std::endl
              << "ID      : "<< id << std::endl
              << "Address : "<< address << std::endl;
    std::cout << "Course  : "<< course << std::endl;
    std::vector<Class*>::iterator it;
    std::cout << "Classes taken:\n";
    for(it = classesTaken.begin(); it != classesTaken.end(); it++) {
        Class* c = *it;
        std::cout << c->getName() << std::endl;
    }
    std::cout << "-----------------------------\n";
}
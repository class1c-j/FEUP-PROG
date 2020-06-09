//
// Created by ritam on 09/06/20.
//

#include "Teacher.h"

Teacher::Teacher(int id, std::string name, std::string address, std::string rank, std::string course)
        : FeupPerson(id, name, address) {
    this->rank = rank;
    this->course = course;
}

void Teacher::addClassTaught(Class *newClass) {
    classesTaught.push_back(newClass);
}

void Teacher::showRecord() {
    std::cout << "-----------------------------\n";
    std::cout << "Name    : "<< name << std::endl
              << "ID      : "<< id << std::endl
              << "Address : "<< address << std::endl
              << "Rank    : "<< rank << std::endl
              << "Course  : "<< course << std::endl;
    std::vector<Class*>::iterator it;
    std::cout << "Classes taught:\n";
    for(it = classesTaught.begin(); it != classesTaught.end(); it++) {
        Class* c = *it;
        std::cout << c->getName() << std::endl;
    }
    std::cout << "-----------------------------\n";
}


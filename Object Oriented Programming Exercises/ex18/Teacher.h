//
// Created by ritam on 09/06/20.
//

#ifndef STUFY_TEACHER_H
#define STUFY_TEACHER_H

#include <iostream>
#include <vector>
#include <string>
#include "FeupPerson.h"
#include "Class.h"

class Teacher : public FeupPerson {
public:
    Teacher() {};
    Teacher(int id, std::string name, std::string address, std::string rank, std::string course);
    void showRecord();
    void addClassTaught(Class* newClass);
    void showCourse() {std::cout << course << std::endl;};
private:
    std::string rank;
    std::string course;
    std::vector<Class*> classesTaught;
};


#endif //STUFY_TEACHER_H

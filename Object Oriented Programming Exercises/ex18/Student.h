//
// Created by ritam on 08/06/20.
//

#ifndef STUFY_STUDENT_H
#define STUFY_STUDENT_H

#include <vector>
#include <string>
#include "FeupPerson.h"
#include "Class.h"

class Student : public FeupPerson {
public:
    Student() { };
    Student(int id, std::string name, std::string address, std::string course, int year);
    void addClassTaken(Class* newClass);
    void changeCourse(int newCourse);
    void showRecord();

private:
    std::string course;
    int year;
    std::vector<Class*> classesTaken;
};


#endif //STUFY_STUDENT_H

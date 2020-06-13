
#ifndef FICHA_EX2_H
#define FICHA_EX2_H

#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

class Student {
public:
    Student();
    Student(const std::string& code, const std::string& name);
    void setGrades(double shortExam, double project, double exam);
    std::string getCode() const;
    std::string getName()const;
    int getFinalGrade() const; // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam;  // weights in percentage(ex:20,30,50)
private:
    std::string m_code; // student code
    std::string m_name; // student complete name
    double m_shortExam{}, m_project{}, m_exam{}; // grades obtained by the student in the different components
    int m_finalGrade{};
};

int Student::weightExam = 50, Student::weightProject = 30, Student::weightShortExam = 20;

void Student::setGrades(double shortExam, double project, double exam) {

    this->m_shortExam = shortExam;
    this->m_project = project;
    this->m_exam = exam;

    double aux = (weightShortExam * shortExam + weightProject * project + weightExam * exam) / 100;

    m_finalGrade = std::round(aux);
}

Student::Student() = default;

Student::Student(const std::string & code, const std::string & name) {
    this->m_code = code;
    this->m_name = name;
}

std::string Student::getCode() const {
    return m_code;
}

std::string Student::getName() const {
    return m_name;
}

int Student::getFinalGrade() const {
    return m_finalGrade;
}

bool Student::isApproved() const {
    return m_finalGrade >= 10;
}

Student readStudentData() {

    std::string code, name;
    double shortExam, project, exam;

    std::cout << '\n';

    std::cout << "Student code ? "; std::cin >> code;
    std::cout << "Student name ? "; std::cin >> name;

    Student st(code, name);

    std::cout << "Short exam grade ? "; std::cin >> shortExam;
    std::cout << "Project grade ? "; std::cin >> project;
    std::cout << "Exam grade ? "; std::cin >> exam;

    st.setGrades(shortExam, project, exam);

    return st;
}

void showAboveAverageStudents(std::ostream & os, const std::vector<Student> & students) {

    os << "Above average students\n";

    double average{};

    for (const auto& i : students) {
        average += i.getFinalGrade();
    }

    average /= students.size();
    std::vector<Student> above{};

    for (const auto& i : students) {
        if (i.getFinalGrade() > average) {
            above.push_back(i);
        }
    }

    os << std::left << std::setw(15) << "CODE" << std::setw(20) << "NAME" << std::setw(30) << std::right << "GRADE" << "\n";

    for (const auto& i : above) {
        os << std::left << std::setw(15) << i.getCode() << std::setw(20) << i.getName() << std::setw(30) << std::right
           << i.getFinalGrade() << "\n";
    }
}



#endif //FICHA_EX2_H

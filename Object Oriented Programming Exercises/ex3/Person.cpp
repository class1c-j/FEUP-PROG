 
#include "Person.h"

Person::Person(std::string name, char gender, const Date &birthDate)
        : m_name(std::move(name)), m_gender(gender), m_birthDate(birthDate) {
}

Person::Person() = default;

const std::string &Person::getName() const {
    return m_name;
}

char Person::getGender() const {
    return m_gender;
}

const Date &Person::getBirthDate() const {
    return m_birthDate;
}

void Person::setName(const std::string &mName) {
    m_name = mName;
}

void Person::setGender(char mGender) {
    m_gender = mGender;
}

void Person::setBirthDate(const Date &mBirthDate) {
    m_birthDate = mBirthDate;
}

void Person::showData() {
    std::cout << "Name: " <<  m_name << '\n' << "Gender: " << m_gender << '\n' << "Birthday: ";
    m_birthDate.show();
    std::cout << "\n";
}


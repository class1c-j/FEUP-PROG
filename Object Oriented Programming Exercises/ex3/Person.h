#ifndef FICHAOOP_PERSON_H
#define FICHAOOP_PERSON_H

#include <utility>

#include "Date.h"

class Person {
public:
    Person(std::string name, char gender, const Date &birthDate);

    Person();

    const std::string &getName() const;

    char getGender() const;

    const Date &getBirthDate() const;

    void setName(const std::string &mName);

    void setGender(char mGender);

    void setBirthDate(const Date &mBirthDate);

    void showData();

private:
    std::string m_name;
    char m_gender{};
    Date m_birthDate;
};


#endif //FICHAOOP_PERSON_H

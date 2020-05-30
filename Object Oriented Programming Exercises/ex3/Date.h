 #ifndef FICHAOOP_DATE_H
#define FICHAOOP_DATE_H

#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>

class Date {
public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    explicit Date(const std::string& yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    std::string getDate() const;  // returns the date in format "yyyy/mm/dd"
    void show() const;       // shows the date on the screen in format "yyyy/mm/dd"
    void showMod();
    bool isValid(); // indicate whether the date is valid or not
    bool isEqualTo(const Date &date) const; // indicate whether the date is equal to the date received as parameter
    bool isNotEqualTo(const Date &date) const; // indicate whether the date is not equal to the date received as parameter
    bool isAfter(const Date &date) const; // indicate whether the date is after date received as parameter
    bool isBefore(const Date &date) const; // indicate whether the dateis before the date received as parameter
private:
    unsigned int year{};
    unsigned int month{};
    unsigned int day{};
    unsigned int getDaysInMonth(); // returns the n of days in year/month
    bool isLeapYear() const;
};

#endif //FICHAOOP_DATE_H

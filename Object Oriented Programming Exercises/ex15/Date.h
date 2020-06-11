
#ifndef FICHA_DATE_H
#define FICHA_DATE_H

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
    Date(const Date &date);
    Date& setYear(unsigned int year);
    Date& setMonth(unsigned int month);
    Date& setDay(unsigned int day);
    Date& setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    std::string getDate() const;  // returns the date in format "yyyy/mm/dd"
    void show() const;       // shows the date on the screen in format "yyyy/mm/dd"
    void showMod() const;
    bool isValid(); // indicate whether the date is valid or not
    bool isEqualTo(const Date &date) const; // indicate whether the date is equal to the date received as parameter
    bool isNotEqualTo(const Date &date) const; // indicate whether the date is not equal to the date received as parameter
    bool isAfter(const Date &date) const; // indicate whether the date is after date received as parameter
    bool isBefore(const Date &date) const; // indicate whether the date is before the date received as parameter
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator<(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator>(const Date &other) const;
    friend std::istream& operator>>(std::istream &is, Date &date);
    friend std::ostream& operator<<(std::ostream& os, const Date &date);
    // these operators were defined as friend of the class because, due to their nature, otherwise we would
    // have to use them with a weird syntax, for example Date d1; d1 << std::cout; so I opted for this way
    // to avoid confusion
    Date& operator++() const;  // ++Date
    Date& operator--() const;  // --Date
    Date operator++(int); // Date++
    Date operator--(int); // Date--
private:
    unsigned int m_year{};
    unsigned int m_month{};
    unsigned int m_day{};
    unsigned int getDaysInMonth() const; // returns the n of days in year/month
    bool isLeapYear() const;
};

#endif //FICHA_DATE_H
 

#include "Date.h"

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(const std::string& yearMonthDay) {
    std::stringstream ss(yearMonthDay);
    char sep = '/';
    ss >> year >> sep >> month >> sep >> day;
}

Date::Date() {
    auto current = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(current);
    struct tm *parts = std::localtime(&now_c);
    year = 1900 + parts->tm_year;
    month = 1 + parts->tm_mon;
    day = parts->tm_mday;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

unsigned int Date::getYear() const {
    return year;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getDay() const {
    return day;
}

std::string Date::getDate() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << year << '/' << std::setw(2) << month
       << '/' << std::setw(2) << day;
    return ss.str();
}

void Date::show() const {
    std::cout << getDate();
}

unsigned int Date::getDaysInMonth() {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear() ? 29 : 28;
        default:
            return 0;
    }
}

bool Date::isValid() {
    return !(day > getDaysInMonth() || (month > 12 || month == 0));
}

bool Date::isLeapYear() const {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool Date::isEqualTo(const Date &date) const {
    return day == date.day && month == date.month && year == date.year;
}

bool Date::isNotEqualTo(const Date &date) const {
    return !isEqualTo(date);
}

bool Date::isAfter(const Date &date) const {
    if (year > date.year) return true;
    else if (month > date.month) return true;
    else return day > date.day;
}

bool Date::isBefore(const Date &date) const {
    return !isAfter(date) && isNotEqualTo(date);
}

void Date::showMod() {
    std::cout << std::setfill('0') << std::setw(4) << year << std::setw(2) << month
              << std::setw(2) << day;
} 

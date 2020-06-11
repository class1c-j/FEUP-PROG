
#include "Date.h"

Date::Date() {
    auto current = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(current);
    struct tm *parts = std::localtime(&now_c);
    m_year = 1900 + parts->tm_year;
    m_month = 1 + parts->tm_mon;
    m_day = parts->tm_mday;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->m_year = year;
    this->m_month = month;
    this->m_day = day;
}

Date::Date(const std::string& yearMonthDay) {
    std::stringstream ss(yearMonthDay);
    char sep = '/';
    ss >> m_year >> sep >> m_month >> sep >> m_day;
}

Date& Date::setYear(unsigned int year) {
    this->m_year = year;
    return *this;
}

Date& Date::setMonth(unsigned int month) {
    this->m_month = month;
    return *this;
}

Date& Date::setDay(unsigned int day) {
    this->m_day = day;
    return *this;
}

Date& Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->m_year = year;
    this->m_month = month;
    this->m_day = day;
    return *this;
}

unsigned int Date::getYear() const {
    return m_year;
}

unsigned int Date::getMonth() const {
    return m_month;
}

unsigned int Date::getDay() const {
    return m_day;
}

std::string Date::getDate() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << m_year << '/' << std::setw(2) << m_month
       << '/' << std::setw(2) << m_day;
    return ss.str();
}

void Date::show() const {
    std::cout << getDate();
}

unsigned int Date::getDaysInMonth() const {
    switch (m_month) {
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
    return !(m_day > getDaysInMonth() || (m_month > 12 || m_month == 0) || m_day == 0);
}

bool Date::isLeapYear() const {
    return (m_year % 400 == 0 || (m_year % 4 == 0 && m_year % 100 != 0));
}

bool Date::isEqualTo(const Date &date) const {
    return m_day == date.m_day && m_month == date.m_month && m_year == date.m_year;
}

bool Date::isNotEqualTo(const Date &date) const {
    return !isEqualTo(date);
}

bool Date::isAfter(const Date &date) const {
    return this->m_year > date.m_year || (this->m_year == date.m_year && (this->m_month > date.m_month ||
    this->m_month == date.m_month && this->m_day > date.m_day));
}

bool Date::isBefore(const Date &date) const {
    return !isAfter(date) && isNotEqualTo(date);
}

void Date::showMod() const {
    std::cout << std::setfill('0') << std::setw(4) << m_year << std::setw(2) << m_month
              << std::setw(2) << m_day;
}

bool Date::operator==(const Date &other) const {
    return this->isEqualTo(other);
}

bool Date::operator!=(const Date &other) const {
    return this->isNotEqualTo(other);
}

bool Date::operator<=(const Date &other) const {
    return this->isBefore(other) || this->isEqualTo(other);
}

bool Date::operator<(const Date &other) const {
    return this->isBefore(other);
}

bool Date::operator>=(const Date &other) const {
    return this->isAfter(other) || this->isEqualTo(other);
}

bool Date::operator>(const Date &other) const {
    return this->isAfter(other);
}

std::istream &operator>>(std::istream &is, Date &date) {
    char sep{};
    is >> date.m_year >> sep >> date.m_month >> sep >> date.m_day;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.m_year << '/' << date.m_month << '/' << date.m_day;
    return os;
}

Date &Date::operator++() const {
    auto result = new Date(this->m_year, this->m_month, this->m_day+1);
    if (!result->isValid()) {
        if (this->m_month == 12) {
            result->setYear(this->m_year + 1).setMonth(1).setDay(1);
        } else {
            result->setMonth(this->m_month + 1).setDay(1);
        }
    }
    return *result;
}

Date &Date::operator--() const {
    auto result = new Date(this->m_year, this->m_month, this->m_day-1);
    if (!result->isValid()) {
        if (this->m_month == 1) {
            result->setYear(this->m_year - 1).setMonth(12).setDay(this->getDaysInMonth());
        } else {
            result->setMonth(this->m_month - 1)  // ew spaghetti
            .setDay(Date(this->m_year, this->m_month-1, this->m_day-1).getDaysInMonth());
        }
    }
    return *result;
}

Date Date::operator++(int) {
    Date temp = *this;
    return ++temp;
}

Date::Date(const Date &date) {
    m_day = date.m_day;
    m_month = date.m_month;
    m_year = date.m_year;
}

Date Date::operator--(int) {
    Date temp = *this;
    return --temp;
}
 

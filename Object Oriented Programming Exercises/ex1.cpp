 
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>

/*
   
   Consider the following definition of class Date that will be used to represent dates:
   
*/

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
    bool isNotEqualTo(const Date &date); // indicate whether the date is not equal to the date received as parameter
    bool isAfter(const Date &date); // indicate whether the date is after date received as parameter
    bool isBefore(const Date &date); // indicate whether the dateis before the date received as parameter
private:
    unsigned int year{};
    unsigned int month{};
    unsigned int day{};
    unsigned int getDaysInMonth(); // returns the n of days in year/month
    bool isLeapYear() const;
};

/*
   
   Write the code of all the methods of the class. For now, consider that the dates represented in objects of class
   Date are valid.
   
*/


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

/*
  
   Write the main() function of a program that tests all the methods of the class.
    
*/

void testA() {
    Date date1(2010, 03, 13);
    Date date2 = Date("2020/05/25");
    date1.setDay(3);
    date1.setMonth(3);
    date1.setYear(3);
    date1.show();
    std::cout << "\n";
    date2.show();
    date1.setDate(2017, 3, 12);
    std::cout << "\n" << date2.getDay() << " " << date2.getMonth() << " " << date2.getYear() << "\n";
}

/*
  
   Add the following methods to the class
    
*/

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

/*
   
   Modify the main() function of the program in order to test the new methods
   
*/

void testB() {
    Date date1(2020, 2, 29);
    std::cout << date1.isValid() << "\n";

    Date date2(2007, 3, 21);
    std::cout << date1.isAfter(date2) << "\n";

    Date date3(2020, 2, 29);
    std::cout << date1.isEqualTo(date3) << "\n";

    std::cout << date2.isBefore(date3) << "\n";
}

/*
  
   Explain why the following variable declaration is not possible: Date d1;.
   The class Date does not have (yet) a constructor that doesn't take any parameters, so there is no suitable
   constructor for this case.
    
*/

/*
  
   Add a default constructor to class Date, that must construct an object representing the current date; you must search
   for a way of obtaining the current date from your computer.
    
*/

Date::Date() {
    auto current = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(current);
    struct tm *parts = std::localtime(&now_c);
    year = 1900 + parts->tm_year;
    month = 1 + parts->tm_mon;
    day = parts->tm_mday;
}

/*
  
   Modify the implementation of the class so that the attributes (year, month and day) are represented in a single
   string, using the format "yyyymmdd". Verify that the main() function that you developed in d) does not have to be modified
    
 */

void Date::showMod() {
    std::cout << std::setfill('0') << std::setw(4) << year << std::setw(2) << month
    << std::setw(2) << day;
}

void testC() {
    Date date1;
    date1.showMod();
}

int main() {
    // testA();
    // testB();
    testC();
}

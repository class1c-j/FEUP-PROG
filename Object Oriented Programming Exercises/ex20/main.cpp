/*

   Consider the class Date of problem 1.

*/

#include "Date.h"
#include "InvalidDate.h"
#include <iostream>

/*

   a) Modify it so that it throws an exception when the constructors or any of the set methods receive as parameter(s)
   some values that would constitute an invalid date. The thrown object must be of class InvalidDate that you must define.

*/

/*

   b) Modify the program developed in problem 1 to test the exception handling additions made to class Date.

*/

void testA() {
    try {
        Date date1(2010, 03, 21);
        Date date2 = Date("2020/05/25");
        date1.setDay(3);
        date1.setMonth(67);
        date1.setYear(2002);
        date1.show();
        std::cout << "\n";
        date2.show();
        date1.setDate(2017, 3, 12);
        std::cout << "\n" << date2.getDay() << " " << date2.getMonth() << " " << date2.getYear() << "\n";
    } catch (InvalidDate &id) {
        std::cout << id.what() << "\n";
    }
}


int main() {
    testA();
    return 0;
}

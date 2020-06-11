/*

   Consider the class Date from problem 1.
   Implement the following modifications/additions and develop a program to test them.

*/

#include "Date.h"
#include <iostream>

/*

   a) Overload the operators ==, !=, <, <=, >, >=,>> and <<, for class Date.

*/

void testA() {
    Date d1("2020/01/16");
    std::cout << (d1 == Date("2020/01/16")) << '\n';
    std::cout << (d1 > Date("2021/01/15")) << '\n';
    std::cout << "Insert date (yyyy/mm/dd) : ";
    std::cin >> d1;
    std::cout << d1;

}

/*

   b) Modify the definition of the 'set' methods so that their return value is a Date &.
   Explain the implications of returning a Date &.

   By returning a reference, it allows us to use a "chain" of setters using the syntax bellow

*/

void testB() {
    Date d1;
    d1.setDay(20).setMonth(03).setYear(2013).show();
}

/*

   Overload operators ++ and -- (both postfix and prefix) for objects of class Date;
   the result of this operator should be the date of the next and the previous day, respectively
   (taking into account the date stored in the object).

*/

void testC() {
    Date d1(2020, 1, 1);
    std::cout << d1--;
}

int main() {
    //testA();
    //testB();
    testC();
    return 0;
}
 

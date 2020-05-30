 /*
  
   Define a class Person for representing persons. Consider that a person has the following attributes:
   name, gender and birth date. Use an object of class Date(see problem 1) to represent the birth date. Develop your
   program using separate compilation.
   
 */

#include "Person.h"

int main() {
    Person p("Sir Dough", 'M', Date());
    p.showData();
    return 0;
}

/*

   Modify the program developed in problem 2.d so that the output can be sorted either by student name or by student
   grade. Use STL algorithm sort() for this purpose. Note: in STL sort(), besides the range of the elements to sort,
   you can specify a function that will be used to compare the elements to be sorted.

*/

#include "ex2.h"

#include <algorithm>

int main() {

    int n{};
    std::vector<Student> students{};

    std::cout << "How many students ? "; std::cin >> n;
    students.reserve(n);

    for (int i = 0; i < n; i++) {
        students.push_back(readStudentData());
    }

    char choice{};
    std::cout << "Sort by name (n) or by grade (g) ? "; std::cin >> choice;
    switch(choice) {
        case 'n':
            std::sort(students.begin(), students.end(), [](const Student& left, const Student& right) {
                return left.getName().compare(right.getName()) < 0;
            });
            break;
        case 'g':
            std::sort(students.begin(), students.end(), [](const Student& left, const Student& right) {
                return left.getFinalGrade() < right.getFinalGrade();
            });
            break;
        default:
            std::cerr << "Invalid choice, aborting.";
            exit(1);
    }

    showAboveAverageStudents(std::cout, students);

    return 0;

}
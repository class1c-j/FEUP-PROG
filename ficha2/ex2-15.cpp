/* Write a program to test if the user knows the multiplication tables. The program should generate 2
 * random numbers (between 2 and 9), present them to the user, and ask for the result of multiplying those numbers.
 * After reading the user's answer, it should present an appropriate message taking into account the correctness of the
 * answer and the time it took the user to give it
 */


#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int op1 = (rand() % 8) + 2, op2 = (rand() % 8) + 2;
    int prod = op1 * op2, guess;
    double t1 = time(NULL);
    cout << op1 << " * " << op2 << " = "; cin >> guess;
    double t2 = time(NULL);
    if (guess != prod) {cout << "Very Bad" << endl;}
    else if (t2 - t1 < 5) {cout << "Good" << endl;}
    else if (t2 - t1 >= 5 || t2 - t1 <= 10) {cout << "Satisfactory" << endl;}
    else {cout << "Insufficient" << endl;}
}

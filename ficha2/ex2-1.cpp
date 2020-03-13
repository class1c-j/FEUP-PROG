/*Solve again problem 1.4 (solution of a system of linear equations in two variables), so that
 * when the system is impossible or inconsistent (a system having infinite solutions) a message
 * is shown to the user: "impossible system" or"inconsistent system".
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, d, e, f;
    cout << "a*x + b*y = c" << endl << "d*x + e*y = f" << endl;
    cout << "a? "; cin >> a;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> a;
    }
    cout << "b? "; cin >> b;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> b;
    }
    cout << "c? "; cin >> c;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> c;
    }
    cout << "d? "; cin >> d;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> d;
    }
    cout << "e? "; cin >> e;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> e;
    }
    cout << "f? "; cin >> f;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> f;
    }
    double x = (c * e - b * f) / (a * e - b * d);
    double y = (a * f - c * d) / (a * e - b * d);
    if (isinf(x) || isinf(y)) {
        cout << "Impossible system." << endl;
    }
    else if (x != x || y != y) {
        cout << "Inconsistent system." << endl;
    }
    else {
        cout << "Value of x: " << x << endl << "Value of y: " << y << endl;
    }
}

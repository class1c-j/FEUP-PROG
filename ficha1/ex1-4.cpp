/* Write a program that reads the values of a, b, c, d, e e f and determines the solution
 * of the corresponding system of equations. Consider only the cases when there is a solution
 * (it is not an impossible or inconsistent system).
 */

#include <iostream>
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
    cout << "Value of x: " << x << endl << "Value of y: " << y << endl;
}

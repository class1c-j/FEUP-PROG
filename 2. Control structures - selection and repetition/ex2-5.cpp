/* Write a program to determine the roots of a quadratic equation Ax2+Bx+C=0, the coefficients A, B and C
 * being provided by the user. The program must indicate whether the equation has 2 different real roots,
 * 2 equal real roots or2 complex roots, and the respective root values , with 3 decimal places.
 */

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    const int PREC = 3;  // number of places to show result
    double a, b, c;
    cout << fixed << setprecision(PREC);
    cout << "Ax^2 + Bx + C = 0" << endl;
    cout << "Insert value of A: ";
    cin >> a;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> a;
    }
    cout << "Insert value of B: ";
    cin >> b;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> b;
    }
    cout << "Insert value of C: ";
    cin >> c;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> c;
    }
    double delta = pow(b, 2) - 4 * a * c;
    if (delta == 0)
        cout << "The equation has 2 equal real roots: " << -b / (2 * a) << endl;
    else if (delta > 0)
        cout << "The equation has 2 different real roots: " << (-b + sqrt(delta)) / (2 * a) << " and " << (-b - sqrt(delta)) / (2 * a) << endl;
    else
        cout << "The equation has 2 complex roots: " << -b / (2 * a) << " + " << sqrt(-delta) / (2 * a) << "i and " << -b / (2 * a)
                  << " - " << sqrt(-delta) / (2 * a) << "i" << endl;
}

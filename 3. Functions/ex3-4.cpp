/*
 * Write a function that rounds a floating point number, x, to a given number of decimal places, n, returning the
 * rounded value.
 */


#include <iostream>
#include <cmath>
using namespace std;

double round(double x, unsigned n) {
    return floor(x*pow(10, n)+0.5) / pow(10, n);
}

int main() {
    double num;
    unsigned places;
    cout << "insert number: ";
    cin >> num;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> num;
    }
    cout << "insert decimal places: ";
    cin >> places;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> places;
    }
    cout << round(num, places) << endl;
}

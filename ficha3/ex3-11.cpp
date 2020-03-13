/*
 * Write a recursive function that determines the greatest common divisor of 2 numbers that it receives as parameters
 */

#include <iostream>
using namespace std;
int gcd_rec(int m, int n);

int main() {
    int a, b;
    cout << "Insert 1st number: ";
    cin >> a;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> a;
    }
    cout << "Insert 2nd number: ";
    cin >> b;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> b;
    }
    cout << "The GCD is: " << gcd_rec(a, b) << endl;
}

int gcd_rec(int m, int n) {
    if (m % n == 0) {
        return n;
    }
    else {
        return gcd_rec(n, m % n);
    }
}

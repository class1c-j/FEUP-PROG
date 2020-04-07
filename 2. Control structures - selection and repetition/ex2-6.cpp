/* Write a program to determine and write the amount that a depositor can withdraw from the bank, after n
 * years of depositing an amount q, where j% is the annual interest rate. The values of n, q and j must be
 * specified by the user. Assume that interest at the end of each year is accrued to the deposited amount.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n, q, j;
    cout << "Value of n (number of years after deposit): ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    cout << "Value of q (amount deposited): ";
    cin >> q;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> q;
    }
    cout << "Value of j (interest rate): ";
    cin >> j;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> j;
    }
    double m = q * pow((1 + j / 100), n);
    cout << "Amount available is: " << m << endl;
}

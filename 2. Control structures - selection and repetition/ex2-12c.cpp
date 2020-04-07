/* Repeat problem 2.11 so that the user can specify the precision with which he wants the result, that is,
 * the maximum variation between the value of the sum of the series, between two consecutive iterations.
 * Note that the variation can be either positive or negative.
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    double x, sum = 0, prec, i = 0;
    cout << "insert value of x: ";
    cin >> x;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> x;
    }
    cout << "precision: ";
    cin >> prec;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> prec;
    }
    double result = pow(M_E, -x);
    while (abs(result - sum) >= prec) {
        sum += (pow(x, i) / factorial(i)) * pow(-1, i);
        i ++;
    }
    cout << sum << endl;
}



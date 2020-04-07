/* Change the program you developed in a) so that the range limits and the interval of the value of the
 * angles in the table can be specified by the user (for example, if the range is [0..1] and the increment
 * is of 0.1 degrees, the table for the angles of 0, 0.1, 0.2,..., and 1 degree should be displayed).
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    double lb, ub, increment;
    cout << fixed << setprecision(5);
    cout << "Insert lower limit: ";
    cin >> lb;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> lb;
    }
    cout << "Insert upper limit: ";
    cin >> ub;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> ub;
    }
    cout << "Insert increment: ";
    cin >> increment;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> increment;
    }
    cout << "ang" << setw(10) << "sin" << setw(10) << "cos" << setw(10) << "tan" << endl;
    for (double i = lb; i <= ub; i += increment) {
        if (i == 90) {
            cout << i << setw(10) << 1 << setw(10) << 0 << setw(10) << std::numeric_limits<double>::infinity();
        }
        else {
            cout << i << setw(10) << sin(i*M_PI/180) << setw(10) << cos(i*M_PI/180) << setw(10)
            << tan(i*M_PI/180) << endl;
        }
    }
}

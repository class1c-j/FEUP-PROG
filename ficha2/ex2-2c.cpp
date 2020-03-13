/* Write a program that reads 3 positive numbers from the keyboard and determines if they
 * can represent the lengthof the 3 sides of a triangle (tip: it is not possible to build a
 * triangle if the sum of the 2 smallest lengths is smaller thanthe largest length). If any of
 * the numbers is not positive the program must show an error message.
 */

#include <iostream>
using namespace std;

int main() {
    double max = 0, min = 99999;
    double n, mid;
    bool valid = true;  // help with negative number validating
    cout << "Enter 3 numbers: " << endl;
    for (int i = 1; i <= 3; i++) {
        cin >> n;
        while (!cin) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid input! Try again." << endl;
            cin >> n;
        }
        if (n < 0) {
            valid = false;
            break;
        }
        if (n > max) {
            max = n;
        }
        else if (n < min) {
            min = n;
        }
        else {
            mid = n;
        }
    }
    if (mid + min >= max && valid) {
        cout << "Possible" << endl;
    }
    else if (valid) {
        cout << "Not possible" << endl;
    }
    else {
        cout << "Invalid input (negative number)" << endl;
    }
}

/* Write a program that reads 3 numbers from the keyboard and determines the largest and the
 * smallest number.
 */

#include <iostream>
using namespace std;

int main() {
    double max = -9999, min = 9999;
    double n;
    cout << "Enter 3 numbers: " << endl;
    for (int i = 1; i <= 3; i++) {
        cin >> n;
        while (!cin) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid input! Try again: ";
            cin >> n;
        }
        if (n > max) {
            max = n;
        }
        else if (n < min) {
            min = n;
        }
    }
    cout << "max: " << max << endl << "min: " << min << endl;
}

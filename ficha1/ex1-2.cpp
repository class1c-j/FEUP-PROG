/* exercise 1.2: Write a program that reads 3 integer numbers from the keyboard and shows
 * on the screen their mean value and the difference between each number and the mean
 * value. The dialog with the user must be similar to the following
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int PREC = 3;  // number of decimal places wanted
    double a, b, c;
    cout << fixed << setprecision(PREC);
    cout << "Please, input 3 integer numbers" << endl;
    cout << "A ? "; cin >> a;
    while (cin.fail()) {  // validating input for a
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> a;
    }
    cout << "B ? "; cin >> b;
    while (cin.fail()) {  // validating input for b
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> b;
    }
    cout << "C ? "; cin >> c;
    while (cin.fail()) {  // validating input for c
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> c;
    }
    double mean = (a + b + c) / 3;
    cout << "mean: " << mean << endl;
    cout << "A-mean: " << a - mean << endl;
    cout << "B-mean: " << b - mean << endl;
    cout << "C-mean: " << c - mean << endl;
}

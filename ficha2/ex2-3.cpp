/* Write a program that reads 2 integer numbers from the keyboard and tests whether their sum
 * would produce overflow (the result would be greater than INT_MAX) or underflow (the result
 * would be lower than INT_MIN). If this happens the program must show the message "sum overflow"
 * or "sum underflow", otherwise it should show the result of the sum.
 */

#include <iostream>
#include <climits>
using namespace std;

int main() {
    double n1, n2;
    cout << "Insert first number: "; cin >> n1;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n1;
    }
    cout << "Insert second number: "; cin >> n2;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n2;
    }
    if (n1 + n2 > INT_MAX) {
        cout << "Sum overflow" << endl;
    }
    else if (n1 + n2 < INT_MIN) {
        cout << "Sum underflow" << endl;
    }
    else {
        cout << n1 + n2 << endl;
    }
}

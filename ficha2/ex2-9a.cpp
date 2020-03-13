/* Write a program that reads a 3-digit integer and determines whether or not it is a palindrome (suggestion:
 * use the division and module operators to separate the integer into its digits.
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "insert 3 digit number: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    if (n >= 1000 || n <= 99) {
        cout << "Not a 3 digit number." << endl;
    }
    if (n / 100 == n % 10) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not palindrome" << endl;
    }
}

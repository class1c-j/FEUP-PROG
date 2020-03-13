/* Generalize the program in a) in order to treat unsigned integers with a greater number of digits. Note:
 * do not use arrays or vectors to store the digits.
 */

#include <iostream>
using namespace std;

int main() {
    int n, num, dig, rev;
    cout << "Insert number: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    while (num != 0) {
        dig = num % 10;
        rev = rev*10 + dig;
        num /= 10;
    }

    if (n = rev) {
        cout << "Palindrome." << endl;
    }
    else {
        cout << "Not palindrome." << endl;
    }
}

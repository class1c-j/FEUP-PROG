/* Write a program that reads a number from the keyboard and determines if it is prime. Note: it is not
 * necessary to test all divisors in the range [2..n[; it is enough to test divisors until the integer part
 * of the square root of n.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    cout << "Insert number: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "Not prime." << endl;
            break;
        }
    }
    if (i > sqrt(n)) {
        cout << "Prime." << endl;
    }
}

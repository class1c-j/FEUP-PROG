/* Write a program that reads an integer and breaks it down into prime factors (example: 20 = 2x2x5).
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "insert number: " << endl;
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    for (int i = 2; n != 1; i++) {
        while (n % i == 0) {
            n = n / i;
            cout << i << " ";
        }
    }
}

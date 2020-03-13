/*  Series giving the value of the mathematical constant pi :
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, a = 2;
    double sum = 0;
    cout << "insert number of series terms to calculate: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    for (double i = 1; i <= n; i += 2) {
        sum += (4 / i) * pow(-1, a);
        a ++;
    }
    cout << sum << endl;
}

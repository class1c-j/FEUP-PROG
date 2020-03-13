/*  Series giving the value of the mathematical constant e:
 */

#include <iostream>
using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    double sum = 0;
    cout << "insert number of terms to calculate: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    for (double i = 0; i <= n; i ++) {
        sum += (1 / factorial(i));
    }
    cout << sum << endl;
}

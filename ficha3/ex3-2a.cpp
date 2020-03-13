/*
 * Rewrite the programs of problem 2.7, for determining prime numbers, in order to use a function isPrime(),
 */

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    if (i > sqrt(n)) {
        return 1;
    }
}

int main() {
    int n;
    cout << "Insert number: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    cout << isPrime(n) << endl;
}

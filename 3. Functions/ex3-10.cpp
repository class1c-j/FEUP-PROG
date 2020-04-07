/*
 * Write a function, factorial_ite(unsigned int n), that determines the factorial of a number using an iterative
 * algorithm
 * Write a recursive function, factorial_rec(unsigned int n), that determines the factorial of a number
 */

#include <iostream>
using namespace std;
unsigned long long factorial_ite(unsigned int n);
unsigned long long factorial_rec(unsigned int n);

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
    cout << "Factorial (iterative) is: " << factorial_ite(n) << endl;
    cout << "Factorial (recursive) is: " << factorial_rec(n) << endl;
}

unsigned long long factorial_ite(unsigned int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i ++) {
        result *= i;
    }
    return result;
}

unsigned long long factorial_rec(unsigned int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial_rec(n - 1);
    }
}

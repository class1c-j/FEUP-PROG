/* Write a program that reads the values of n, delta and nMaxIter and that calculates the square root of n using the
 * algorithm described previously. Always use 1 as initial estimate of rq.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, rq = 1, rqn = 1, nMaxIter, delta;
    int iter = 1;
    cout << "Insert number: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    cout << "Insert delta: ";
    cin >> delta;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> delta;
    }
    cout << "Insert max iterations: ";
    cin >> nMaxIter;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> nMaxIter;
    }
    while ((n - pow(rqn, 2) >= delta) || iter <= nMaxIter) {
        rqn = (rq + n / rq) / 2;
        rq = rqn;
        iter ++;
    }
    cout << rqn << endl;
}

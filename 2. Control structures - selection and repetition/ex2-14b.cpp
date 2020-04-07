/* Modify the program in a) in order to present the result with the same number of decimal places used in
 * specifying the delta value; for that you should find an algorithm to determine the number of decimal
 * places.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int dec_places(double n) {
    int places = 0;
    while (n < 1) {
        n *= 10;
        places ++;
    }
    return places;
}

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
    cout << fixed << setprecision(dec_places(delta));
    cout << "Estimate: " << rqn << " Real: " << sqrt(n) << endl;
}

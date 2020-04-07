/* 
 * Rewrite the program of problem 2.14 in order to use a function to calculate the square root, using the method 
 * indicated in that problem.
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

double sq_root(double value, double precision, int max_iterations) {
    double rq = 1, rqn = 1;
    int iter = 1;
    while ((value - pow(rqn, 2) >= precision) || iter <= max_iterations) {
        rqn = (rq + value / rq) / 2;
        rq = rqn;
        iter ++;
    }
    return rqn;
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
    cout << "Insert precision: ";
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
    cout << fixed << setprecision(dec_places(delta));
    cout << sq_root(n, delta, nMaxIter) << endl;
}

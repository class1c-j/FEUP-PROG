/*
 * Rewrite the program of problem 1.6, for calculating the area of a triangle using the Heron formula, in order to use
 * the following functions:
 */

#include <iostream>
#include <cmath>

using namespace std;
double distance(double x1, double y1, double x2, double y2);

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x1, y1, x3, y3);
    double s = (a + b + c) / 3;
    return sqrt((s)*(s-a)*(s-b)*(s-c));
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "Insert coordinates of point 1: ";
    cin >> x1 >> y1;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> x1 >> y1;
    }
    cout << "Insert coordinates of point 2: ";
    cin >> x2 >> y2;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> x2 >> y2;
    }
    cout << "Insert coordinates of point 3: ";
    cin >> x3 >> y3;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> x3 >> y3;
    }

    cout << area(x1, y1, x2, y2, x3, y3);
}

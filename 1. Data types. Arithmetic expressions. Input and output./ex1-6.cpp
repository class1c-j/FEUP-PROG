/*The area of a triangle can be determined using the Heron's formula: area  s(s  a)(s  b)
 * (s  c) where s, a, b and c are, respectively, the semi-perimeter and the length of the 3
 * sides. Write a program that reads the coordinates of the 3 vertices of a triangle and
 * calculates the area of the triangle, using that formula.
 */

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc;
    cout << "Coordinates of vertice A (x y): ";
    while (!(cin >> xa >> ya)) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: " << endl;
        cin >> xa >> ya;
    }
    cout << "Coordinates of vertice B (x y): ";
    while (!(cin >> xb >> yb)) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: " << endl;
        cin >> xb >> yb;
    }
    cout << "Coordinates of vertice C (x y): ";
    while (!(cin >> xc >> yc)) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: " << endl;
        cin >> xc >> yc;
    }
    double a = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    double b = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
    double c = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
    double s = (a + b + c) / 2;
    double area = sqrt((s) * (s - a) * (s - b) * (s - c));
    cout << "The area of the triangle is: " << area << endl;
}

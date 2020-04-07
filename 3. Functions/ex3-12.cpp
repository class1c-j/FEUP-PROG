/*
 * Write and test a program that overloads a function, area(),
 */

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x1, y1, x3, y3);
    double s = (a + b + c) / 3;
    return sqrt((s)*(s-a)*(s-b)*(s-c));
}

double area(double x1, double y1, double x2, double y2) {
    double height = abs(y1 - y2);
    double width = abs(x1 - x2);
    return height * width;
}

double area(double radius) {
    return M_PI * pow(radius, 2);
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "insert radius, coordinates of 3 vertices, or coordinates of 2 opposite vertices" << endl;
    cin >> x1;
    cout << area(x1) << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << area(x1, y1, x2, y2) << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << area(x1, y1, x2, y2, x3, y3) << endl;
}

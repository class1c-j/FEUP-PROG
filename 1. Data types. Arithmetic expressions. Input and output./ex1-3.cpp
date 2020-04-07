/* The mass of a sphere is given by the expression M = 4/3(r3) where M,  and r are,
 * respectively, the mass of the sphere, the specific mass of the material from which it is
 * made, and its radius. Write a program that, given the values of  and r, determines the
 * value of M. The user must be informed about the units used to represent all the values: Kg/m3, m and Kg
 * for , r and M, respectively. Use a constant to represent the value of .
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double density, radius;
    cout << "Enter the value of density (Kg/m³): "; cin >> density;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {  // validating input for radius
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> density;
    }
    cout << "Enter the radius (m): "; cin >> radius;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {  // validating input for radius
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> radius;
    }
    double mass = 4 / 3 * (density * M_PI * pow(radius, 3));
    cout << "Mass (Kg): " << mass << endl;
}

/* Write a program that displays on the screen a table of sines, cosines and tangents of the angles in the
 * range [0..90] degrees, with intervals of 15 degrees, as shown below (note the particular case of the last
 * line, corresponding to the 90 degree angle).
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    cout << fixed << setprecision(5);
    cout << "ang" << setw(10) << "sin" << setw(10) << "cos" << setw(10) << "tan" << endl;
    for (double i = 0; i <= 90; i += 15) {
        if (i == 90) {
            cout << i << setw(10) << 1 << setw(10) << 0 << setw(10) << std::numeric_limits<double>::infinity();
        }
        else {
            cout << i << setw(10) << sin(i*M_PI/180) << setw(10) << cos(i*M_PI/180) << setw(10)
            << tan(i*M_PI/180) << endl;
        }
    }
}

/* Repeat problem 2.11 so that the user can specify the precision with which he wants the result, that is,
 * the maximum variation between the value of the sum of the series, between two consecutive iterations.
 * Note that the variation can be either positive or negative.
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
    double sum = 0, prec, i = 0;
    cout << "precision: "; cin >> prec;
    cout << setprecision(10);
    while (abs(sum - M_PI) >= prec) {
        sum += (4 / (2*i + 1)) * pow(-1, i);
        i++;
    }
    cout << sum << endl;
}

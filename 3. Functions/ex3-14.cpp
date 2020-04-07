/*
 * Write a function that with the parameters f ,a, b e n, above mentioned, that calculates the integral of a function,
 * using this method.
 */

#include <iostream>
#include <cmath>
using namespace std;

double g(double x) {
    return pow(x, 2);
}

double h(double x) {
    return sqrt(4 - pow(x, 2));
}

double integrateTR(double(f(double)), double a, double b, int n) {
    double sum = 0;
    double h = (b - a) / (double) n;
    for (int i = 1; i <= n; i ++) {
        sum += (h/2) * (f(a + ((i - 1) * h)) + f(a + (i*h)));
    }
    return sum;
}

int main(){
    double ga = 0, gb = 10;
    int n;
    cout << "Insert value for n: " << endl; cin >> n;
    cout << "Integral of x² when a = 0 and b = 10: " << integrateTR(g, ga, gb, n) << endl;
    double ha = -2, hb = 2;
    cout << "Integral of sqrt(4-x²) when a = -2 and b = 2: " << integrateTR(h, ha, hb, n) << endl;
}

/* Write a program that writes on the screen all the prime numbers lower than 1000.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int d;
    for (int i = 2; i < 1000; i++) {
        for (d = 2; d <= sqrt(i); d++) {
            if (i % d == 0) {
                break;
            }
        }
        if (d > sqrt(i)) {
            cout << i << endl;
        }
    }
}

/* Write a program that determines the largest prime number that can be stored in a variable of type
 * unsigned long.
 */

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    if (i > sqrt(n)) {
        return 1;
    }
}

int main() {
    const double size_ull = pow(2, sizeof(unsigned long long) * 8);
    for (int i = size_ull; i >= 0; i --)
    {
        if (isPrime(i))
        {
            cout << i << endl;
            break;
        }
    }
}


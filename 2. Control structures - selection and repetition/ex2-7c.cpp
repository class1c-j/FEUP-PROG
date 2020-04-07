/* Write a program that writes on the screen the first 100 prime numbers.
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
    int primesFound = 0;
    int current = 2;
    while (primesFound <= 100) {
        if (isPrime(current)) {
            cout << current << endl;
            primesFound ++;
        }
        current ++;
    }
}


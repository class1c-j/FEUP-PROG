/*
 * You must develop a set of functions that allow the manipulation of fractions, represented by independent variables
 * that represent the numerator and denominator of each fraction
 */

#include <iostream>
using namespace std;
bool readFraction(int &numerator, int &denominator);
void reduceFraction(int &numerator, int &denominator);
double gcd(int a, int b);
void addFractions(int &numerator1, int &denominator1, int numerator2, int denominator2);
void subtractFractions(int &numerator1, int &denominator1, int numerator2, int denominator2);
void multiplyFractions(int &numerator1, int &denominator1, int numerator2, int denominator2);
void divideFractions(int &numerator1, int &denominator1, int numerator2, int denominator2);

int main() {
    int numerator, denominator;
    int numerator2, denominator2;
    int op;
    cout << "insert 1st fraction in form a/b: " << endl;
    readFraction(numerator, denominator);
    cout << "reduced: ";
    reduceFraction(numerator, denominator);
    cout << numerator << "/" << denominator << endl;

    cout << "insert 2nd fraction in form a/b: " << endl;
    readFraction(numerator2, denominator2);
    cout << "reduced: ";
    reduceFraction(numerator2, denominator2);
    cout << numerator2 << "/" << denominator2 << endl;

    cout << "Select operation: (1) - add, (2) - sub, (3) - mul, (4) - div: ";
    cin >> op;
    switch (op) {
        case 1:
            addFractions(numerator, denominator, numerator2, denominator2);
            cout << numerator << "/" << denominator << endl;
            break;
        case 2:
            subtractFractions(numerator, denominator, numerator2, denominator2);
            cout << numerator << "/" << denominator << endl;
            break;
        case 3:
            multiplyFractions(numerator, denominator, numerator2, denominator2);
            cout << numerator << "/" << denominator << endl;
            break;
        case 4:
            divideFractions(numerator, denominator, numerator2, denominator2);
            cout << numerator << "/" << denominator << endl;
            break;
        default:
            cerr << "Invalid." << endl;
            break;
    }
}

bool readFraction(int &numerator, int &denominator) {
    char del;
    if (cin >> numerator >> del >> denominator and del == '/') {
        return 1;
    }
    else {
        while (cin.fail()) {
            cerr << "Invalid input" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }

        numerator = 0;
        denominator = 0;
        return 0;
    }
}

void reduceFraction(int &numerator, int &denominator) {
    int gcdn = gcd(numerator, denominator);
    numerator /= gcdn;
    denominator /= gcdn;
}

double gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void addFractions(int &numerator1, int &denominator1, int numerator2, int denominator2) {
    if (denominator1 == denominator2) {
        numerator1 = numerator1 + numerator2;
    }
    else {
        numerator1 = denominator2 * numerator1 + denominator1 * numerator2;
        denominator1 = denominator1 * denominator2;
    }
    reduceFraction(numerator1, denominator1);
}

void subtractFractions(int &numerator1, int &denominator1, int numerator2, int denominator2) {
    if (denominator1 == denominator2) {
        numerator1 = numerator1 - numerator2;
    }
    else {
        numerator1 = denominator2 * numerator1 - denominator1 * numerator2;
        denominator1 = denominator1 * denominator2;
    }
    reduceFraction(numerator1, denominator1);
}

void multiplyFractions(int &numerator1, int &denominator1, int numerator2, int denominator2) {
    numerator1 *= numerator2;
    denominator1 *= denominator2;
    reduceFraction(numerator1, denominator1);
}

void divideFractions(int &numerator1, int &denominator1, int numerator2, int denominator2) {
    numerator1 *= denominator2;
    denominator1 *= numerator2;
    reduceFraction(numerator1, denominator1);
}

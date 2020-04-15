/*
   
   Redo problem 3.8 using structs to represent fractions:
   
   struct Fraction {
        int numerator;
        int denominator;
   };
    
   Adapt the prototype of the functions accordingly; for example, the prototype of
   readFraction() must now be bool readFraction(Fraction &fraction).
   
*/

#include <iostream>

struct Fraction {
    int numerator;
    int denominator;
};

bool readFraction(Fraction &fraction) {
    char del;
    if (std::cin >> fraction.numerator >> del >> fraction.denominator) {
        return true;
    } else {
        while (std::cin.fail()) {
            std::cerr << "Invalid input\n";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
        }
        fraction.numerator = fraction.denominator = 0;
        return false;
    }
}

void showFraction(Fraction fraction) {
    std::cout << fraction.numerator << "/" << fraction.denominator;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduceFraction(Fraction &fraction) {
    int gcdn = gcd(fraction.numerator, fraction.denominator);
    fraction.numerator /= gcdn;
    fraction.denominator /= gcdn;
}

void addFractions(Fraction &fraction1, Fraction &fraction2) {
    if (fraction1.denominator == fraction2.denominator) {
        fraction1.numerator += fraction2.numerator;
    } else {
        fraction1.numerator = fraction2.denominator * fraction1.numerator + fraction1.denominator * fraction2.numerator;
        fraction1.denominator = fraction1.denominator * fraction2.denominator;
    }
    reduceFraction(fraction1);
}

void subtractFractions(Fraction &fraction1, Fraction &fraction2) {
    if (fraction1.denominator == fraction2.denominator) {
        fraction1.numerator -= fraction2.numerator;
    } else {
        fraction1.numerator = fraction2.denominator * fraction1.numerator - fraction1.denominator * fraction2.numerator;
        fraction1.denominator = fraction1.denominator * fraction2.denominator;
    }
    reduceFraction(fraction1);
}

void multiplyFractions(Fraction &fraction1, Fraction &fraction2) {
    fraction1.numerator *= fraction2.numerator;
    fraction1.denominator *= fraction2.denominator;
    reduceFraction(fraction1);
}

void divideFractions(Fraction &fraction1, Fraction &fraction2) {
    fraction1.numerator *= fraction2.denominator;
    fraction1.denominator *= fraction2.numerator;
    reduceFraction(fraction1);
}

int main() {
    Fraction fraction1{}, fraction2{};
    int op;
    std::cout << "Fraction 1 (a/b): "; readFraction(fraction1);
    std::cout << "Fraction 2 (a/b): "; readFraction(fraction2);
    std::cout << "Select operation: (1) - add, (2) - sub, (3) - mul, (4) - div: ";
    std::cin >> op;
    switch(op) {
        case 1:
            addFractions(fraction1, fraction2);
            showFraction(fraction1); std::cout << "\n";
            break;
        case 2:
            subtractFractions(fraction1, fraction2);
            showFraction(fraction1); std::cout << "\n";
            break;
        case 3:
            multiplyFractions(fraction1, fraction2);
            showFraction(fraction1); std::cout << "\n";
            break;
        case 4:
            divideFractions(fraction1, fraction2);
            showFraction(fraction1); std::cout << "\n";
            break;
        default:
            std::cerr << "Invalid operation." << std::endl;
    }
}

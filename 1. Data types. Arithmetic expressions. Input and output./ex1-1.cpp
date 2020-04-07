 /* exercise 1.1: Write a program that reads a letter or other symbol from the keyboard and
 * shows its ASCII code.
 */

#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Insert character: " << endl;
    cin >> c;
    cout << "The ascii code from the character inserted is: " << int(c) << endl;
}


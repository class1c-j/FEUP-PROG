/*
 * Write a function bool readInt(int &x) that tries to read a valid integer number from the keyboard.
 */

#include <iostream>
using namespace std;

bool readInt(int &x) {
    cin >> x;
    if (cin.fail()) {
        if (cin.eof()) {
            return 0;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            return 0;
        }
    }
    else if (!isdigit(cin.peek()) && cin.peek() != '\n') {
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
    return 1;
}

int main() {
    int x;
    cout << "Insert integer: " << endl;
    cout << readInt(x) << endl;
}

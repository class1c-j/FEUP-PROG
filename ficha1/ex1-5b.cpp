/* Modify the program so that the user must input a separator between hours, minutes and
 * seconds (ex: 10:35:50). Although the separator usually used is ':', consider that any
 * separator is valid
 */

#include <iostream>
using namespace std;

int main() {

    int h1, m1, s1;
    cout << "Time1 (hours minutes seconds) ";
    cin >> h1;
    while(!cin >> h1 || h1 > 23) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> h1;
    }
    while (!isdigit(cin.peek())) {
        cin.clear();
        cin.ignore();
    }
    cin >> m1;
    while(!cin >> m1 || m1 > 59) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> m1;
    }
    while (!isdigit(cin.peek())) {
        cin.clear();
        cin.ignore();
    }
    cin >> s1;
    while(!cin >> s1 || s1 > 59) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> s1;
    }

    int h2, m2, s2;
    cout << "Time2 (hours minutes seconds) ";
    cin >> h2;
    while(!cin >> h2 || h2 > 23) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> h2;
    }
    while (!isdigit(cin.peek())) {
        cin.clear();
        cin.ignore();
    }
    cin >> m2;
    while(!cin >> m2 || m2 > 59) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> m2;
    }
    while (!isdigit(cin.peek())) {
        cin.clear();
        cin.ignore();
    }
    cin >> s2;
    while(!cin >> s2 || s2 > 59) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> s1;
    }

    int s = s1 + s2 % 60;
    int m = m1 + m2 + (s / 60);
    int h = h1 + h2 + (m / 60);
    int d = h / 24;
    s = s % 60;
    m = m % 60;
    h = h % 24;
    cout << "Time 1 + Time 2 = " << d << " day, " << h << " hours, " << m << " minutes, and "
    << s << " seconds." << endl;
}

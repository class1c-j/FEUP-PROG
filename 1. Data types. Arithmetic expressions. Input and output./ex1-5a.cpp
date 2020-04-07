/*Write a program that reads two times, expressed in hours, minutes and seconds, and
 * determines their sum.
 */

#include <iostream>
using namespace std;

int main() {
    int h1, m1, s1;
    cout << "Time1 (hours minutes seconds) "; cin >> h1 >> m1 >> s1;
    while(!cin >> h1 >> m1 >> s1 || (h1 > 23) || (m1 > 59) || (s1 > 59)) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> h1 >> m1 >> s1;
    }
    int h2, m2, s2;
    cout << "Time2 (hours minutes seconds) "; cin >> h2 >> m2 >> s2;
    while(!cin >> h2 >> m2 >> s2 || (h2 > 23) || (m2 > 59) || (s2 > 59)) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> h2 >> m2 >> s2;
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

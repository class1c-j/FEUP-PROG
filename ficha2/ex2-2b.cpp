/* Write a program that reads 3 numbers from the keyboard and writes them on the screen,
 * in descending order.
 */

#include <iostream>
using namespace std;

int main()
{
    double max = 0, min = 99999;
    double n, mid;
    cout << "Enter 3 numbers: " << endl;
    for (int i=1; i<=3; i++)
    {
        cin >> n;
        while (!cin) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid input! Try again: ";
            cin >> n;
        }
        if (n > max) {
            max = n;
        }
        else if (n < min) {
            min = n;
        }
        else {
            mid = n;
        }
    }
    cout << max << " " << mid << " " << min;
}

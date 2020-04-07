/* Series giving the value of e -x (com x real positivo previamente definido):
 */

#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main()
{
    using namespace std;

    int n;
    double x, sum = 0;
    cout << "insert ammount of terms: ";
    cin >> n;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> n;
    }
    cout << "insert value of x: ";
    cin >> x;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> x;
    }

    for (double i = 0; i <= n; i ++) {
        sum += (pow(x, i) / factorial(i)) * pow(-1, i);
    }
    cout << sum << endl;
}

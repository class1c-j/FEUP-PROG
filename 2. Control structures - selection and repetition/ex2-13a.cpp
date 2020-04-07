/* Write a program that reads a sequence of integer numbers, and determines and writes the sum, the mean,
 * the standard deviation, the smallest and the largest of the numbers, in the following situations:
 * the length of the sequence is previously indicated by the user;
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int len;
    double sum = 0, sum_squares = 0, mean = 0, dev, max = 0, min = 999999;
    cout << "Number of terms: "; cin >> len;
    for (int i = 1; i <= len; i++) {
        double n;
        cout << "Insert value " << i << ": ";
        cin >> n;
        while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid input! Try again: ";
            cin >> n;
        }
        sum += n;
        sum_squares += pow(n, 2);
        if (n > max) {
            max = n;
        }
        else if (n < min) {
            min = n;
        }
    }
    mean = sum / len;
    dev = sqrt((sum_squares - 2 * mean * sum + pow(mean, 2) * len) / (len - 1));
    cout << "Mean: " << mean << endl << "Standard deviation: " << dev << endl << "Max: " << max << endl
         << "Min: " << min << endl;
}

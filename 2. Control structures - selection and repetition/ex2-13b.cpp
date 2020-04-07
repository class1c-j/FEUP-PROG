/* Write a program that reads a sequence of integer numbers, and determines and writes the sum, the mean,
 * the standard deviation, the smallest and the largest of the numbers, in the following situations:
 * the end of the sequence is indicated by the value 0 (which is not considered to be part of the sequence); at the end,
 * the program must indicate the length of the sequence;
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sum = 0, sum_squares = 0, mean = 0, dev, max = 0, min = 999999, num, len = 1;
    do {
        cout << "Insert value " << len << ": ";
        cin >> num;
        while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n')) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Invalid input! Try again: ";
            cin >> num;
        }
        sum += num;
        sum_squares += pow(num, 2);
        if (num > max && num != 0) {
            max = num;
        }
        else if (num < min && num != 0) {
            min = num;
        }
        len ++;
    } while (num != 0);
    mean = sum / len;
    dev = sqrt((sum_squares - 2 * mean * sum + pow(mean, 2) * len) / (len - 1));
    cout << "Mean: " << mean << endl << "Standard deviation: " << dev << endl << "Max: " << max << endl
         << "Min: " << min << endl;
}

/* Write a program that reads a sequence of integer numbers, and determines and writes the sum, the mean,
 * the standard deviation, the smallest and the largest of the numbers, in the following situations:
 * the end of the sequence is indicated by the value 0 (which is not considered to be part of the sequence); at the end,
 * the program must indicate the length of the sequence;
 */

#include <iostream>
#include <cmath>

int main() {
    using namespace std;
    bool another;
    double sum = 0, sum_squares = 0, mean = 0, dev, num, len = 0;
    int maximum = 0, minimum = 999999;
    do {
        bool valid;
        another = true;
        do {
            cout << "Insert value " << len + 1 << ": "; cin >> num;
            valid = true;
            if (cin.fail()) {
                valid = false;
                if (cin.eof()) {
                    cout << "eof" << endl;
                    another = false;
                    cout << len << endl;
                } else {
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            } else {
                cin.ignore(1000, '\n');
            }
        } while (another && !valid);
        sum += num;
        sum_squares += pow(num, 2);
        if (num > maximum) {
            maximum = num;
        }
        else if (num < minimum ) {
            minimum = num;
        }
        len ++;
        if (valid) {
            mean = sum / len;
            dev = sqrt((sum_squares - 2 * mean * sum + pow(mean, 2) * len) / (len - 1));
        } else {
            cerr << "Invalid!" << endl;
        }
    } while (another);
    cout << "Mean: " << mean << endl << "Standard deviation: " << dev << endl << "Max: " << maximum << endl
         << "Min: " << minimum << endl;
}

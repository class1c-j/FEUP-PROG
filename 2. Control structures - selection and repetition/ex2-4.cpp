/* The cost of transporting a certain merchandise is determined, depending on its weight, as
 * follows: if the weight is less or equal to 500 grams the cost is 5 euros; if the weight is
 * between 501 grams and 1000 grams, inclusive, the cost is equal to 5 euros plus 1.5 euros for
 * each additional 100 grams or fraction above 500 grams; if the weight exceeds 1000 grams, the cost is 12.5 euros plus
 * 5 euros for each additional 250 grams or fraction above 1000 grams. Write a program that, given the weight of a
 * certain merchandise, determines the cost of its transportation.
 */

#include <iostream>
using namespace std;

int main() {
    double weight, cost = 5;
    cout << "Insert the weight in grams: ";
    cin >> weight;
    while (!cin || !(isdigit(cin.peek()) || cin.peek() == '\n' || weight < 0)) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input! Try again: ";
        cin >> weight;
    }
    while (weight <= 1000 && weight >= 600) {
        cost += 1.5;
        weight -= 100;
    }
    if (weight > 1000) {
        cost = 12.5;
        while (weight >= 1250) {
            cost += 5;
            weight -= 250;
        }
    }
    cout << "The cost in euros is: " << cost << endl;
}

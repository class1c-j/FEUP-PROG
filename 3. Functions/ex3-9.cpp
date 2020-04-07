/*
 * The final result of this problem will be a program to show, on the screen, the calendar of a given year. The
 * development of this program will be done modularly, using a bottom-up approach.
 */

#include <iostream>
#include <iostream>
using namespace std;
bool isLeap(int year);
int numberDays(int month, int year);
int monthCode(int month, int year);
int weekDay(int day, int month, int year);
void showMonth(int month, int year);
void showYear(int year);
int decentMod(int n, int d);

int main() {
    int year;
    cout << "Insert year: "; cin >> year;
    showYear(year);
}

bool isLeap(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int numberDays(int month, int year) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            if (isLeap(year)) {
                return 29;
            } else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            cout << "Invalid month." << endl;
            break;
    }
    return 0;
}

int weekDay(int day, int month, int year) {
    // Saturday = 0, Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6
    return ((int) (5*(year % 100)/4 + monthCode(month, year) + day - 2 * ((year / 100) % 4)) + 7 ) % 7;
}

int monthCode(int month, int year) {
    switch (month) {
        case 1:
            if (isLeap(year)) {
                return 6;
            } else {
                return 0;
            }
        case 2:
            if (isLeap(year)) {
                return 2;
            } else {
                return 3;
            }
        case 3: return 3;
        case 4: return 6;
        case 5: return 1;
        case 6: return 4;
        case 7: return 6;
        case 8: return 2;
        case 9: return 5;
        case 10: return 0;
        case 11: return 3;
        case 12: return 5;
    }
    return 0;
}

void showMonth(int month, int year) {
    int nDays = numberDays(month, year);
    int firstDay = weekDay(1, month, year);
    int firstWeek = (firstDay) % 7;
    if (firstWeek == 0) firstWeek += 1;
    switch (month) {
        case 1:
            cout << "January/" << year << endl;
            break;
        case 2:
            cout << "February/" << year << endl;
            break;
        case 3:
            cout << "March/" << year << endl;
            break;
        case 4:
            cout << "April/" << year << endl;
            break;
        case 5:
            cout << "May/" << year << endl;
            break;
        case 6:
            cout << "June/" << year << endl;
            break;
        case 7:
            cout << "July/" << year << endl;
            break;
        case 8:
            cout << "August/" << year << endl;
            break;
        case 9:
            cout << "September/" << year << endl;
            break;
        case 10:
            cout << "October/" << year << endl;
            break;
        case 11:
            cout << "November/" << year << endl;
            break;
        case 12:
            cout << "December/" << year << endl;
            break;
    }
    cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
    cout << "";
    for (int i = 1; i < decentMod((firstDay), 7); i ++) {
        cout << '\t';
    }
    for (int j = 1; j <= nDays; j++) {
        cout << j << '\t';
        if (weekDay(j, month, year) % 7 == 0) {
            cout << endl;
        }
    }
}

void showYear(int year) {
    for (int i = 1; i <= 12; i++) {
        showMonth(i, year);
        cout << endl;
    }
}

int decentMod(int n, int d) {
    int result = n % d;
    while (result <= 0) {
        result += d;
    }
    return result;
}

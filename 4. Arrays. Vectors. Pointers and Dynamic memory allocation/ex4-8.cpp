/*
 
   Write a program that reads the pluviosity observed in every day of a given year and determines the following 
   statistical data: the average daily pluviosity; the average monthly pluviosity; the date(s) of maximum pluviosity;
   the date(s) in which the pluviosity was above the average daily pluviosity. The pluviosity values must be stored in a 2D
   STL vector, indexed by month and day (note: the number of days is not constant for every month; the vector should have
   the mumber of elements strictly necessary). The program must have independent functions to "read" the pluviosity
   (note: instead of reading the values, generate them randomly) and to calculate  each  one  of  the  statistical  values.
   The results must be shown on the screen by the main() function. A function for calculating the number of days
   of each month of the given year must be used (see problem 3.9.b).
  
*/ 

#include <vector>
#include <iostream>
#include <algorithm>

bool isLeap(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int numberDays(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2:
            return isLeap(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            std::cout << "Invalid month." << std::endl;
            break;
    }
    return 0;
}

double avgDaily(const std::vector<std::vector<int>> &data, int numDays) {
    double sum = 0;
    for (const auto &i : data) {
        for (int j : i) {
            sum += j;
        }
    }
    return sum / numDays;
}

double avgMonthly(const std::vector<std::vector<int>> &data) {
    std::vector<double> avgDays;
    double yearSum = 0;
    for (const auto &month : data) {
        double monthSum = 0;
        for (int i : month) {
            monthSum += i;
        }
        avgDays.push_back(monthSum / month.size());
    }
    for (int i = 0; i < 11; i ++) {
        yearSum += avgDays.at(i);
    }
    return yearSum / 12;
}

std::vector<std::vector<int>> maxDay(const std::vector<std::vector<int>> &data) {
    int maxVal = 0;
    std::vector<int> answer = {0, 0};
    std::vector<std::vector<int>> result;
    for (const auto & row : data) {
        for (int col : row) {
            if (col > maxVal) {
                maxVal = col;
            }
        }
    }
    for (int row = 0; row < data.size(); row ++) {
        for (int col = 0; col < data.at(row).size(); col ++) {
            if (data.at(row).at(col) == maxVal) {
                result.push_back({col + 1, row + 1});
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> aboveAvg(const std::vector<std::vector<int>> &data, int numDays) {
    double avg = avgDaily(data, numDays);
    std::vector<std::vector<int>> answer;
    for (int i = 0; i < data.size(); i ++) {
        for (int j = 0; j < data.at(i).size(); j ++) {
            if (data.at(i).at(j) > avg) {
                answer.push_back({j + 1, i + 1});
            }
        }
    }
    return answer;
}


void readYear(std::vector<std::vector<int>> &data, int year) {
    for (int i = 0; i < 11; i ++) {
        std::vector<int> month(numberDays(i+1, year));
        for (int d = 0; d < numberDays(i+1, year); d ++) {
            month.at(d) = rand() % 101;
        }
        data.at(i) = month;
    }
}


int main() {
    const int MONTHS = 12;
    int year;
    std::cout << "Insert year: ";
    std::cin >> year;
    int numDays = (isLeap(year)) ? 366 : 365;
    std::vector<std::vector<int>> data(MONTHS);
    readYear(data, year);
    std::cout << "Average Daily: " << avgDaily(data, numDays) << '\n';
    std::cout << "Average Monthly: " << avgMonthly(data) << '\n';
    std::vector<std::vector<int>> v = maxDay(data);
    std::cout << "Days with most pluviosity: ";
    for (const auto & i : v) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << ", ";
    }
    std::cout << '\n';
    std::vector<std::vector<int>> aboveAvgDays = aboveAvg(data, numDays);
    std::cout << "Days above average: ";
    for (const auto & i : aboveAvgDays) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << ", ";
    }
    std::cout << '\n';
}

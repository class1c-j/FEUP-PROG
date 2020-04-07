// Ex 4.4

#include <iostream>
#include <vector>

/*
 
   a) "Binary search" is an algorithm that can be used to search for a value in a sorted array/vector by
   repeatedly dividing the search interval in half until the value is found. In pseudocode, for searching a value
   in an array/vector sorted in ascending order, it can be described as follows:
       -assign the index of the first element of the array/vector to first;
       -assign the index of the last element of the array/vector to last;
       -make variable found equal to false;
       -repeat until found is true or first is greater than last:
            -make middle equal to index of the middle position between first and last;
            -if the value of the array/vector in middle position is equal to the searched value, make found equal to true
            otherwise, if the searched value is lower than the value of the array/vector in middle position
                -make last equal to middle - 1;
            otherwise
                -make first equal to middle + 1.
    Write  a  function  whose  prototype is int binarySearch(const vector<int> &v, int value) that applies this search
    algorithm to a vector v. The function must return the index of the element whose value is value if it exists in v
    or -1, if it does not exist.
    
*/

int binarySearch(const std::vector<int> &v, int value) {
    int first = 0;
    int last = (int) v.size() - 1;
    do {
        int middle = (first + last) / 2;
        if (v.at(middle) == value) {
            return middle;
        } else if (value < v.at(middle)) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    } while (first <= last);
    return -1;
}

/*

   b) Write a program for testing the binarySearch() function.

*/

void readVector(std::vector<int> &v, size_t nElem) {
    for (int i = 0; i < nElem; i ++) {
        int temp;
        std::cout << "Value at index " << i << ": ";
        std::cin >> temp;
        v.push_back(temp);
    }
}

void bubbleSort(std::vector<int> &v) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < v.size(); i++) {
            if (v.at(i - 1) > v.at(i)) {
                int temp = v.at(i);
                v.at(i) = v.at(i-1);
                v.at(i-1) = temp;
                swapped = true;
            }
        }
    }
}

void testA() {
    int value;
    const int SIZE_VECTOR = 5;
    std::cout << "Insert value to search: "; std::cin >> value;
    std::vector<int> vec;
    readVector(vec, SIZE_VECTOR);
    bubbleSort(vec);
    std::cout << binarySearch(vec, value) << '\n';
}




int main() {
    testA();
}

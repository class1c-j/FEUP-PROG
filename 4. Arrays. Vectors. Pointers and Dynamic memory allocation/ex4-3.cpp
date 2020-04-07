#include <iostream>
#include <vector>

/*

 a) The bubble sort method, for sorting the elements of a vector with N elements, consists of the following:
     - scan the vector, starting at the 1st element (index=0), comparing the elements of indexes i and i + 1
 of the vector, and changing their position if they are out of order; after this step, the largest (or smallest,
 depending on whether the sorting is done in ascending or descending order) will be in the correct position
 (the last position of the vector);
     - repeat the previous  step, considering in each iteration only the elements not yet in the correct position;
 note that, after the 2nd iteration the last 2 elements will be in the correct position, after the 3rd iteration the
 last 3 elements will be in the correct position, and so on.

 Write a function void bubbleSort(vector<int> &v) that implements this sorting method to sort a vector of integer
 values in ascending order.
 
*/

void bubbleSort(std::vector<int> &v) {
    int toCheck = v.size();
    while(toCheck > 0) {
        for (int i = 1; i < toCheck; i ++) {
            if (v.at(i - 1) > v.at(i)) {
                int temp = v.at(i);
                v.at(i) = v.at(i - 1);
                v.at(i - 1) = temp;
            }
        }
        toCheck --;
    }
}

/*

  b) Write a program for testing the bubbleSort()function
  
*/

void readVector(std::vector<int> &v) {
    int temp;
    int i = 0;
    std::cout << "Insert value at index " << i << ": ";
    while (std::cin >> temp) {
        i++;
        std::cout << "Insert value at index " << i << ": ";
        v.push_back(temp);
    }
    std::cout << '\n';
}

void testA() {
    std::vector<int> vec;
    readVector(vec);
    bubbleSort(vec);
    for (int i : vec) {
        std::cout << vec.at(i) << '\t';
    }
}

/*
 
  c) Improve the function developed in 4.3.a, in order to optimize the implementation, by stopping the algorithm when
  no swap is done during a scan of all the elements, which means that the elements are sorted.
  
*/

void bubbleSortMod1(std::vector<int> &v) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < v.size(); i++) {
            if (v.at(i - 1) > v.at(i)) {
                int temp = v.at(i);
                v.at(i) = v.at(i - 1);
                v.at(i - 1) = temp;
                swapped = true;
            }
        }
    }
}

void testC() {
    std::vector<int> vec;
    readVector(vec);
    bubbleSortMod1(vec);
    for (int i : vec) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}

/*
 
   d) Improve the function developed in 4.3.a, by adding an additional parameter of type char, that allows the user of
   the function to sort the values in ascending or descending order (parameter equal to 'a' or 'd', respectively)

*/

void bubbleSortMod2(std::vector<int> &v, char order) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < v.size(); i++) {
            if (v.at(i - 1) > v.at(i) && order == 'a' || v.at(i - 1) < v.at(i) && order == 'd') {
                int temp = v.at(i);
                v.at(i) = v.at(i - 1);
                v.at(i - 1) = temp;
                swapped = true;
            }
        }
    }
}

void testD() {
    char order;
    std::vector<int> vec;
    std::cout << "Order: "; std::cin >> order;
    readVector(vec);
    bubbleSortMod2(vec, order);
    for (int i : vec) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}

/*
  
   e) Modify the  function  developed in 4.3.a, so that the additional parameter is a function bool f(int x, int y) that determines
   the sorting order (ascending or descending): void bubbleSort(vector<int> &v, bool f(int x, int y)). This new version  of
   bubbleSort() could be called in the following way: bubbleSort(v, ascending) or bubbleSort(v, descending), where ascending() 
   and descending() are the functions that determine the sorting order.
 
 */

bool ascending(int x, int y) {
    return x > y;
}

bool descending(int x, int y) {
    return x < y;
}

void bubbleSortMod3(std::vector<int> &v, bool f(int x, int y)) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < v.size(); i++) {
            if (f(v.at(i-1), v.at(i))) {
                int temp = v.at(i);
                v.at(i) = v.at(i-1);
                v.at(i-1) = temp;
                swapped = true;
            }
        }
    }
}

void testE() {
    std::vector<int> vec = {2, 6, 7, 2, 8, 2, 1, 0 -5};
    bubbleSortMod3(vec, ascending);
    for (int i : vec) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
    bubbleSortMod3(vec, descending);
    for (int i : vec) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}




int main() {
    // testA();
    // testC();
    // testD();
    // testE();
}

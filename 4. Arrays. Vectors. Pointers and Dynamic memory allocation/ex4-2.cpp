// EX 4.2

#include <iostream>
#include <vector>
#include <limits>

/*
 * a) Repeat problem 4.1, using STL vectors to store the numbers, instead of C arrays. The prototypes of
 * the functions to be developed are, in this case, the following:
 * - void readVector(vector<int> &v, size_t nElem); (Note: in this case, it is not necessaryto pre-allocate space for the values to be read)
 * - size_t findValueInVector(const vector<int> &v, intvalue, size_t pos1, size_t pos2);
 * - void findMultValuesInVector(const vector<int> &v,int value, size_t pos1, size_t pos2, vector<size_t> &index);
 */


void readVector(std::vector<int> &v, size_t nElem) {
    for (int i = 0; i < nElem; i ++) {
        int temp;
        std::cout << "Value at index " << i << ": ";
        std::cin >> temp;
        v.push_back(temp);
    }
}

size_t findValueInVector(const std::vector<int> &v, int value, size_t pos1, size_t pos2) {
    for (int i = pos1; i <= pos2; i ++) {
        if (v.at(i) == value) {
            return i;
        }
    }
    return -1;
}

void findMultValuesInVector(const std::vector<int> &v, int value, size_t pos1, size_t pos2, std::vector<size_t> &index) {
    for (int i = pos1; i <= pos2; i ++) {
        if (v.at(i) == value) {
            index.push_back(i);
        }
    }
}

void testA() {
    size_t nElem, pos1, pos2;
    std::vector<int> v;
    std::vector<size_t> index;
    int value;
    std::cout << "How many elements to read? "; std::cin >> nElem;
    readVector(v, nElem);
    std::cout << "Value to search: "; std::cin >> value;
    std::cout << "Begin: "; std::cin >> pos1; std::cout << "End: "; std::cin >> pos2;
    std::cout << findValueInVector(v, value, pos1, pos2) << std::endl;
    findMultValuesInVector(v, value, pos1, pos2, index);
    for (size_t i : index) {
        std::cout << i << '\t';
    }
}

/*
  Modify function readVector() so that the number of elements to be read does not need to be specified as a function parameter; reading
  must end when the user closes the standard input stream, by typing CTRL-Z(in  Windows) or CTRL-D (in Linux).
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
}

void testB() {
    std::vector<int> v;
    readVector(v);
    std::cout << std::endl;
    for (int i : v) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
}

/*
  Alternative prototypes of functions readVector() and findMultValuesInVector() could have been used, so that both return 
  the resulting vectors, instead of void. Implement these functions and modify the developed code in order to use the new
  functions. Do you find any advantage/disadvantage of using these new versions? Would it be possible to modify the 
  function readArray() in problem 4.1.a so that it returns an array?
 */

// It can have a disadvantage in performance because it would require copying the vector
// And no, it would not be possible to do that on 4.1

std::vector<size_t> findMultValuesInVector(const std::vector<int> &v, int value, size_t pos1, size_t pos2) {
    std::vector<size_t> index;
    for (int i = pos1; i <= pos2; i ++) {
        if (v.at(i) == value) {
            index.push_back(i);
        }
    }
    return index;
}

std::vector<int> readVector() {
    std::vector<int> v;
    int temp;
    int i = 0;
    std::cout << "Insert value at index " << i << ": ";
    while (std::cin >> temp) {
        i++;
        std::cout << "Insert value at index " << i << ": ";
        v.push_back(temp);
    }
    if (std::cin.fail()) {
        if (std::cin.eof()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << "Ended reading" << std::endl;
        }
    }
    return v;
}

void testC() {
    int value = 3;
    std::vector<int> v = readVector();
    size_t pos1 = 0, pos2 = v.size() - 1;
    std::vector<size_t> index = findMultValuesInVector(v, value, pos1, pos2);
    for (size_t i : index) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
}


int main() {
    // testA();
    // testB();
    // testC();
}

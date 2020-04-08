#include <iostream>
#include <vector>


/*

   a) Write two functions whose prototypes are
   void vectorUnion(const vector<int> &v1, const vector<int> &v2, vector<int> &v3);
   void vectorIntersection(const vector<int> &v1, const vector<int> &v2, vector<int> &v3);
   that do, respectively, the union and the intersection of the elements of vectors v1 and v2, returning
   the result through vector v3. The resulting vector  must not have repeated elements and these must
   be sorted in ascending order. Suggestion: use the functions bubbleSort() and removeDuplicates() from the previous problems. 
 
*/ 


void removeDuplicates(std::vector<int> &v) {
    for (int i = 0; i < v.size(); i ++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v.at(i) == v.at(j)) {
                for (int k = j + 1; k < v.size(); k ++) {
                    v.at(k - 1) = v.at(k);
                }
                v.resize(v.size() - 1);
                j --;
            }
        }
    }
}

void bubbleSort(std::vector<int> &v) {
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

void vectorUnion(const std::vector<int> &v1, const std::vector<int> &v2, std::vector<int> &v3) {
    for (int i : v1) {
        v3.push_back(i);
    }
    for (int i : v2) {
        v3.push_back(i);
    }
    removeDuplicates(v3);
    bubbleSort(v3);
}

void vectorIntersection(const std::vector<int> &v1, const std::vector<int> &v2, std::vector<int> &v3) {
    for (int i : v1) {
        for (int j : v2) {
            if (i == j) {
                v3.push_back(i);
            }
        }
    }
    removeDuplicates(v3);
    bubbleSort(v3);
}



/*
 
   b) Write a program for testing the vectorUnion() and the vectorIntersection() functions.

*/


void testA() {
    std::vector<int> v1 = {20, 1, 5, 10, 10, 50, 10};
    std::vector<int> v2 = {50, 20, 3, 15, 50};
    std::vector<int> v3 = {};
    vectorUnion(v1, v2, v3);
    for (int l : v3) {
        std::cout << l << " ";
    }
    std::cout << std::endl;
    v3 = {};
    vectorIntersection(v1, v2, v3);
    for (int l : v3) {
        std::cout << l << " ";
    }
    std::cout << std::endl;
}





int main() {
    testA();
}

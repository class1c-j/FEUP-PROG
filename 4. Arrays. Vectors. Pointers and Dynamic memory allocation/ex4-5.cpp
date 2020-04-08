//EX 4.5

#include <iostream>
#include <vector>

/*

   a) Write a void function void removeDuplicates(vector<int> &v) that eliminates the repeated elements of
   vector v. The original ordering of the vector elements must be maintained. Suggestion: the elimination of an
   element can be done "in-place" (that is, without using an auxiliary vector) by moving all the elements that occupy
   the next positions of the vector to the position before the position they occupy and changing the size of the vector,
   using the resize() method of the vector class, to decrease the size of the vector.
   Note: there are member functions of the STL vector class that can be used to do this task; these functions will be studied later.
   
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

/*
  
   b) Write a program for testing the removeDuplicates() function.
   
*/

void testA() {
    std::vector<int> v = {20, 1, 5, 10, 10, 50, 10};
    removeDuplicates(v);
    for (int l : v) {
        std::cout << l << " ";
    }
    std::cout << std::endl;
}





int main() {
    testA();
}



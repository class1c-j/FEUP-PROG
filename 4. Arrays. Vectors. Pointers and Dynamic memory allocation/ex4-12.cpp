#include <iostream>
#include <new>


/*
 
   a) Redo problem 4.1 so that the space for the array is allocated dynamically, after asking the user for the
   effective number of the elements to be read and before calling the function readArray(). In findMultValuesInArray(),
   the space for the resulting array must also be allocated dynamically. The new prototype of the functions must be:
   -void readArray(int *a,size_tnElem)
   -intfindValueInArray(const int *a, size_tnElem, intvalue, size_tpos1, size_tpos2)
   -size_t findMultValuesInArray(const int *a, size_tnElem, int value, size_tpos1, size_tpos2, size_t*index)
   
*/

void readArray(int *a, size_t nElem) {
    for (int i = 0; i < nElem; i ++) {
        int temp;
        std::cout << "Insert value for index " << i << ": ";
        std::cin >> temp;
        a[i] = temp;
    }
}

int findValueInArray(const int *a, size_t nElem, int value, size_t pos1, size_t pos2) {
    for (int i = pos1; i <= pos2; i ++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

size_t findMultValuesInArray(const int *a, size_t nElem, int value, size_t pos1, size_t pos2, size_t *index) {
    if (pos2 == -1) {
        pos2 = nElem;
    }

    size_t count = 0;
    for (int i = pos1; i <= pos2; i ++) {
        if (a[i] == value) {
            index[count] = i;
            count ++;
        }
    }
    return count;
}

void testA() {
    int nMax;
    int *a;
    int value;
    size_t pos1, pos2;
    size_t *index;
    std::cout << "nMax? "; std::cin >> nMax;
    a = new int[nMax];
    index = new size_t[nMax];
    readArray(a, nMax);
    std::cout << "Value to search: "; std::cin >> value;
    std::cout << "Begin: "; std::cin >> pos1;
    std::cout << "End: "; std::cin >> pos2;
    std::cout << "First occurrence: " << findValueInArray(a, nMax, value, pos1, pos2) << std::endl;
    std::cout << "Number of occurrences: " << findMultValuesInArray(a, nMax, value, pos1, pos2, index) << std::endl;
    std::cout << "Indexes of occurrences: ";
    for (int i = 0; i < findMultValuesInArray(a, nMax, value, pos1, pos2, index); i ++) {
        std::cout << index[i] << " ";
    }
    std::cout << std::endl;
}

/*
 
   b) Modify the solutions of 4.12.a so that findValueInArray() and findMultValuesInArray() have the following prototypes:
   -intfindValueInArray(const int *pos1, const int *pos2, intvalue)
   -size_t findMultValuesInArray(const int *pos1, const int *pos2, int value, size_t*index)
   where pos1 and pos2 are pointers to elements of the array.
   
 */


int findValueInArray(const int *pos1, const int *pos2, int value) {
    int i = 0;
    while (pos1 <= pos2) {
        if (*pos1 == value) {
            return i;
        }
        pos1 ++;
        i ++;
    }
    return -1;
}

size_t findMultValuesInArray(const int *pos1, const int *pos2, int value, size_t *index) {
    int count = 0;
    int idx = 0;
    while (pos1 <= pos2) {
        if (*pos1 == value) {
            index[count] = idx;
            count ++;
        }
        idx ++;
        pos1 ++;
    }
    return count;
}

void testB() {
    int nMax;
    int pos1, pos2, value;
    std::cout << "Insert max number: "; std::cin >> nMax;
    int *a = new int[nMax];
    size_t *index = new size_t[nMax];
    readArray(a, nMax);
    std::cout << "Value to search for: "; std::cin >> value;
    std::cout << "Begin: "; std::cin >> pos1;
    std::cout << "End: "; std::cin >> pos2;
    int *ptr1 = &a[pos1];
    int *ptr2 = &a[pos2];
    std::cout << findValueInArray(ptr1, ptr2, value) << std::endl;
    size_t occurrences = findMultValuesInArray(ptr1, ptr2, value, index);
    for (int i = 0; i < occurrences; i ++) {
        std::cout << index[i] << " ";
    }
    std::cout << std::endl;
}





int main(){
    testA();
    testB();
} 

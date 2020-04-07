// EX 4.1

/*
  a) Write a function, whose prototype is void readArray(int a[], size_t nElem), which reads from the keyboard
  the elements of an array of integers, a[]; the number of elements to be read is nElem. The space for the
  array must be allocated statically, before calling the function. Before reading each element of the array, the
  respective index must be displayed on the screen.
 */


void readArray(int a[], size_t nElem) {
    for (int i = 0; i < nElem; i ++) {
        int temp;
        std::cout << "Reading element for index " << i << ": ";
        std::cin >> temp;
        a[i] = temp;
    }
}

/*
  b) Write a function, whose prototype is int findValueInArray(const int a[], size_t nElem, int value, size_t pos1,
  size_t pos2) which searches the nElem elements of the array, between indexes (positions) pos1 and pos2, inclusive,
  for the first occurrence of value. If value is found, the function must return the index (position) of the
  corresponding element of the array; otherwise it must return -1.
 */

int findValueInArray(const int a[], int value, size_t pos1, size_t pos2) {
    for (int i = pos1; i <= pos2; i ++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

/*
  c) Write a program for testing the functionsreadArray() and findValueInArray().
 */

#include <iostream>

void test1() {
    const int SIZE_ARRAY = 256;  // change to allocate a different amount of space
    int a[SIZE_ARRAY];  // allocates the space for the array
    size_t nElem, pos1, pos2;
    int value;

    std::cout << "Insert the number of elements to read (must be lower than " << SIZE_ARRAY/sizeof(int) << "): ";
    std::cin >> nElem;
    readArray(a, nElem);

    std::cout << "Value to search: ";
    std::cin >> value;
    std::cout << "Pos 1: "; std::cin >> pos1;
    std::cout << "Pos 2: "; std::cin >> pos2;
    std::cout << findValueInArray(a, value, pos1, pos2) << std::endl;
}


/*
   d) In C++, it would be possible to specify default values for the parameters pos1and pos2 so that all the elements
      of the array are searched when pos1 and pos2 are not   
      specified as arguments of the call. How would you modify the prototype of findValueInArray() to do this? 
 */

int findValueInArray(const int a[], int value, size_t nElem, size_t pos1 = 0, size_t pos2 = -1);

/*
    e) Modify the function findValueInArray() to obtain a new function size_t findMultValuesInArray(const  int  a[],size_tnElem,
    int value, size_tpos1, size_tpos2, size_tindex[]) that, if  there are multiple occurrences of value in a[], returns the indexes
    of those occurrences through parameter index[]. The value returned by the function must be the number of occurrences, 
    that is, the number of valid elements of index[]. In C language, is it be possible that the name of this function is also
    findValueInArray, like the previous function? And in C++language?
*/

// it is possible in C++ and impossible in C

size_t findValueInArray(const int a[], int value, size_t nElem,size_t pos1, size_t pos2, size_t index[]) {
    
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

/*
  Change the program developed in exercise 4.1.c) in order to use the function findMultValuesInArray(). Note: the space for array
  index[] must be allocated before calling the function  findMultValuesInArray(), taking into account the expected maximum number
  of occurrences (in the limit, it must have nElem elements).
*/

void test2() {
    const int SIZE_ARRAY = 256;  // change to allocate a different amount of space
    int a[SIZE_ARRAY];  // allocates the space for the array
    size_t nElem, pos1, pos2;
    int value;

    std::cout << "Insert the number of elements to read (must be lower than " << SIZE_ARRAY/sizeof(int) << "): ";
    std::cin >> nElem;
    readArray(a, nElem);

    size_t index[nElem];
    std::cout << "Value to search: ";
    std::cin >> value;
    for (int i = 0; i < findValueInArray(a, value, nElem, 0, -1, index); i ++) {
        std::cout << index[i] << '\t';
    }
}

int main() {
    test1();
    test2();
}

#include <iostream>


/*
   
   Standard C library provides qsort() function that can be used for sorting an array. This function uses quicksort
   algorithm (https://en.wikipedia.org/wiki/Quicksort) to sort the given array. Theprototype of qsort() is
   void qsort (void* base, size_t num, size_t size,  int (*comparator)(const void*,const void*)). The meaning of the
   parameters is:
   
   base − pointer to the first element of the array to be sorted;
   num − number of elements in the array pointed by base;
   size − size in bytes of each element in the array;
   comparator − function that compares two elements;
   this function must return:
   
        < 0 when the element pointed by the 1st parameter goes before the element pointed by the 2nd parameter
        0 when the element pointed by the 1st parameter is equivalent to the element pointed by the 2nd parameter
        >0 when the element pointed by the 1st parameter goes after the element pointed by the 2nd parameter.
        
   Write a program that uses this function to:
   
   a) Sort all the elements of an array in ascending order.
   b) Sort all the elements of an array in descending order.
   c) Sort the elemente in the first half and in the second half of the array, independently, in ascending order.
   
 */

int ascendCompare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

int descendCompare(const void* a, const void* b) {
    return -(*(int*) a - *(int*) b);
}

void testA() {
    const int ARR_SIZE = 10;
    size_t nElem = 10;
    int a[ARR_SIZE] = {4, 6, 8, 2, 1, 1, 0, 6, 7, 3};
    qsort(a, nElem, sizeof(int), ascendCompare);
    for (int i = 0; i < nElem; i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << '\n';
}

void testB() {
    const int ARR_SIZE = 10;
    size_t nElem = 10;
    int a[ARR_SIZE] = {4, 6, 8, 2, 1, 1, 0, 6, 7, 3};
    qsort(a, nElem, sizeof(int), descendCompare);
    for (int i = 0; i < nElem; i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << '\n';
}

void testC() {
    const int ARR_SIZE = 10;
    size_t nElem = 10;
    int a[ARR_SIZE] = {4, 6, 8, 2, 1, 1, 0, 6, 7, 3};
    int *firstHalf = a;
    int *secondHalf = a + (nElem / 2);
    qsort(firstHalf, nElem, sizeof(int), ascendCompare);
    qsort(secondHalf, nElem/2, sizeof(int), ascendCompare);
    for (int i = 0; i < nElem; i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    testA();
    testB();
    testC();
}

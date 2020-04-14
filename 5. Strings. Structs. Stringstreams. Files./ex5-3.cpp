/*

    Redo  problem 5.1 using an array of C strings to store the names and the
    library function qsort() to sort the names. Tip: adapt the code from
    problem 4.11. Note: in order to use the library function qsort() the space
    allocated for each name must be the same (for example, 100 bytes), although
    the effective length of the names may be different.

*/

#include <iostream>
#include <cstring>

int compare(const void *a, const void *b) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;
    return strcmp(pa, pb);
}

int main() {
    const char *arr[] = {"egas", "becas", "sonso", "mafarrico"};
    qsort(arr, sizeof(arr)/sizeof(const char *), sizeof(const char *), compare);
    for (auto & i : arr) {
        std::cout << i << std::endl;
    }
    return 0;
}



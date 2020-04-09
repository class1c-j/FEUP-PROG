#include <iostream>
#include <vector>

const int NE = 5;

/*
 
   a) An element of a matrix is said to be a local maximum if its value is
   greater than the value of all its neighbors. Write a function whose prototype
   is void localMax(const int a[][NE])that displays on the screen the position (row  and column)
   and value of all the local maxima of a 2D matrix with NExNE of elements of
   type int, considering that only the elements of the matrix that have 8 neighbors can
   be considered local maxima. Using this rule in the example below, only the elements
   colored in red would be considered local maxima. Note: since NE must be a global constant,
   and the number of lines is equal to the number of columns, it is not necessary to pass the number
   of lines and columns as parameters
   
*/ 


void localMax(const int a[][NE]) {
    std::vector<std::vector<int>> results;
    for (int i = 0; i < NE; i ++) {
        for (int j = 0; j < NE; j ++) {
            std::vector<int> coords = {};
            if (i - 1 >= 0 && i + 1 < NE && j - 1 >= 0 && j + 1 < NE) {
                int c = a[i][j];
                if (c > a[i][j-1] && c > a[i][j+1] && c > a[i-1][j] && c > a[i+1][j] && c > a[i-1][j-1]
                && c > a[i-1][j+1] && c > a[i+1][j-1] && c > a[i+1][j+1]) {
                    coords.push_back(i);
                    coords.push_back(j);
                    results.push_back(coords);
                }
            }
        }
    }
    for (const auto& i : results) {
        for (int j : i ) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


/* 
 
   b) Write a test program for the function developed, using the matrix above as an argument to the call.
   Suggestion: to avoid reading the elements of the matrix from the keyboard, on every run, use a declaration
   with initialization of the 2D matrix, in main().

*/

void testA() {
    const int a[][NE] = {{7, 3, 4, 1, 3}, {2, 9, 6, 2, 1}, {1, 3, 5, 1, 4}, {6, 5, 2, 7, 5}, {4, 2, 1, 3, 6}};
    localMax(a);
}


/*
 
   c) Rewrite the code of localMax() and of the test program with the following modifications:
   - use a 2D vector (from STL), instead of a 2D array;
   - use an additional parameter, in localMax(), to let the user decide if he wants to consider that any element of
   the matrix can be a local maximum, regardless of the number of neighbors it has;
   in this case, the elements colored in magenta, in the example, would also be considered local maxima

*/


void localMax(const std::vector<std::vector<int>> &a, bool neigh8) {
    std::vector<std::vector<int>> results;
    if (neigh8) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                std::vector<int> coords = {};
                if (i - 1 >= 0 && i + 1 < a.size() && j - 1 >= 0 && j + 1 < a.size()) {
                    int c = a[i][j];
                    if (c > a[i][j - 1] && c > a[i][j + 1] && c > a[i - 1][j] && c > a[i + 1][j] && c > a[i - 1][j - 1]
                        && c > a[i - 1][j + 1] && c > a[i + 1][j - 1] && c > a[i + 1][j + 1]) {
                        coords.push_back(i);
                        coords.push_back(j);
                        results.push_back(coords);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < NE; i ++) {
            for (int j = 0; j < NE; j++) {
                int c = a[i][j];
                bool isMax = true;
                std::vector<int> coords = {};
                for (int sideX = -1; sideX < 2; sideX ++) {
                    for (int sideY = -1; sideY < 2; sideY ++) {
                        if (i + sideX >= 0 && i + sideX < a.size() && j + sideY >= 0 && j + sideY < a.size()
                        && a[sideX+i][sideY+j] > c) {
                            isMax = false;
                            break;
                        }
                    }
                }
                if (isMax) {
                    coords.push_back(i);
                    coords.push_back(j);
                    results.push_back(coords);
                }
            }
        }
    }
    for (const auto &i : results) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void testB() {
    bool neigh8 = false;
    std::vector<std::vector<int>> a = {{7, 3, 4, 1, 3},
                                       {2, 9, 6, 2, 1},
                                       {1, 3, 5, 1, 4},
                                       {6, 5, 2, 7, 5},
                                       {4, 2, 1, 3, 6}};
    localMax(a, neigh8);
}



int main() {
    testA();
    testB();
}


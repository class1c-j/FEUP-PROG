#include <string>
#include <vector>
#include <iostream>
 
 /*
  
   a) Write a function void bubbleSort(vector<string> &v, char order) that implements the bubblesort method to
   sort a vector of C++ strings, in lexicographic (ascending) order or in reverse lexicographic (descending) order,
   depending on the value of parameter order being 'a'or 'd'. Tip: adapt the code from problem 4.3.d
   
  */
 
void bubbleSort(std::vector<std::string> &v, char order) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < v.size(); i ++) {
            if (v.at(i - 1) > v.at(i) && order == 'a'
            || v.at(i - 1) < v.at(i) && order == 'd') {
                std::string temp = v.at(i);
                v.at(i) = v.at(i - 1);
                v.at(i - 1) = temp;
                swapped = true;
            }
        }
    }
}

void testA() {
    char order;
    std::vector<std::string> v = {"Não estás nada", "Estou a vê-lo", "au", "Para de me bater"};
    std::cout << "Ascending (a) or Descending (d) ? ";
    std::cin >> order;
    bubbleSort(v, order);
    for (const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/*
 
   b) Write a program that reads, from standard input, a list of person names (each name having more than one word),
   stores them into a vector<string>, and sorts them using the bubbleSort() function.
   
*/

void testB() {
    std::vector<std::string> names;
    std::string temp;
    char order; std::cout << "Ascending (a) or Descending (d) ? "; order = std::getchar();
    std::cout << "Insert names\n";
    while (!std::cin.fail()) {
        std::getline(std::cin, temp);
        if (std::cin.fail()) {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                break;
            }
        } else {
            names.push_back(temp);
        }
    }
    bubbleSort(names, order);
    for (const auto &i : names) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}




int main() {
    testA();
    testB();
}

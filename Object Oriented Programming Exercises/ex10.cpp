/*

   Repeat the previous problem using an STL list to store the words read from the file.
   In this case it not possible to use the STL algorithms sort() and unique()? Why?
   Investigate the use of alternative solutions.

   The STL algorithms mentioned do not work with lists because they require the use of random access iterators,
   which lists do not have. Therefore, some of those algorithms have been adapted and optimized for lists and been
   implemented as member functions - ex list.sort() and list.unique()

*/

#include <list>
#include <fstream>
#include <string>
#include <iostream>

void readWords(std::ifstream &fs, std::list<std::string> &wordList) {
    std::string temp{};
    auto it = wordList.begin();
    while (std::getline(fs, temp)) {
        wordList.insert(it, temp);
        it ++;
    }
}

void sortWords(std::list<std::string> &wordList) {
    wordList.sort();
}

void removeDuplicates(std::list<std::string> &wordList) {
    wordList.unique();
}

void writeFile(std::ofstream &fs, const std::list<std::string> &wordList) {
    for (const auto &i : wordList) {
        fs << i << '\n';
    }
}

int main() {
    std::list<std::string> lst{};
    std::ifstream ifs("words.txt");
    readWords(ifs, lst);
    sortWords(lst);
    removeDuplicates(lst);
    std::ofstream ofs("words.txt");
    writeFile(ofs, lst);
    return 0;
} 

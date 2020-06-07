#include <vector>
#include <string>
#include <fstream>
#include <iostream>


/*

   Write a program to eliminate duplicates in a set of unordered words, stored in a text file. The values must be read
   into an STL vector. The ordered set of words must be written to the same text file. Use STL algorithm sort() to sort
   the words; to eliminate duplicates, implement two versions of the program:

   a) Using your own code to remove the duplicates

*/

std::vector<std::string> readWords(std::fstream &file) {
    std::vector<std::string> words{};
    std::string temp{};
    while (getline(file, temp, '\n')) {
        words.push_back(temp);
    }
    return words;
}

void sortWords(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
}

void removeDuplicates(std::vector<std::string> &words) {
    auto end = words.end();
    for (auto it = words.begin(); it != end; it ++) {
        end = std::remove(it + 1, end, *it);
    }
    words.erase(end, words.end());
}

void writeFile(std::ofstream &file, const std::vector<std::string> &words) {
    for (const auto &i : words) {
        file << i << "\n";
    }
}

void testA() {
    std::fstream f("words.txt");
    std::vector<std::string> words = readWords(f);
    sortWords(words);
    removeDuplicates(words);
    std::ofstream of("words.txt");
    writeFile(of, words);
}

/*

   .b) Using STL algorithm unique() to remove the duplicates.

*/

void removeDuplicatesMod(std::vector<std::string> &words) {
    words.erase(std::unique(words.begin(), words.end()), words.end());
}

void testB() {
    std::fstream f("words.txt");
    std::vector<std::string> words = readWords(f);
    sortWords(words);
    removeDuplicatesMod(words);
    std::ofstream of("words.txt");
    writeFile(of, words);
}

int main() {
    //testB();
    return 0;
} 
